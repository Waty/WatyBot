#pragma once
#include "HackAddys.h"
#include "MapleStory.h"
namespace ChangeChannel
{
	enum class CCType{CC, CS, DC};
	public ref class CChangeChannel sealed
	{
	public:
		CChangeChannel();
		property bool Busy
		{
			bool get() {return bw->IsBusy;}
		}
		void CCSwitch(CCType type);

	private:
		CMapleStory^ CMS;
		System::ComponentModel::BackgroundWorker^ bw;
		void CC(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^  e);
		void DC(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^  e);
		void CS(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^  e);
		void GenerateRandomChannel();
		property int StartChannel;
		property int TargetChannel;
	};
}
