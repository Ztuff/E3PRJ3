#include "SampleBank.hpp"

SampleBank::SampleBank()
{
	//læs fra fil
}

SampleBank::~SampleBank()
{
	saveAll();
}

string[] SampleBank::list()
{
	//hiv fat i navnet på lydpakken, for hver lydpakke der findes. (foreach)
	//Dvs efter sidste '/' står der xxxxxx.mp3
	//Dette 'navn' tilføjes til en string array
	//Returner denne string
}

SoundPack SampleBank::get()
{
	//Mangler en parameter i metoden... hvilken lydpakke?
}

void SampleBank::add(SoundPack)
{
	//Tilføj SoundPack element til mappet lydPakker_
}

void SampleBank::remove(SoundPack)
{
	//Fjern SoundPack med den givne SoundPack.filepath_ 
}

void SampleBank::save()
{
	//Gem i XML
}

SoundPack::SoundPack(filepath)
{
	filepath_ = filepath;
}

SoundPack::~SoundPack()
{

}