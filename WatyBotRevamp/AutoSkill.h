#pragma once
#include "MapleStory.h"
public ref class CAutoSkill
{
public:
	CAutoSkill();
	CAutoSkill(System::String^ name, int interval, int key);
	~CAutoSkill();
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
	CMapleStory^ CMS;
	System::Windows::Forms::Timer^ timer;
	void AutoSkill_Tick(System::Object^  sender, System::EventArgs^  e);

	System::ComponentModel::BackgroundWorker^ bw;
	void CastBackground(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^  e);
};
