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

namespace PacketSender
{
	void AddPacket(string name, string data);
	void DeletePacket(int index);
	void EditPacket(int i, string name, string data);
	void Save(string filename);
	void Load(string filename);
}

extern int SpammedPackets;