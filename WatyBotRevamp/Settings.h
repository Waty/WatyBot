#pragma once
#include <Windows.h>
using namespace System;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Xml::Serialization;

namespace Settings
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
}
