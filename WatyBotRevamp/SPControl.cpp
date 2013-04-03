#include "SPControl.h"
#include <fstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
SPControlVector SPControlv;

void SPControl::AddSPControl(string name, int ID, int x, int y)
{
	SPControlStruct SP;
	SP.mapName = name;
	SP.mapID = ID;
	SP.x = x;
	SP.y = y;
	SPControlv.push_back(SP);
}

void SPControl::EditSPControl(int i, string mapname, int mapid, int x, int y)
{
	SPControlStruct SP = SPControlv.at(i);
	SP.mapName = mapname;
	SP.mapID = mapid;
	SP.x = x;
	SP.y = y;
}

void SPControl::DeleteSPControl(int i)
{
	SPControlv.erase(SPControlv.begin() + i);
}

void SPControl::Load(string filename)
{
	ifstream file(filename);
	using boost::property_tree::ptree;
	ptree pt;
	read_xml(file, pt);
	if(!pt.empty())
	{
		for(ptree::value_type const& v : pt.get_child("spcontrol"))
		{
			if(v.first == "location")
			{
				SPControlStruct SP;
				SP.mapName = v.second.get<string>("mapname");
				SP.mapID = v.second.get<int>("mapid");
				SP.x = v.second.get<int>("x");
				SP.y = v.second.get<int>("y");
				SPControlv.push_back(SP);
			}	
		}
	}
}

void SPControl::Save(string filename)
{
	ofstream file(filename);
	using boost::property_tree::ptree;
	ptree pt;

	for(SPControlStruct SP : SPControlv)
	{
        ptree & node = pt.add("spcontrol.location", "");
		node.put("mapname", SP.mapName);
		node.put("mapid", SP.mapID);
		node.put("x", SP.x);
		node.put("y", SP.y);
    }
	write_xml(file, pt);
}