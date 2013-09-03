#include "SPControl.h"

using namespace WatyBotRevamp;

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

void SPControl::WriteXmlData()
{
	auto writer = File::Create(Path);
	try
	{
		serializer->Serialize(writer, Locations);
	}
	catch(Exception^){}
	writer->Close();
}

void SPControl::ReadXmlData()
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
		Locations = safe_cast<List<SPControlLocation^>^>(serializer->Deserialize(reader));
	}
	catch(InvalidOperationException^){}
	reader->Close();
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
	WriteXmlData();
}
