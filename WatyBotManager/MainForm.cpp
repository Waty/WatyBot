#include "MainForm.h"
using namespace WatyBotManager;

void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm);
	Application::Exit();
}

void MainForm::MainForm_Resize(System::Object^  sender, System::EventArgs^  e)
{
	this->tabControl1->Width = this->Width - 16;
	this->tabControl1->Height = this->Height - 40;
}

void MainForm::startNewTabToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	::MessageBox::Show("No");
}