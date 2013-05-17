#include "ChangeChannel.h"
#include "Packet.h"
#include "MapleStory.h"
#include "Packet.h"
#include <Windows.h>
#include "Memory.h"
#include <vcclr.h>

using namespace ChangeChannel;
using namespace System;

extern gcroot<CMapleStory^> CMS;
extern gcroot<Packets::CPackets^> CPacket;

typedef void (__stdcall* PFN_CField_SendTransferChannelRequest)(unsigned char nChannel);
auto CField_SendTransferChannelRequest = reinterpret_cast<PFN_CField_SendTransferChannelRequest>(CCAddy);

CChangeChannel::CChangeChannel()
{
	bw = gcnew System::ComponentModel::BackgroundWorker;
}

void CChangeChannel::CCSwitch(CCType type)
{
	if(Busy) return;
	String^ strError = String::Empty;
	switch(type)
	{
	case CCType::CC:
		bw->DoWork += gcnew ComponentModel::DoWorkEventHandler(this, &CChangeChannel::CC);
		bw->RunWorkerAsync();
		break;

	case CCType::CS:
		bw->DoWork += gcnew ComponentModel::DoWorkEventHandler(this, &CChangeChannel::CS);
		bw->RunWorkerAsync();
		break;

	case CCType::DC:
		bw->DoWork += gcnew ComponentModel::DoWorkEventHandler(this, &CChangeChannel::DC);
		bw->RunWorkerAsync();
		break;
	}
}

//Generate a random int to CC to + check if it is a different channel
void CChangeChannel::GenerateRandomChannel()
{
	do
	{
		srand (GetCurrentTime());
		TargetChannel = rand()%14;
	}		
	while(TargetChannel == StartChannel);
}

void CChangeChannel::CC(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
{
	if(!CMS->InGame)
	{
		e->Cancel;
		return;
	}
	
	//Store the currrent Channel
	StartChannel = CMS->Channel;

	GenerateRandomChannel();

	//Sleep while breath > 0
	while(CMS->Breath > 0) Sleep(100);
	
	int i = 0;
	while(CMS->Channel != TargetChannel && CMS->Channel != -1)
	{
		//if the CC didn't happen after trying 10 times, Generate new random channel
		if(i > 10) GenerateRandomChannel();

		//Send the CC request
		CField_SendTransferChannelRequest(TargetChannel);
		Sleep(1000);
		i++;
	}
}

void CChangeChannel::CS(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
{
	if(!CMS->InGame) e->Cancel;
	while(CMS->Breath != 0) Sleep(100);
	Sleep(500);
	String^ strError = String::Empty;
	CPacket->Send(EnterCashShop, strError);
	Sleep(2500);
	CPacket->Send(LeaveCashShop, strError);
	Sleep(3000);
}

void CChangeChannel::DC(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
{
	while(CMS->InGame)
	{
		String^ strError = String::Empty;
		CPacket->Send(ChangeCharacter, strError);
		Sleep(2500);
	}
}
