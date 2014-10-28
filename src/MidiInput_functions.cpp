/*
 *  Copyright 2010-2014 Fabric Software Inc. All rights reserved.
 */

#include "extension.h"
#include "MidiInput_functions.h"

using namespace Fabric::EDK;

// Defined at src\MidiInput.kl:24:1
FABRIC_EXT_EXPORT void MidiInput_construct(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::MidiInput >::IOParam this_
) {
  try
  {
    this_->handle = new RtMidiIn();
  }
  catch (RtMidiError &error)
  {
    setError(error.getMessage().c_str());
  }
}

// Defined at src\MidiInput.kl:27:1
FABRIC_EXT_EXPORT void MidiInput_destruct(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::MidiInput >::IOParam this_
) {
  RtMidiIn* midi = (RtMidiIn*)this_->handle;
  if(midi)
  {
    delete(midi);
    this_->handle = NULL;
  }
}

// Defined at src\MidiInput.kl:35:1
FABRIC_EXT_EXPORT void MidiInput_openPort(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::MidiInput >::IOParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::UInt32 >::INParam portNumber,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::String >::INParam portName
) {
  RtMidiIn* midi = (RtMidiIn*)this_->handle;
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

// Defined at src\MidiInput.kl:55:1
FABRIC_EXT_EXPORT void MidiInput_openVirtualPort(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::MidiInput >::IOParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::String >::INParam portName
) {
  RtMidiIn* midi = (RtMidiIn*)this_->handle;
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

// Defined at src\MidiInput.kl:62:1
FABRIC_EXT_EXPORT void MidiInput_closePort(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::MidiInput >::IOParam this_
) {
  RtMidiIn* midi = (RtMidiIn*)this_->handle;
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

// Defined at src\MidiInput.kl:65:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Boolean MidiInput_isPortOpen(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::MidiInput >::INParam this_
) {
  RtMidiIn* midi = (RtMidiIn*)this_->handle;
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

// Defined at src\MidiInput.kl:71:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::UInt32 MidiInput_getPortCount(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::MidiInput >::INParam this_
) {
  RtMidiIn* midi = (RtMidiIn*)this_->handle;
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

// Defined at src\MidiInput.kl:78:1
FABRIC_EXT_EXPORT void MidiInput_getPortName(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::String >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::MidiInput >::INParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::UInt32 >::INParam portNumber
) {
  RtMidiIn* midi = (RtMidiIn*)this_->handle;
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

// Defined at src\MidiInput.kl:92:1
FABRIC_EXT_EXPORT void MidiInput_ignoreTypes(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::MidiInput >::IOParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Boolean >::INParam midiSysex,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Boolean >::INParam midiTime,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Boolean >::INParam midiSense
) {
  RtMidiIn* midi = (RtMidiIn*)this_->handle;
  if(!midi)
    return;
  try
  {
    midi->ignoreTypes(midiSysex, midiTime, midiSense);
  }
  catch (RtMidiError &error)
  {
    setError(error.getMessage().c_str());
  }
}

// Defined at src\MidiInput.kl:106:1
FABRIC_EXT_EXPORT Fabric::EDK::KL::Float64 MidiInput_getMessage(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::MidiInput >::IOParam this_,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::VariableArray< Fabric::EDK::KL::UInt8 > >::IOParam message
) {
  RtMidiIn* midi = (RtMidiIn*)this_->handle;
  if(!midi)
    return 0.0;
  try
  {
    std::vector<unsigned char> message_;
    double stamp = midi->getMessage(&message_);
    message.resize(message_.size());
    memcpy(&message[0], &message_[0], message_.size());
    return stamp;
  }
  catch (RtMidiError &error)
  {
    setError(error.getMessage().c_str());
  }
  return 0.0;
}
