#include "contNoteGen.h"

contNoteGen::contNoteGen(string root, string scale, string direction)
{
	
}
	

void contNoteGen::playContNote()
{
	/*
	if(sensorData != sensorDataOld) //optimering
	{
	
	//* Afkod til sensorInput til tone **
	//omkonvertering til v�rdi mellem 0-119
	noteIn = (2< sensorData <122 ? sensorData-3 : -1);
	if(noteIn == -1) noteIn = (sensorData < 3 ? 0 : 119);

	switch(Direction){
		Case rising: //g�r intet
	Break; 
	Case falling: //"vend" tonen omkring midten
	noteIn = 120-noteIn;
	Break;
	}

	//** Forskyd j�vnf�r grundtone *
	Switch(Root)
	{
		Case c: Break:
	Case cis: noteIn+=11; Break;
	Case d: noteIn +=10; Break;
	Case dis: noteIn +=9; Break;
	Case e: noteIn+=8; Break;
	Case f: noteIn +=7; Break;
	Case fis: noteIn+=6; Break;
	Case g: noteIn +=5; Break;
	Case gis: noteIn +=4; Break;
	Case a: noteIn +=3; Break;
	Case ais: noteIn +=2; Break;
	Case b: noteIn +=1; Break;
	}

	//** Kvantiser til skala *
		switch(scale){
			Case Cromatic: //g�r intet
	Break;
	Case Major:
	Case Minor: 
	quantizeDiatonic(&noteIn, scale)//diatonisk kvantisering 
		Break;
	}

	//** Forskyd tilbage j�vnf�r grundtone **
		Switch(Root)
	{
		Case c: Break:
	Case cis: noteIn-=11; Break;
	Case d: noteIn -=10; Break;
	Case dis: noteIn -=9; Break;
	Case e: noteIn-=8; Break;
	Case f: noteIn -=7; Break;
	Case fis: noteIn-=6; Break;
	Case g: noteIn -=5; Break;
	Case gis: noteIn -=4; Break;
	Case a: noteIn -=3; Break;
	Case ais: noteIn -=2; Break;
	Case b: noteIn -=1; Break;
	}
}

//** afspil tone **
If(sensorData == sensorDataOld); //g�r intet hvis samme tone
else
{
	//1. Stop tone (send besked til ALSA)
	//2. afspil ny tone (send besked til ALSA)
}

sensorDataOld = sensorData;
*/
}

void contNoteGen::quantizeDiatonic(unsigned int &dataIn)
{

}