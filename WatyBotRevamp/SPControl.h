#pragma once
#include <string>
#include <vector>
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
extern void AddSPControl(string MapName, int MapID, int XLocation, int YLocation);
extern void EditSPControl(int i, string mapname, int mapid, int x, int y);
extern void DeleteSPControl(int index);
extern void ReadSPControlXML(string filename);
extern void WriteSPControlXML(string filename);