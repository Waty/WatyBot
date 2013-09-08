#include "AutoSkill.h"
#include "MapleStory.h"
#include "ChangeChannel.h"

using namespace WatyBotRevamp;

AutoSkillEntry::AutoSkillEntry()
{
	bw = gcnew System::ComponentModel::BackgroundWorker;
	bw->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &AutoSkillEntry::CastBackground);
	timer = gcnew System::Windows::Forms::Timer;
	timer->Tick += gcnew System::EventHandler(this, &AutoSkillEntry::AutoSkill_Tick);
}

AutoSkillEntry::AutoSkillEntry(String^ name, int interval, int key)
{
	bw = gcnew System::ComponentModel::BackgroundWorker;
	bw->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &AutoSkillEntry::CastBackground);
	timer = gcnew System::Windows::Forms::Timer;
	timer->Tick += gcnew System::EventHandler(this, &AutoSkillEntry::AutoSkill_Tick);

	Name = name;
	Interval = interval;
	keyIndex = key;
}

AutoSkillEntry::~AutoSkillEntry()
{
	delete timer;
	delete bw;
}

Void AutoSkillEntry::AutoSkill_Tick(System::Object^  sender, System::EventArgs^  e)
{
	Cast();
}

Void AutoSkillEntry::Cast()
{
	if (!bw->IsBusy) bw->RunWorkerAsync();
}

Void AutoSkillEntry::CastBackground(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^  e)
{
	if (!CMS::InGame) return;

	//Send Key
	while (CC::IsBusy || CMS::UsingAutoSkill) Sleep(500);
	CMS::UsingAutoSkill = true;
	Sleep(500);
	CMS::SendSwitch(keyIndex);
	Sleep(500);
	CMS::UsingAutoSkill = false;
}

Void AutoSkill::WriteXmlData()
{
	auto writer = File::Create(Path);
	try
	{
		serializer->Serialize(writer, AutoSkills);
	}
	catch (Exception^){}
	writer->Close();
}

Void AutoSkill::ReadXmlData()
{
	//If the file doesnt exist, it writes the basic structure of the class to the file, making the FileSystemWatcher reload the settings
	if (!File::Exists(Path))
	{
		WriteXmlData();
		return;
	}

	//Deserialize the xml file
	TextReader^ reader = gcnew StreamReader(Path);
	try
	{
		AutoSkills = safe_cast<List<AutoSkillEntry^>^>(serializer->Deserialize(reader));
	}
	catch (InvalidOperationException^){}
	reader->Close();
}