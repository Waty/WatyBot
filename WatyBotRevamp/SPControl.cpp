#include <Windows.h>
#include "SPControl.h"
using namespace SpawnControl;
using namespace System::IO;
using namespace System::Windows::Forms;

SPControl^ SpawnControl::LoadSPControl(System::String^ filename)
{
	if(!File::Exists(filename))
		return gcnew SPControl;

	TextReader^ reader = gcnew StreamReader(filename);
	try
	{
		XmlSerializer^ serializer = gcnew XmlSerializer(SPControl::typeid);
		return safe_cast<SPControl^>(serializer->Deserialize(reader));
	}
	catch(System::Exception^)
	{
		switch(MessageBox::Show("WatyBot Failed in loading your config for SPControl :( /n this can be because you just upgraded to a new version of WatyBot, or because the file got corrupted /n Do you want to delete the file to fix the problem?", "Error in loading SPControl", MessageBoxButtons::YesNo, MessageBoxIcon::Question))
		{
		case ::DialogResult::Yes:
			File::Delete(filename);
			return gcnew SPControl;
			break;

		case ::DialogResult::No:
			TerminateProcess(GetCurrentProcess(), 0);
			ExitProcess(0);
			break;
		}

	}
	finally{reader->Close();}
}

void SpawnControl::SaveSPControl(System::String^ filename, SPControl^ sp)
{
	TextWriter^ writer = gcnew StreamWriter( filename );
	try
	{
		if(!File::Exists(filename)) return;
		XmlSerializer^ serializer = gcnew XmlSerializer( SPControl::typeid );
		serializer->Serialize(writer, sp);
		writer->Close();
	}
	catch(System::Exception^){}
}

SPControl::SPControl()
{
	Locations = gcnew ArrayList;
}

void SPControl::AddLocation(System::String^ name, int ID, int x, int y)
{
	SPControlLocation^ SP = gcnew SPControlLocation;
	SP->Name = name;
	SP->MapId = ID;
	SP->X = x;
	SP->Y = y;
	Locations->Add(SP);
}

void SPControl::EditLocation(int index, System::String^ name, int mapid, int x, int y)
{
	SPControlLocation^ SP = safe_cast<SPControlLocation^>(Locations[index]);
	SP->Name = name;
	SP->MapId = mapid;
	SP->X = x;
	SP->Y = y;
	
}

void SPControl::DeleteLocation(int i)
{
	Locations->RemoveAt(i);
}
