#pragma once
#include <string>
#include <vector>
using namespace std;
	
struct packetStruct
{
	string Name;
	string Data;
};

class CPacket
{
public:
	typedef vector<packetStruct> PacketVector;
	PacketVector Packetv;
	CPacket(string);
	~CPacket(void);
	void WriteXML(string);
	void AddPacket(string name, string data);
	void EditPacket(int, string, string);
	void DeletePacket(int index);
	packetStruct At(int);

	int SpammedPackets;
};