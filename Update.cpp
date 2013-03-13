#include "Update.h"
#include <fstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
UpdateVector Updatev;

void Update::ReadXML(string filename)
{
	ifstream file(filename);
	using boost::property_tree::ptree;
	ptree pt;
	read_xml(file, pt);
	if(!pt.empty())
	{
		BOOST_FOREACH( ptree::value_type const& v, pt.get_child("updatelist"))
		{
			if(v.first == "update")
			{
				UpdateStruct update;
				update.name = v.second.get<string>("name", ERROR);
				update.AOB = v.second.get<int>("AOB", ERROR);
        update.AOB2 = v.second.get<int>("AOB2", NULL);
				Updatev.push_back(SP);
			}	
		}
	}
}
