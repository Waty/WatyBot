#include "Defines.h"

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
	if(serializer == nullptr) serializer = gcnew XmlSerializer(List<CSPControlLocation^>::typeid);
	
	auto writer = File::Create(SPControlFileName);
	try
	{
		serializer->Serialize(writer, Locations);
	}
	catch(Exception^){}
	writer->Close();
}

void CSPControl::ReadXmlData()
{
	if(serializer == nullptr) serializer = gcnew XmlSerializer(List<CSPControlLocation^>::typeid);
	if(!File::Exists(SPControlFileName))
	{
		WriteXmlData();
		return;
	}

	//Deserialize the xml file
	TextReader^ reader = gcnew StreamReader(SPControlFileName);
	try 
	{
		Locations = safe_cast<List<CSPControlLocation^>^>(serializer->Deserialize(reader));
	}
	catch(InvalidOperationException^ex ){ShowInfo(ex->ToString());}
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

DWORD dwSPControlRet = SPControlAddy + 6;
int spawn_x, spawn_y;
BOOL WINAPI GetCoords()
{
	int iMapID = CMS::MapId();
	for each(CSPControlLocation^ location in CSPControl::Locations)
	{
		if(iMapID == location->MapId)
		{
			spawn_x = location->X;
			spawn_y = location->Y;
			return TRUE;
		}
	}
	return FALSE;
}
void __declspec(naked) SPControlCave()
{
	_asm
	{
		push eax
		call GetCoords
		cmp eax,FALSE
		pop eax
		je SpawnNormal //if eax == false, jump to SpawnNormal
 
		//Spawn on controlled location
		mov edi,[spawn_x]
		mov ebx,[spawn_y]
		jmp [dwSPControlRet]
 
		SpawnNormal:
		mov edi,[eax+0x0C]
		mov ebx,[eax+0x10]
		jmp [dwSPControlRet]
	}
}
BYTE SPCCheck[] = {0xEB};
CMemory cmSPCChecks(SPCChecksAddy, SPCCheck, 1);
CMemory cmSPControl(SPControlAddy, SPControlCave, 1, true);

bool CSPControl::Enable(bool status)
{
	return (cmSPCChecks.Enable(status) && cmSPControl.Enable(status));
}
