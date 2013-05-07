#pragma once
public ref class GeneralSettings
{
public:
	GeneralSettings(void)
	{
		WatyBotFileName = "";
		MSFileName = "";
		SelectedTabIndex = -1;
	}

	~GeneralSettings(void)
	{

	}

	property System::String^ WatyBotFileName;
	property System::String^ MSFileName;
	property int SelectedTabIndex;
};

