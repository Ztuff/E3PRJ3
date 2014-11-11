class PresetBank{
	public:
	PresetBank();
	~PresetBank();
	
	private:
	Vector<Preset> presets_
};

class Preset{
	public:
	Preset();
	~Preset();
	
	private:
	Vector<SensorConfiguration*> sensorConfigs_
};
