#include <Windows.h>
#include "SPControl.h"

using namespace WatyBotRevamp;

CSPControlLocation::CSPControlLocation()
{
	Name = "Error";
	MapId = -1;
	X = -1;
	Y = -1;
}

CSPControlLocation::CSPControlLocation(String^ name, int MapId, int X, int Y)
{
	this->Name = name;
	this->MapId = MapId;
	this->X = X;
	this->Y = Y;
}

void CSPControl::WriteXmlData()
{
	auto writer = File::Create(Path);
	try
	{
		serializer->Serialize(writer, Locations);
	}
	catch(Exception^){}
	writer->Close();
}

void CSPControl::ReadXmlData()
{
	if(!File::Exists(Path))
	{
		WriteXmlData();
		return;
	}

	//Deserialize the xml file
	TextReader^ reader = gcnew StreamReader(Path);
	try 
	{
		Locations = safe_cast<List<CSPControlLocation^>^>(serializer->Deserialize(reader));
	}
	catch(InvalidOperationException^){}
	reader->Close();
}

void CSPControl::EditLocation(int index, String^ name, int mapid, int x, int y)
{
	Locations[index]->Name = name;
	Locations[index]->MapId = mapid;
	Locations[index]->X = x;
	Locations[index]->Y = y;
}

void CSPControl::AddLocation(String^ Name, int MapId, int X, int Y)
{
	CSPControlLocation^ l = gcnew CSPControlLocation;
	l->Name = Name;
	l->MapId = MapId;
	l->X = X;
	l->Y = Y;
	Locations->Add(l);
	WriteXmlData();
}
