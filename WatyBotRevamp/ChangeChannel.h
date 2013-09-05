#pragma once
#include "MapleStory.h"

namespace WatyBotRevamp
{
	using namespace System;

	enum class CCType{CC, CS, DC};
	public ref class CC sealed
	{
	public:
		static property bool IsBusy{bool get();}
		static void CCSwitch(CCType type);

	private:
		static System::ComponentModel::BackgroundWorker^ bw = gcnew System::ComponentModel::BackgroundWorker;
		static Void doCC(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^  e);
		static Void doDC(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^  e);
		static Void doCS(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^  e);
		static Void GenerateRandomChannel();
		static property int StartChannel;
		static property int TargetChannel;
	};
}
