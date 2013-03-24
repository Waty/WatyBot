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

namespace SPControl
{
	void AddSPControl(string MapName, int MapID, int XLocation, int YLocation);
	void EditSPControl(int i, string mapname, int mapid, int x, int y);
	void DeleteSPControl(int index);
	void Save(string filename);
	void Load(string filename);
}