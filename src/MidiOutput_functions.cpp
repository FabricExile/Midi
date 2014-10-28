/*
 *  Copyright 2010-2014 Fabric Software Inc. All rights reserved.
 */

#include "extension.h"
#include "MidiOutput_functions.h"

using namespace Fabric::EDK;

// Defined at src\MidiOutput.kl:24:1
FABRIC_EXT_EXPORT void MidiOutput_construct(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::MidiOutput >::IOParam this_
) {
  try
  {
    this_->handle = new RtMidiOut();
  }
  catch (RtMidiError &error)
  {
    setError(error.getMessage().c_str());
  }
}

// Defined at src\MidiOutput.kl:27:1
FABRIC_EXT_EXPORT void MidiOutput_destruct(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::MidiOutput >::IOParam this_
) {
  RtMidiOut* midi = (RtMidiOut*)this_->handle;
  if(midi)
  {
    delete(midi);
    this_->handle = NULL;
  }
}

// Defined at src\MidiOutput.kl:35:1
FABRIC_EXT_EXPORT void MidiOutput_openPort(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::MidiOutput >::IOParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::UInt32 >::INParam portNumber,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::String >::INParam portName
) {
  RtMidiOut* midi = (RtMidiOut*)this_->handle;
  if(!midi)
    return;
  try
  {
    midi->openPort(portNumber, portName.data());
  }
  catch (RtMidiError &error)
  {
    setError(error.getMessage().c_str());
  }
}

// Defined at src\MidiOutput.kl:55:1
FABRIC_EXT_EXPORT void MidiOutput_openVirtualPort(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::MidiOutput >::IOParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::String >::INParam portName
) {
  RtMidiOut* midi = (RtMidiOut*)this_->handle;
  if(!midi)
    return;
  try
  {
    midi->openVirtualPort(portName.data());
  }
  catch (RtMidiError &error)
  {
    setError(error.getMessage().c_str());
  }
}

// Defined at src\MidiOutput.kl:62:1
FABRIC_EXT_EXPORT void MidiOutput_closePort(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::MidiOutput >::IOParam this_
) {
  RtMidiOut* midi = (RtMidiOut*)this_->handle;
  if(!midi)
    return;
  try
  {
    midi->closePort();
  }
  catch (RtMidiError &error)
  {
    setError(error.getMessage().c_str());
  }
}

// Defined at src\MidiOutput.kl:65:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean MidiOutput_isPortOpen(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::MidiOutput >::INParam this_
) {
  RtMidiOut* midi = (RtMidiOut*)this_->handle;
  if(!midi)
    return false;
  try
  {
    return midi->isPortOpen();
  }
  catch (RtMidiError &error)
  {
    setError(error.getMessage().c_str());
  }
  return false;
}

// Defined at src\MidiOutput.kl:71:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::UInt32 MidiOutput_getPortCount(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::MidiOutput >::INParam this_
) {
  RtMidiOut* midi = (RtMidiOut*)this_->handle;
  if(!midi)
    return 0;
  try
  {
    return midi->getPortCount();
  }
  catch (RtMidiError &error)
  {
    setError(error.getMessage().c_str());
  }
  return 0;
}

// Defined at src\MidiOutput.kl:78:1
FABRIC_EXT_EXPORT void MidiOutput_getPortName(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::String >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::MidiOutput >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::UInt32 >::INParam portNumber
) {
  RtMidiOut* midi = (RtMidiOut*)this_->handle;
  if(!midi)
    return;
  try
  {
    _result = midi->getPortName(portNumber).c_str();
  }
  catch (RtMidiError &error)
  {
    setError(error.getMessage().c_str());
  }
}

// Defined at src\MidiOutput.kl:106:1
FABRIC_EXT_EXPORT void MidiOutput_sendMessage(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::MidiOutput >::IOParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::VariableArray< Fabric::EDK::KL::UInt8 > >::INParam message
) {
  RtMidiOut* midi = (RtMidiOut*)this_->handle;
  if(!midi)
    return;
  try
  {
    std::vector<unsigned char> message_(message.size());
    memcpy(&message_[0], &message[0], message.size());
    midi->sendMessage(&message_);
  }
  catch (RtMidiError &error)
  {
    setError(error.getMessage().c_str());
  }
  return;
}
