#pragma once
#include <Windows.h>

namespace WatyBotManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Button^  bStartMS;
	private: System::Windows::Forms::Panel^  panel1;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->bStartMS = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(2, 2);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1088, 670);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->panel1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1080, 644);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"tabPage1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Location = System::Drawing::Point(6, 8);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1068, 631);
			this->panel1->TabIndex = 2;
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(838, 623);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// bStartMS
			// 
			this->bStartMS->Location = System::Drawing::Point(867, -1);
			this->bStartMS->Name = L"bStartMS";
			this->bStartMS->Size = System::Drawing::Size(224, 23);
			this->bStartMS->TabIndex = 1;
			this->bStartMS->Text = L"Start MapleStory";
			this->bStartMS->UseVisualStyleBackColor = true;
			this->bStartMS->Click += gcnew System::EventHandler(this, &MainForm::bStartMS_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1090, 674);
			this->Controls->Add(this->bStartMS);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MainForm";
			this->Text = L"$W4GB0t2013YOLO";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void bStartMS_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void cbCPUHack_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void bEmbedMS_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void bSafetySwitch_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbTeleDelay_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void nudTeleDelay_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbUnlAtk_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbSiegeMode_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbJDA_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void bItemVacChar_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbFLACC_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void nudGMMisses_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void nudItemVacY_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbDojangGM_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbDelayGM_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void nudGMSecs_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void nudItemVacX_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbKami_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbItemVac_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbSwimHack_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void nudKamiXRange_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbKamiLoot_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void nudKamiYRange_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbPerfectLoot_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void nudKamiItems_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbNoCharKB_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbSuspendMobs_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void bKBFHCharFH_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void bMMCCharPos_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbKBFHVac_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbMobFreeze_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbFilterMobs_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void nudKBFH_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbFasterMobs_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbLemmings_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbNoMobKB_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbVacRight_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbMobDisarm_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void nudMMCY_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void nudMMCX_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbMMC_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbWUVac_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbJUVac_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void nudSlwib_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void nudSawsil_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbAutoCCDelay_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbAutoCCPeople_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void nudCCDelay_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void nudCCPeople_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbMPKey_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void nudMP_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbHPKey_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void nudHP_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbAutoPot_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbLootKey_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void nudLootDelay_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbAutoLoot_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbAttackKey_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void nudAttackDelay_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbAutoAttack_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbAutoSkill2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbAutoSkill1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbAutoSkill4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbAutoSkill3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbAutoSkill_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbSkillKey2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbSkillKey3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbSkillKey4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbSkillKey1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void nudSkillDelay1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void nudSkillDelay4_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void nudSkillDelay3_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void nudSkillDelay2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbSkillKamiDisable_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void bClearAll_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void nudMesoFilter_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbMesoFilter_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void cbItemFilter_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void bRemoveItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void bAddItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
