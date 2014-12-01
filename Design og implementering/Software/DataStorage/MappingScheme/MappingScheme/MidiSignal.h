#ifndef MIDISIGNAL_H_
#define MIDISIGNAL_H_

#define NOTEOFF '8'
#define NOTEON '9'
#define AFTERTOUCH 'A'
#define CONTIUOUSCONTROLLER 'B'

#include <string>
#include <iostream>

using namespace std;

struct MidiSignal
{
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
		cout<<   "     channel_ = " << hex << channel_
			<< "\n     command_ = " << hex << command_
			<< "\n     param1_ = "<< dec << param1_
			<< "\n     param2_ = "<< dec << param2_ << endl;
	}
};

#endif /* MIDISIGNAL_H_ */