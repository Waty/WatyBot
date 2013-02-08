#pragma once
#include <string>
#include <vector>
using namespace std;
	
struct sPacket
{
	string name;
	string data;
};

typedef vector<sPacket> PacketVector;
extern PacketVector vPacket;

extern void AddPacket(string name, string data);
extern void DeletePacket(int index);
extern void EditPacket(int i, string name, string data);
extern void WritePacketXML(string filename);
extern void ReadPacketXML(string filename);

extern int SpammedPackets;