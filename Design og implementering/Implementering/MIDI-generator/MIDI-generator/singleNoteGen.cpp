#include "singleNoteGen.h"

singleNoteGen::singleNoteGen(string root, int octave, unsigned int lowerThreshold, int dataIn ) : MIDIGen(dataIn)
{
	root_= MIDIGen::noteStringToInt(root);							//værdi fra 1 til 12
	octave_ = (octave >=-3 && octave<=8 ? octave : 0);				//værdi fra -3 til 8
	lowerThreshold_ = (lowerThreshold>127 ? 127 : lowerThreshold);	//værdi fra -3 til 8
	noteState_ = 0;

	int note= (octave_+3)*12+root_-1;								//indstilling af tone
	note_= (note>127 ? 127: note);									//frasortering af værdier over 127
	cout << "Note has number " <<note_ << "\n";		//for testing
}

void singleNoteGen::sendMIDI(int dataIn)
{
	if(dataIn != -1)
		MIDIGen::setDataIn(dataIn);

	cout << "Playing single note\n";
	if(dataIn_< lowerThreshold_)
	{
		cout << "Stop note ALSA\n";
		noteState_ = 0;
	}
	else
	{
		if(noteState_ == 0)
		{
			cout << "Send new note ALSA\n";
			noteState_ = 1;
		}
		else
		{
			cout << "Send aftertouch ALSA\n";
		}
	}
}

void singleNoteGen::printStrategies()
{

}

