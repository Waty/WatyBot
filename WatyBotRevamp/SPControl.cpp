#include "SPControl.h"
#include <string>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <msclr/marshal_cppstd.h>

using namespace msclr::interop;
using namespace SpawnControl;

void SPControl::Load(System::String^ filename)
{
	if(!Locations) Locations = gcnew ArrayList;
	using namespace System::IO;
	if(!File::Exists(filename)) return;
	using boost::property_tree::ptree;
	ptree pt;
	read_xml(marshal_as<std::string>(filename), pt);
	if(!pt.empty())
	{
		for(ptree::value_type const& v : pt.get_child("spcontrol"))
		{
			if(v.first == "location")
			{
				SPControlLocation^ loc = gcnew SPControlLocation();
				loc->Name = marshal_as<System::String^>(v.second.get<std::string>("mapname"));
				loc->MapId = v.second.get<int>("mapid");
				loc->X = v.second.get<int>("x");
				loc->Y = v.second.get<int>("y");
				Locations->Add(loc);
			}	
		}
	}
}

void SPControl::AddLocation(System::String^ name, int ID, int x, int y)
{
	SPControlLocation^ SP = gcnew SPControlLocation;
	SP->Name = name;
	SP->MapId = ID;
	SP->X = x;
	SP->Y = y;
	Locations->Add(SP);
}

void SPControl::EditLocation(int index, System::String^ name, int mapid, int x, int y)
{
	SPControlLocation^ SP = safe_cast<SPControlLocation^>(Locations[index]);
	SP->Name = name;
	SP->MapId = mapid;
	SP->X = x;
	SP->Y = y;
	
}

void SPControl::DeleteLocation(int i)
{
	Locations->RemoveAt(i);
}

void SPControl::Save(System::String^ filename)
{
	using namespace System::IO;
	using boost::property_tree::ptree;
	ptree pt;

	for each(SPControlLocation^ SP in Locations)
	{
        ptree & node = pt.add("spcontrol.location", "");
		node.put("mapname", marshal_as<std::string>(SP->Name));
		node.put("mapid", SP->MapId);
		node.put("x", SP->X);
		node.put("y", SP->Y);
    }
	write_xml(marshal_as<std::string>(filename), pt);
}