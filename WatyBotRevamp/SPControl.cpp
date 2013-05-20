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

CSPControl::CSPControl()
{
	if(!File::Exists(SPControlFileName))
	{
		auto stream = File::Create(SPControlFileName);
		stream->Close();
	}
	
	TextReader^ reader = gcnew StreamReader(SPControlFileName);
	s = gcnew XmlSerializer(List<CSPControlLocation^>::typeid);
	try
	{
		Locations = safe_cast<List<CSPControlLocation^>^>(s->Deserialize(reader));
	}
	catch(Exception^ ex)
	{
		ShowNotifyIcon(ex->Message);
	}	
	reader->Close();
	if(Locations == nullptr) Locations = gcnew List<CSPControlLocation^>;
}

void CSPControl::Save()
{
	TextWriter^ writer = gcnew StreamWriter(SPControlFileName);
	try
	{
		s->Serialize(writer, Locations);
	}
	catch(Exception^ ex)
	{
		ShowNotifyIcon(ex->Message);
	}
	writer->Close();
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
	this->Save();
}

DWORD dwSPControlRet = SPControlAddy + 6;
extern BOOL WINAPI GetCoords();
int spawn_x, spawn_y;
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
		mov ebx,[spawn_x]
		mov ebp,[spawn_y]
		jmp [dwSPControlRet]
 
		SpawnNormal:
		mov ebx,[eax+0x0C]
		mov ebp,[eax+0x10]
		jmp [dwSPControlRet]
	}
}
CMemory cmSPControl(SPControlAddy, SPControlCave, 1, true);

bool CSPControl::Enable(bool status)
{
	return cmSPControl.Enable(status);
}
