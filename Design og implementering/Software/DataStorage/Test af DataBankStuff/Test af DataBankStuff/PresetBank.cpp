#include "PresetBank.hpp"

PresetBank::PresetBank()
{

}

void PresetBank:: edit(Preset pre)
{
	presets_.erase(presets_.begin()+(pre.getID())); //Slet det gamle preset
	presets_.insert((presets_.begin()+(pre.getID())), pre); //Indsæt det nye
}

/*
vector<string> PresetBank:: list()
{

}
*/

Preset PresetBank:: get(int ID)
{
	return presets_[ID];
}

void PresetBank:: save()
{

}

PresetBank:: ~PresetBank()
{

}

Preset:: Preset()
{

}

Preset:: ~Preset()
{

}