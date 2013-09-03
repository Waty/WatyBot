#pragma once

namespace WatyBotRevamp
{
	using namespace System;
	using namespace System::IO;
	using namespace System::Collections::Generic;
	using namespace System::Xml::Serialization;

	public ref class AutoSkillEntry
	{
	public:
		AutoSkillEntry();
		AutoSkillEntry(System::String^ name, int interval, int key);
		~AutoSkillEntry();
		void Cast();

		System::String^ Name;
		int keyIndex;
		property int Interval
		{
			int get()
			{
				return timer->Interval / 1000;
			}
			void set(int i)
			{
				timer->Interval = i * 1000;
			}
		}
		[System::Xml::Serialization::XmlIgnoreAttribute]
		property bool Enabled
		{
			void set(bool state)
			{
				if(state) Cast(); 
				timer->Enabled = state;
			}
			bool get()
			{
				return timer->Enabled;
			}
		}

	private:
		System::Windows::Forms::Timer^ timer;
		void AutoSkill_Tick(System::Object^  sender, System::EventArgs^  e);

		System::ComponentModel::BackgroundWorker^ bw;
		void CastBackground(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^  e);
	};


	public ref class AutoSkill
	{
	public:
		static Void ReadXmlData();
		static Void WriteXmlData();
		static String^ Path = Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData), "Waty\\AutoSkill.xml");

		static XmlSerializer^ serializer = gcnew XmlSerializer(List<AutoSkillEntry^>::typeid);
		static List<AutoSkillEntry^>^ AutoSkills = gcnew List<AutoSkillEntry^>;
	};
}
