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
		union {
			NoteOnMessage noteOn;
			NoteOffMessage noteOff;
			ParameterChangeMessage parameterChange;
		};

		Message(MessageType type_, Time time_) :
			type(type_),
			time(time_)
		{
		}

		static Message createNoteOn(Time time, unsigned int number) {
			Message message(MessageType::NOTE_ON, time);
			message.noteOn = NoteOnMessage::create(number);
			return message;
		}

		static Message createNoteOff(Time time, unsigned int number) {
			Message message(MessageType::NOTE_OFF, time);
			message.noteOff = NoteOffMessage::create(number);
			return message;
		}
		static Message createParameterChange(Time time) {
			Message message(MessageType::PARAMETER_CHANGE, time);
			message.parameterChange = ParameterChangeMessage::create();
			return message;
		}
	};
}

#endif  // MESSAGE_H_INCLUDED
