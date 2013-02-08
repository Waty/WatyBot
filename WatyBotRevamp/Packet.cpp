#include "Packet.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <fstream>

PacketVector vPacket;
int SpammedPackets;

void AddPacket(string name, string data)
{
	sPacket p;
	p.name = name;
	p.data = data;
	vPacket.push_back(p);
}

void DeletePacket(int i)
{
	vPacket.erase(vPacket.begin() + i);
}

void EditPacket(int i, string name, string data)
{
	vPacket.at(i).name = name;
	vPacket.at(i).data = data;
}

void WritePacketXML(string filename)
{
	ofstream file(filename);
	using boost::property_tree::ptree;
	ptree pt;

	BOOST_FOREACH( sPacket p, vPacket )
	{
        ptree & node = pt.add("packetlist.packet", "");
		node.put("name", p.name);
		node.put("data", p.data);
    }
	write_xml(file, pt);
}

void ReadPacketXML(string filename)
{
	ifstream file(filename);
	using boost::property_tree::ptree;
	ptree pt;
	read_xml(file, pt);
	if(!pt.empty())
	{
		BOOST_FOREACH( ptree::value_type const& v, pt.get_child("packetlist"))
		{
			if(v.first == "packet")
			{
				sPacket p;
				p.name = v.second.get<string>("name");
				p.data = v.second.get<string>("data");
				vPacket.push_back(p);
			}
		}
	}
}