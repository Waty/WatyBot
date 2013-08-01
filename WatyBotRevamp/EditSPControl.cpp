#include "EditSPControl.h"
#include "MapleStory.h"

using namespace WatyBotRevamp;

Void EditSPControl::bGetCurrentLoc_Click(System::Object^  sender, System::EventArgs^  e)
{
	nudMapId->Value = CMS::MapId;
	nudXLoc->Value = CMS::CharX;
	nudYLoc->Value = CMS::CharY;
}
Void EditSPControl::bSaveChanges_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->DialogResult = ::DialogResult::OK;
	location->Name = tbMapName->Text;
	location->MapId = (int) nudMapId->Value;
	location->X = (int) nudXLoc->Value;
	location->Y = (int) nudYLoc->Value;

	Close();
}
Void EditSPControl::bCancel_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->DialogResult = ::DialogResult::Cancel;
	Close();
}
