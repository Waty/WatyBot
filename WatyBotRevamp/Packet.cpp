#include "Packet.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <fstream>

PacketVector vPacket;
int SpammedPackets;

void PacketSender::AddPacket(string name, string data)
{
	sPacket p;
	p.name = name;
	p.data = data;
	vPacket.push_back(p);
}

void PacketSender::DeletePacket(int i)
{
	vPacket.erase(vPacket.begin() + i);
}

void PacketSender::EditPacket(int i, string name, string data)
{
	vPacket.at(i).name = name;
	vPacket.at(i).data = data;
}

void PacketSender::Save(string filename)
{
	ofstream file(filename);
	using boost::property_tree::ptree;
	ptree pt;

	for(sPacket p : vPacket)
	{
        ptree & node = pt.add("packetlist.packet", "");
		node.put("name", p.name);
		node.put("data", p.data);
    }
	write_xml(file, pt);
}

void PacketSender::Load(string filename)
{
	ifstream file(filename);
	using boost::property_tree::ptree;
	ptree pt;
	read_xml(file, pt);
	if(!pt.empty())
	{
		for(ptree::value_type const& v : pt.get_child("packetlist"))
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