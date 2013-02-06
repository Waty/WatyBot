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
	CPacket(void);
	~CPacket(void);
	void ReadXML(string filename);
	void WriteXML(string filename);


	typedef vector<packetStruct> PacketVector;
	PacketVector Packetv;
private:
	int test;
};