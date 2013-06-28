#include "AutoSkill.h"
#include "Defines.h"

CAutoSkill::CAutoSkill()
{
	bw = gcnew System::ComponentModel::BackgroundWorker;
	bw->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &CAutoSkill::CastBackground);
	timer = gcnew System::Windows::Forms::Timer;
	timer->Tick += gcnew System::EventHandler(this, &CAutoSkill::AutoSkill_Tick);
}

CAutoSkill::CAutoSkill(String^ name, int interval, int key)
{
	bw = gcnew System::ComponentModel::BackgroundWorker;
	bw->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &CAutoSkill::CastBackground);
	timer = gcnew System::Windows::Forms::Timer;
	timer->Tick += gcnew System::EventHandler(this, &CAutoSkill::AutoSkill_Tick);

	Name = name;
	Interval = interval;
	keyIndex = key;
}

CAutoSkill::~CAutoSkill()
{
	delete timer;
	delete bw;
}

Void CAutoSkill::AutoSkill_Tick(System::Object^  sender, System::EventArgs^  e)
{
	Cast();
}

Void CAutoSkill::Cast()
{
	if(!bw->IsBusy) bw->RunWorkerAsync();
}

Void CAutoSkill::CastBackground(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^  e)
{
	if(!CMS::InGame()) return;

	//Send Key
	while(CC->Busy || CMS::UsingAutoSkill) Sleep(500);
	CMS::UsingAutoSkill = true;
	Sleep(500);
	CMS::SendSwitch(keyIndex);
	Sleep(500);
	CMS::UsingAutoSkill = false;
}
