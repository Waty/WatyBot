#include "Packet.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

CPacket::CPacket(void)
{
}


CPacket::~CPacket(void)
{
}

void CPacket::ReadXML(string filename)
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
