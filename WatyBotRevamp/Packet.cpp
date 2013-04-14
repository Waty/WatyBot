#include <Windows.h>
#include "Packet.h"
#include "Pointers.h" // where i store stuff like SendAddy and SendClassAddy
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <msclr/marshal_cppstd.h>
#include <fstream> 

using namespace Packets;
using namespace msclr::interop;

DWORD dwMSSendMethod = SendAddy;// + 5;
DWORD dwMSSendObject = *(PDWORD)(SendClassAddy+2);
DWORD dwMSSendRetVal = SendAddy - 13;

vector<gcroot<CPacketData^>> vPacket;
int SpammedPackets;

void CPackets::Add(String^ name, String^ data)
{
	CPacketData^ packet = gcnew CPacketData;
	packet->Name = name;
	packet->Data = data;
	vPacket.push_back(packet);
}

void CPackets::Delete(int i)
{
	vPacket.erase(vPacket.begin() + i);
}

void CPackets::Edit(int i, String^ name, String^ data)
{
	vPacket.at(i)->Name = name;
	vPacket.at(i)->Data = data;
}

void CPackets::Save(String^ filename)
{
	ofstream file(marshal_as<string>(filename));
	using boost::property_tree::ptree;
	ptree pt;

	for(CPacketData^ p : vPacket)
	{
        ptree & node = pt.add("packetlist.packet", "");
		node.put("name", marshal_as<string>(p->Name));
		node.put("data", marshal_as<string>(p->Data));
    }
	write_xml(file, pt);
}

void CPackets::Load(String^ filename)
{
	ifstream file(marshal_as<string>(filename));
	using boost::property_tree::ptree;
	ptree pt;
	read_xml(file, pt);
	if(!pt.empty())
	{
		for(ptree::value_type const& v : pt.get_child("packetlist"))
		{
			if(v.first == "packet")
			{
				CPacketData^ p = gcnew CPacketData;
				p->Name = marshal_as<String^>(v.second.get<string>("name"));
				p->Data = marshal_as<String^>(v.second.get<string>("data"));
				vPacket.push_back(p);
			}
		}
	}
}

void __declspec(naked) InjectPacket(COutPacket* pPacket)
{
  __asm
  {
      //set class ptr
      mov ecx,dwMSSendObject
      mov ecx,[ecx]
 
      //push packet and fake return address
      push [esp+4]
      push dwMSSendRetVal
 
      //send packet
      jmp [dwMSSendMethod]
  }
}

// Send a MapleStory packet using byte data
DWORD WINAPI SendPacketf ( __in_bcount(nLength) LPBYTE lpBytes, __in DWORD dwLength )
{
//21st Century / ZPE
    COutPacket Packet;
 
    ZeroMemory(&Packet, sizeof(COutPacket));
 
    Packet.lpbData  = lpBytes;
    Packet.dwcbData = dwLength;
 
    try {
        InjectPacket(&Packet);
        return TRUE;
 
    } catch (...) {
        return FALSE;
    }
}

bool CPackets::isGoodPacket(String^ strPacket, String^&strError)
{
    if(strPacket == String::Empty)
	{
        strError = "Packet is Empty";
        return false;
    }
 
    if((strPacket->Length)%2 == 1)
	{
        strError = "Packet size is not a multiple of 2";
        return false;
    }
 
    for (int i = 0; i < strPacket->Length; i++)
    {
        if (strPacket[i] >= '0' && strPacket[i] <= '9') continue;
        if (strPacket[i] >= 'A' && strPacket[i] <= 'F') continue;
        if (strPacket[i] == '*') continue;
 
        strError = "Invalid character detected in packet" + strPacket[i];
   
        return false;
    }
    return true;
}

bool CPackets::Send(String^ packet, String^&strError)
{	
	String^strPacket = packet->Replace(" ", "");

    if(!isGoodPacket(strPacket, strError))
        return false;

    Random^ randObj = gcnew Random();
    String^ rawBytes = String::Empty;
 
    for(int i = 0; i < strPacket->Length; i++)
	{
        if(strPacket[i] == '*')	rawBytes += randObj->Next(16).ToString("X");
        else	rawBytes += strPacket[i];
    }
 
    ::DWORD dwOffset = 0;
    ::DWORD dwLength = ( rawBytes->Length / 2 );
    ::LPBYTE lpBytes = new ::BYTE [ dwLength ];
 
    for ( int i = 0; ( dwOffset < dwLength ) && ( ( i + 1 ) < rawBytes->Length ); dwOffset++, i += 2 )
        lpBytes[dwOffset] = Byte::Parse(rawBytes->Substring(i, 2), Globalization::NumberStyles::HexNumber, Globalization::CultureInfo::InvariantCulture);
 
    try
	{
		SendPacketf(lpBytes, dwLength);
	} 
	catch ( Exception^ ){} 
	finally {delete [] lpBytes;}
    return true;
}
