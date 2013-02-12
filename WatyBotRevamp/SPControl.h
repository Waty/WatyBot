#pragma once
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

struct SPControlStruct
{
	string mapName;
	int mapID;
	int x;
	int y;
};
typedef vector<SPControlStruct> SPControlVector;
extern SPControlVector SPControlv;

extern DWORD SPControlXCoord;
extern DWORD SPControlYCoord;
extern int SPControlMapID;

void AddSPControl(string MapName, int MapID, int XLocation, int YLocation);
void EditSPControl(int i, string mapname, int mapid, int x, int y);
void DeleteSPControl(int index);
void ReadSPControlXML(string filename);
void WriteSPControlXML(string filename);
BOOL WINAPI SPControlGetCoords();