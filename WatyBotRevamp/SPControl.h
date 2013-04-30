#pragma once
using namespace System::Collections;
using namespace System::Xml::Serialization;

namespace SpawnControl
{
	public ref class SPControlLocation sealed
	{
	public:
		[XmlAttribute]
		property System::String^ Name;
		property int MapId;
		property int X;
		property int Y;
	};

	[XmlRootAttribute("WatyBotSpawnControl",Namespace="https://ccplz.net/resources/watybot.6/", IsNullable=false)]
	public ref class SPControl sealed
	{
	public:
		SPControl();

		[XmlArrayItem(SPControlLocation::typeid)]
		property ArrayList^ Locations;
		void AddLocation(System::String^ name, int ID, int x, int y);
		void EditLocation(int index, System::String^ name, int mapid, int x, int y);
		void DeleteLocation(int i);
	};
	extern SPControl^ LoadSPControl(System::String^ file);
	extern void SaveSPControl(System::String^ filename, SPControl^ sp);
}
