#ifndef MIDISIGNAL_H_
#define MIDISIGNAL_H_

#define NOTEOFF 0x8
#define NOTEON 0x9
#define AFTERTOUCH 0xA
#define CONTROLCHANGE 0xB

#include <string>
#include <iostream>

struct MidiSignal
{
	MidiSignal():	channel_(1), 
					command_ (8),
					param1_(0),
					param2_(0)
	{}

	/** ATRIBUTES USED FOR ALSA **/
	int channel_;
	int command_;
	int param1_;
	int param2_;

	void print()
	{
		std::cout<<  "     channel_ = " << std::hex << channel_
				<< "\n     command_ = " << std::hex << command_
				<< "\n     param1_ = "<< std::dec << param1_
				<< "\n     param2_ = "<< std::dec << param2_ << std::endl;
	}
};

#endif /* MIDISIGNAL_H_ */