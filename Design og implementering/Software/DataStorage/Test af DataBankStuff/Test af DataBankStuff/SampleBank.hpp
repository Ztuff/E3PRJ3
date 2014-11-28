#include <vector>
#include <string>
#include <map>

class SoundPack
{
	public:
	std::string filepath_;
	SoundPack(std::string filepath);
	~SoundPack();

};
class SampleBank
{
	public:
	SampleBank(/*const std::string &sourcepath*/);
	std::vector<std::string> list();
	SoundPack get(std::string key);
	void add(std::string key);
	void remove(std::string key);
	void save();
	~SampleBank();
	
	private:
	std::map<std::string, SoundPack> soundPacks_; //Key-typen er string, data-typen er SoundPack
};

