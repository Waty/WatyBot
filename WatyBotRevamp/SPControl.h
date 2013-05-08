#pragma once
using namespace System::Collections::Generic;
using namespace System::Xml::Serialization;

namespace SpawnControl
{
#define SPControlFileName (System::Environment::GetFolderPath(System::Environment::SpecialFolder::ApplicationData) + "\\Waty\\WatyBotSPControl.xml")

	[XmlRootAttribute("WatyBotSpawnControl", Namespace="https://ccplz.net/resources/watybot.6/", IsNullable=false)]
	public ref class SPControlLocation sealed
	{
	public:
		[XmlAttribute]
		property System::String^ Name;
		property int MapId;
		property int X;
		property int Y;
	};

	public ref class SPControl sealed
	{
	public:
		SPControl();
		void Save();
		void AddLocation(System::String^ name, int ID, int x, int y);
		void EditLocation(int index, System::String^ name, int mapid, int x, int y);
		void DeleteLocation(int i);

		property List<SPControlLocation^>^ Locations;
	};
}
