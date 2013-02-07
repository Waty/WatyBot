#include "Packet.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

CPacket::CPacket(string filename)
{
	using boost::property_tree::ptree;
	ptree pt;
	read_xml(filename, pt);

	BOOST_FOREACH( ptree::value_type const& v, pt.get_child("packetlist"))
	{
		if(v.first == "packet")
		{
			packetStruct p;
			p.Name = v.second.get<string>("name");
			p.Data = v.second.get<string>("data");
			Packetv.push_back(p);
		}
	}
}

packetStruct CPacket::At(int i)
{
	return Packetv.at(i);
}

void CPacket::WriteXML(string filename)
{
	using boost::property_tree::ptree;
	ptree pt;

	BOOST_FOREACH( packetStruct p, Packetv )
	{
        ptree & node = pt.add("packetlist.packet", "");
		node.put("name", p.Name);
		node.put("data", p.Data);
    }
	write_xml(filename, pt);
}

void CPacket::EditPacket(int index, string name, string data)
{
	Packetv.at(index).Name = name;
	Packetv.at(index).Data = data;
}

void CPacket::DeletePacket(int index)
{
	Packetv.erase(Packetv.begin() + index);
}

void CPacket::AddPacket(string name, string data)
{
	packetStruct p;
	p.Name = name;
	p.Data = data;
	Packetv.push_back(p);
}


CPacket::~CPacket(void)
{
}