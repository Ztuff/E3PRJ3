#include "SampleBank.hpp"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

using namespace std;

SoundPack::SoundPack()
{
	SoundPack("defaultSound.wav"); //en lyd der ligger i roden af projektet
}

SoundPack::SoundPack(string filepath)
	:filepath_(filepath)
{

}

SoundPack::~SoundPack()
{
}

SampleBank::SampleBank(/*const string &sourcepath*/)
{
	//læs fra fil
	using boost::property_tree::ptree;
	ptree pt;
	read_xml("SampleBank.xml", pt); 

	BOOST_FOREACH(ptree::value_type &v, //for hvert node under root/samples kør add
		pt.get_child("root.samples"))
	{
		SoundPack newSoundPack("C:/test/" + v.second.data());
		soundPacks_.insert(std::make_pair(v.second.data(), newSoundPack));
	}
	save();
}

SampleBank::~SampleBank()
{
	save();
}

vector<string> SampleBank::list()
{
	vector<string> soundsVector;
	for(map<string, SoundPack>:: iterator it = soundPacks_.begin(); it != soundPacks_.end(); ++it) 
	{
		soundsVector.push_back(it->first);
	}
	return soundsVector;
}

SoundPack SampleBank::get(string key)
{
	return soundPacks_.find(key)->second;
}

void SampleBank::add(string key) //Tilføj SoundPack element til mappet soundPacks_
{
	SoundPack newSoundPack("C:/test/" + key);
	soundPacks_.insert(std::make_pair(key, newSoundPack));
	save();
}

void SampleBank::remove(string key) //Fjern SoundPack med den givne SoundPack.filepath_ 
{
	soundPacks_.erase(key);
	save();
}

void SampleBank::save()
{
	using boost::property_tree::ptree;
	ptree pt;
	pt.put("root.samples", "");
	for(map<string, SoundPack>:: iterator it = soundPacks_.begin(); it != soundPacks_.end(); ++it) 
	{
		pt.add("root.samples.sample", it->first);
	}
    write_xml("SampleBank.xml", pt); //Sletter den gamle fil og laver en helt ny, i princippet.
}
