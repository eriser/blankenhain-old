#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED

enum class MessageType {
	NOTE_ON,
	NOTE_OFF,
	PARAMETER_CHANGE,
};

struct NoteOnMessage {
};

struct NoteOffMessage {
};

struct ParameterChangeMessage {
};

struct Message {
	MessageType type;
	union {
		NoteOnMessage noteOn;
		NoteOffMessage noteOff;
		ParameterChangeMessage parameterChange;
	};
};

#endif  // MESSAGE_H_INCLUDED
