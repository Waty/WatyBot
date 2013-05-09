#include <Windows.h>
#include "SPControl.h"
#include "HackAddys.h"
using namespace SpawnControl;
using namespace System::IO;
using namespace System::Windows::Forms;

SPControlLocation::SPControlLocation()
{
	Name = "Error";
	MapId = -1;
	X = -1;
	Y = -1;
}

SPControlLocation::SPControlLocation(String^ name, int MapId, int X, int Y)
{
	this->Name = name;
	this->MapId = MapId;
	this->X = X;
	this->Y = Y;
}

SPControl::SPControl()
{
	Load();
}

void SPControl::Load()
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

void SPControl::EditLocation(int index, String^ name, int mapid, int x, int y)
{
	Locations[index]->Name = name;
	Locations[index]->MapId = mapid;
	Locations[index]->X = x;
	Locations[index]->Y = y;
}

void SPControl::AddLocation(String^ Name, int MapId, int X, int Y)
{
	SPControlLocation^ l = gcnew SPControlLocation;
	l->Name = Name;
	l->MapId = MapId;
	l->X = X;
	l->Y = Y;
	Locations->Add(l);
	this->Save();
}
