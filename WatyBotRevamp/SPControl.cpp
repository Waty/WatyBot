#include <Windows.h>
#include "SPControl.h"
using namespace SpawnControl;
using namespace System::IO;
using namespace System::Windows::Forms;

SPControl::SPControl()
{
	if(File::Exists(SPControlFileName))
	{
		TextReader^ reader = gcnew StreamReader(SPControlFileName);
		try
		{
			auto serializer = gcnew XmlSerializer(List<SPControlLocation^>::typeid);
			Locations = safe_cast<List<SPControlLocation^>^>(serializer->Deserialize(reader));
			reader->Close();
			return;
		}
		catch(System::Exception^)
		{
			reader->Close();
			File::Delete(SPControlFileName);
		}
	}
	Locations = gcnew List<SPControlLocation^>;
}

void SPControl::Save()
{
	TextWriter^ writer = gcnew StreamWriter(SPControlFileName);
	try
	{
		XmlSerializer^ serializer = gcnew XmlSerializer(List<SPControlLocation^>::typeid);
		serializer->Serialize(writer, Locations);
	}
	catch(System::Exception^){}
	writer->Close();
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
	Locations[index]->Name = name;
	Locations[index]->MapId = mapid;
	Locations[index]->X = x;
	Locations[index]->Y = y;
}

void SPControl::DeleteLocation(int i)
{
	Locations->RemoveAt(i);
}
