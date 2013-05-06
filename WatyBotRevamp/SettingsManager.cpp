#include "SettingsManager.h"
using namespace Settings;

SettingsManager::SettingsManager(void)
{
	Settings = gcnew ArrayList;
}


SettingsManager::~SettingsManager(void)
{

}

void SettingsManager::Add(Setting^ s)
{
	Settings->Add(s);
}
