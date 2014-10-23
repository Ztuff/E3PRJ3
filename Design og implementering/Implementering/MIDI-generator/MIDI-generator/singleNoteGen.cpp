#include "singleNoteGen.h"

singleNoteGen::singleNoteGen(unsigned int root, int octave, unsigned int lowerThreshold, unsigned int dataIn ) : MIDIGen(dataIn)
{
	root_= (root >= 1 && root <= 12 ? root : 1);					//v�rdi fra 1 til 12
	octave_ = (octave >=-3 && octave<=8 ? octave : 0);				//v�rdi fra -3 til 8
	lowerThreshold_ = (lowerThreshold>127 ? 127 : lowerThreshold);	//v�rdi fra -3 til 8
	noteState_ = 0;

	int note= (octave_+3)*12+root_-1;								//indstilling af tone
	note_= (note>127 ? 127: note);									//frasortering af v�rdier over 127
	cout << "Note has number " <<note_ << "\n";
}
	
void singleNoteGen::playSingleNote()
{
	cout << "Playing single note\n";
	if(getDataIn()< lowerThreshold_)
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
			cout << "Stop aftertouch ALSA\n";
		}
	}
}

