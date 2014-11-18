#ifndef MIDISIGNAL_H_
#define MIDISIGNAL_H_

#define NOTEOFF 0x80
#define NOTEON 0x90
#define AFTERTOUCH 0xA0
#define CC 0xB0

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
		cout<<   "     channel_ = " << channel_
			<< "\n     command_ = 0x"<< hex << command_
			<< "\n     param1_ = "<< param1_
			<< "\n     param2_ = "<< param2_ << endl;
	}
};

#endif /* MIDISIGNAL_H_ */