#pragma once
ref class CAutoSkill
{
public:
	CAutoSkill(int interval, int key);
	~CAutoSkill();
	void Cast();

private:
	int keyIndex;

	System::Windows::Forms::Timer^ timer;
	void AutoSkill_Tick(System::Object^  sender, System::EventArgs^  e);

	System::ComponentModel::BackgroundWorker^ bw;
	void CastBackground(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^  e);
};
