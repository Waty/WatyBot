#pragma once

namespace SpawnControl
{
	public ref class SPControlLocation sealed
	{
	public:
		property System::String^ Name;
		property int MapId;
		property int X;
		property int Y;
	};

	public ref class SPControl sealed
	{
	public:
		property System::String^ Title;
		property System::String^ Description;

		void Load(System::String^ filename);
		void AddLocation(System::String^ name, int ID, int x, int y);
		void EditLocation(int index, System::String^ name, int mapid, int x, int y);
		void DeleteLocation(int i);
		void Save(System::String^ filename);
	};
}
