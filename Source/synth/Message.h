#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED

#include "Time.h"

namespace blankenhain {
	enum class MessageType {
		NOTE_ON,
		NOTE_OFF,
		PARAMETER_CHANGE,
	};

	struct NoteOnMessage {
		unsigned int number;

		static NoteOnMessage create(unsigned int number) {
			NoteOnMessage message;
			message.number = number;
			return message;
		}
	};

	struct NoteOffMessage {
		unsigned int number;

		static NoteOffMessage create(unsigned int number) {
			NoteOffMessage message;
			message.number = number;
			return message;
		}
	};

	struct ParameterChangeMessage {
		static ParameterChangeMessage create() {
			ParameterChangeMessage message;
			return message;
		}
	};

	struct Message {
		MessageType type;
		Time time;
		unsigned int channel;
		union {
			NoteOnMessage noteOn;
			NoteOffMessage noteOff;
			ParameterChangeMessage parameterChange;
		};

		Message(MessageType type_, Time time_, unsigned int channel_) :
			type(type_),
			time(time_),
			channel(channel_)
		{
		}

		static Message createNoteOn(Time time, unsigned int number, unsigned int channel) {
			Message message(MessageType::NOTE_ON, time, channel);
			message.noteOn = NoteOnMessage::create(number);
			return message;
		}

		static Message createNoteOff(Time time, unsigned int number, unsigned int channel) {
			Message message(MessageType::NOTE_OFF, time, channel);
			message.noteOff = NoteOffMessage::create(number);
			return message;
		}
		static Message createParameterChange(Time time, unsigned int channel) {
			Message message(MessageType::PARAMETER_CHANGE, time, channel);
			message.parameterChange = ParameterChangeMessage::create();
			return message;
		}
	};
}

#endif  // MESSAGE_H_INCLUDED
