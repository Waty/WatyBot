#pragma once
#include <Windows.h>
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Xml::Serialization;

namespace Settings
{
	public ref class Setting abstract
	{
	public:
		Setting(){}
		virtual property int Value;
	};
	public ref class NumericUpDownSetting sealed : Setting
	{
	public:
		NumericUpDownSetting() : Setting()
		{

		}
		NumericUpDownSetting(NumericUpDown^ nud) : Setting()
		{
			this->nud = nud;
		}
		NumericUpDown^ nud;
	};
	public ref class ComboBoxSetting sealed : Setting
	{
	public:
		ComboBoxSetting() : Setting()
		{

		}
		ComboBoxSetting(ComboBox^ ddb) : Setting()
		{
			this->ddb = ddb;
		}
		ComboBox^ ddb;
	};
	public ref class CheckBoxSetting sealed : Setting
	{
	public:
		CheckBoxSetting() : Setting()
		{

		}
		CheckBoxSetting(CheckBox^ cb) : Setting()
		{
			this->cb = cb;
		}
		CheckBox^ cb;
	};
	
	[XmlRootAttribute("WatyBotSettings",Namespace="https://ccplz.net/resources/watybot.6/", IsNullable=false)]
	public ref class SettingsManager sealed
	{
	public:
		SettingsManager();
		~SettingsManager();
		[XmlArrayItem(NumericUpDownSetting::typeid), XmlArrayItem(ComboBoxSetting::typeid),	XmlArrayItem(CheckBoxSetting::typeid)]
		ArrayList^ Settings;
		void Add(Setting^ setting);
	};
}
