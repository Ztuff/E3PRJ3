#ifndef MIDISIGNAL_H_
#define MIDISIGNAL_H_

#define NOTEOFF 0x80
#define NOTEON 0x90
#define AFTERTOUCH 0xA0
#define CONTIUOUSCONTROLLER 0xB0

#include <string>
#include <iostream>

using namespace std;

struct MidiSignal
{
	/** ATRIBUTES USED FOR ALSA **/
	int channel_;
	int command_;
	int param1_;
	int param2_;

	/** UTILITY ATRIBUTES **/
	int param1Old_;
	int param2Old_;

	void print()
	{
		cout<<   "     channel_ = " << dec << channel_
			<< "\n     command_ = 0x"<< hex << command_
			<< "\n     param1_ = "<< dec << param1_
			<< "\n     param2_ = "<< dec << param2_ << endl;
	}
};

#endif /* MIDISIGNAL_H_ */