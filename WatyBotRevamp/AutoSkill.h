#pragma once
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

private:
	System::Windows::Forms::Timer^ timer;
	void AutoSkill_Tick(System::Object^  sender, System::EventArgs^  e);

	System::ComponentModel::BackgroundWorker^ bw;
	void CastBackground(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^  e);
};
