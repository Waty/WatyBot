#include <Windows.h>
#include "SPControl.h"
using namespace SpawnControl;
using namespace System::IO;
using namespace System::Windows::Forms;

SPControl^ SPControl::Load()
{
	if(File::Exists(SPControlFileName))
	{
		TextReader^ reader = gcnew StreamReader(SPControlFileName);
		try
		{
			auto serializer = gcnew XmlSerializer(List<SPControlLocation^>::typeid);
			SPControl^ s = safe_cast<SPControl^>(serializer->Deserialize(reader));
			reader->Close();
			return s;
		}
		catch(System::Exception^)
		{
			reader->Close();
			File::Delete(SPControlFileName);
		}
	}
	return gcnew SPControl;
}

void SPControl::Save()
{
	TextWriter^ writer = gcnew StreamWriter(SPControlFileName);
	try
	{
		XmlSerializer^ serializer = gcnew XmlSerializer(List<SPControlLocation^>::typeid);
		serializer->Serialize(writer, this);
	}
	catch(System::Exception^){}
	writer->Close();
}

void SPControl::EditLocation(int index, String^ name, int mapid, int x, int y)
{
	this[index]->Name = name;
	this[index]->MapId = mapid;
	this[index]->X = x;
	this[index]->Y = y;
}

void SPControl::AddLocation(String^ Name, int MapId, int X, int Y)
{
	SPControlLocation^ l = gcnew SPControlLocation;
	l->Name = Name;
	l->MapId = MapId;
	l->X = X;
	l->Y = Y;
	this->Add(l);
	this->Save();
}
