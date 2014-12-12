#ifndef MIDISIGNAL_H_
#define MIDISIGNAL_H_

#define NOTEOFF 0x80
#define NOTEON 0x90
#define AFTERTOUCH 0xA0
#define CONTIUOUSCONTROLLER 0xB0

#include <string>
#include <iostream>

struct MidiSignal
{
	MidiSignal():	channel_(0), 
					command_ (NOTEOFF),
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
				<< "\n     param1_ = "<< std::hex << param1_
				<< "\n     param2_ = "<< std::hex << param2_ << std::endl;
	}
};

#endif /* MIDISIGNAL_H_ */