#include <iostream>
#include "Parameters.h" //Vores parameter-structs
#include <conio.h> //khbit() getch()
#include <stdio.h> //printf
#include <windows.h> //Bruges for at inkludere mmsystem
#include <mmsystem.h> //Multimedie-metoder til windows, og vi skal bruge MIDI-metoderne.

#pragma comment(lib, "Winmm.lib")	//Nødvendigt for at man ikke skal deklarere MIDI-metoderne

using namespace std;

static unsigned char sensorDataOld;


void playSingleNote(struct singleNote parameter)
{
	int noteState = 0; //Note on eller off? Ved off stoppes lyden med det samme (for at lyden kan spilles igen i samme øjeblik fx)
	int midiData = (parameter.root+1)*(parameter.octave+3)-1; //Giver en værdi mellem 0 og 132
	if (midiData > 127) //MIDI anser ikke noget over 127 (Det er også en meget høj tone)
	{
		midiData = 127;
	}

	union { unsigned long word; unsigned char data[4]; } midiMessage; //Selve midi-beskeden der skal sendes til fx ALSA
	midiMessage.data[0] = 0x90; //90 svarer til kommandoen 'Note On'
	midiMessage.data[1] = midiData; //tonen
	midiMessage.data[2] = parameter.sensorData; //volumen/anslagskraft
	midiMessage.data[3] = 0; //Skal altid være 0, ubrugt parameter
	


	if(parameter.sensorData < parameter.lowerThreshold)
	{
		//Stop tone (ALSA) -
		//Hvorfor skal tonen stoppes når sensorData er mindre end lowerThreshold?
		//Hvis man så slår hårdt, genereres en tone, og derefter stoppes den med det samme, fordi sensorData < lowerThreshold???
		//noteState = 0;
	}
	else
	{
		if(noteState == 0)
		{
			//midiMessage sendes til ALSA
			//noteState = 1;
		}
		else
		{
			//Fortsæt tone...? besked til ALSA.
		}
	}
	/*
	Hvornår bliver denne funktion kaldt? Skal det i en while(1)? Hmm..

	Skal det være en højere volumen hvis man slår hårdere?) 

	Hvem indstiller lowerThreshold? Er det noget vi sætter eller kan man også vælge det i et preset?
	*/
}

/*
void quantizeDiatonic(&noteln, scale)
{

}
*/

void playContNotes(struct continuousNote parameter, note_scale scale)
{
	/* Til sidst i denne metode, kan jeg se at den bare afspiller én tone. Det kan den finde på at gøre flere gange.
	Kan det måske passe at vi i bunden af dette bare skal kalde playSingleNote? Funktionaliteten er ens.
	Jeg tror ikke det er nødvendigt med en continuousNote struct, da scala er noget man får fra et preset anyway?*/

	if( parameter.sensorData != sensorDataOld ) //Skal sensordata ikke også være med i continuousNote structen? Ellers kan du da ikke tilgå sensorData. Skal vi lave sensorDataOld uden for dette scope måske?
	{
		int noteln = 0;
		/*Afkod sensorData til tone (noteln)/*
		//kode her

		/*Noget med direction/*
		//kode her

		/* Forskyd jævnfør grundtone*/
		int root = 0;
		if (root == 0)
		{
			noteln = 0;
		}
		else
		{
			noteln = noteln + (12-root);
		}

		/*Kvantiser til skala*/ //Går ud fra at det bliver valgt i et preset eller sådan noget
		switch(scale)
		{
		case CROMATIC:
			break;
		case MAJOR:
		case MINOR:
			//quantizieDiatonic(&noteln, scale);
			break;
		}

		/* Forskyd tilbage jævnfør grundtone */

		if( root == 0)
		{
			noteln = 0;
		}
		else
		{
			noteln = noteln - (12-root);
		}

		/* Ingen behov for endnu en if/else. 
		Hvis der ikke er nogen ændring i sensorData,
		så sker der bare ikke noget!*/

		/* Afpsil tone */
		//Stop tone (ALSA besked)
		//Afspil ny stone (ALSA besked)
	}

	sensorDataOld = parameter.sensorData;
}

/*
void controlChangeAbs(struct ccAbs parameter)
{
}

void controlChangeRel(struct ccRel parameter)
{
}
*/

void paramSelect()	//Skal modtage en template struct - tror jeg
{
	/*
	switch (parameter){
	case 1:
		playSingleNote();
		break;
	case 2:
		playContNotes();
		break;
	case 3:
		controlChangeAbs();
		break;
	case 4:
		controlChangeRel();
		break;
	}
	*/
}

int main()
{
	//Oprettelse af MIDI output port nummer
	//Der skal oprettes en tråd for hver MIDI kanal. Jeg forestiller mig at hver tråd kører paramSelect?
	//Main eller noget andet skal modtage informationer om preset
	//Preset bestemmer så hvilken parameter vi bruger, og gives videre til paramSelect
}