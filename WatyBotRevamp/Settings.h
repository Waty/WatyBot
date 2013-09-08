#pragma once
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Xml::Serialization;

namespace WatyBotRevamp
{
	public ref class SettingsEntry
	{
	public:
		SettingsEntry()
		{
			Name = String::Empty;
			Value = -1;
		}
		SettingsEntry(NumericUpDown^ nud)
		{
			Name = nud->Name;
			Value = (Object^) nud->Value;
		}
		SettingsEntry(CheckBox^ cb)
		{
			Name = cb->Name;
			Value = (Object^) cb->Checked;
		}
		SettingsEntry(ComboBox^ cb)
		{
			Name = cb->Name;
			Value = (Object^) cb->SelectedIndex;
		}

		[XmlAttribute]
		property String^ Name;
		property Object^ Value;
	};

	public ref class Settings
	{
	public:
		static String^ Path = System::IO::Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData), "Waty", "Settings.xml");
		static Object^ Deserialize(String^ Path, XmlSerializer^ Deserializer);
		static Void Serialize(String^ Path, XmlSerializer^ Serializer, Object^ Collection);
	};

}
