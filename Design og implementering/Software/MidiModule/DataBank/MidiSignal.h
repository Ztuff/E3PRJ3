#ifndef MIDISIGNAL_H_
#define MIDISIGNAL_H_

#define NOTEOFF '8'
#define NOTEON '9'
#define AFTERTOUCH 'A'
#define CONTIUOUSCONTROLLER 'B'

#include <string>
#include <iostream>

struct MidiSignal
{
	MidiSignal():	channel_('1'), 
					command_ ('8'),
					param1_(0),
					param2_(0),
					param1Old_(0),
					param2Old_(0)
	{}

	/** ATRIBUTES USED FOR ALSA **/
	char channel_;
	char command_;
	int param1_;
	int param2_;

	/** UTILITY ATRIBUTES **/
	int param1Old_;
	int param2Old_;

	void print()
	{
		std::cout<<  "     channel_ = " << std::hex << channel_
				<< "\n     command_ = " << std::hex << command_
				<< "\n     param1_ = "<< std::dec << param1_
				<< "\n     param2_ = "<< std::dec << param2_ << std::endl;
	}
};

#endif /* MIDISIGNAL_H_ */