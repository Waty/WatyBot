#include "SPControl.h"
#include "Settings.h"

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
	Settings::Serialize(Path, serializer, Locations);
}

void SPControl::ReadXmlData()
{
	Object^ Result = Settings::Deserialize(Path, serializer);
	if (Result != nullptr) Locations = safe_cast<List<SPControlLocation^>^>(Result);
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
