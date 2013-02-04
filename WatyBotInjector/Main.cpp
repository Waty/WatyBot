#include "MyForm.h"
#include <Windows.h>

using namespace WatyBotInjector;

void MyForm::OpenMSFile_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
{

}

void MyForm::MyForm_Load(System::Object^  sender, System::EventArgs^  e)
{
}

void MyForm::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(OpenMSFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{

	}

}





int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm());
	Application::Exit();
}
