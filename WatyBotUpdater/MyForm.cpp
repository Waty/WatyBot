#include "MyForm.h"
#include "PatternFind.h"
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <msclr/marshal_cppstd.h>
#include <fstream>

using namespace WatyBotUpdater;
using namespace System::IO;
using namespace msclr::interop;
using namespace std;

#define ShowInfo(Message)		MessageBox::Show(Message, "Information", MessageBoxButtons::OK, MessageBoxIcon::Information)




PFSEARCH pf;
void *lpvMapleBase = NULL;
DWORD dwMapleSize = 0;
void MyForm::bUpdate_Click(System::Object^  sender, System::EventArgs^  e)
{
	lpvMapleBase = reinterpret_cast<LPVOID>(0x00400000);
	ifstream file("AOBs");
	using boost::property_tree::ptree;
	ptree pt;
	read_xml(file, pt);
	StreamWriter^ sw = File::CreateText("Addys.h");

	if(!pt.empty())
	{
		BOOST_FOREACH( ptree::value_type const& v, pt.get_child("aobs"))
		{
			if(v.first == "addy")
			{
				string aob = v.second.get<string>("aob");
				String^ name = marshal_as<String^>(v.second.get<string>("name"));

				FindPattern((char*)aob.c_str(), &pf, lpvMapleBase, dwMapleSize);
				DWORD result = (DWORD)pf.lpvResult;
			

				//Write the found addy to the header file
				try
				{
					sw->WriteLine("#define " + name + " " + result.ToString("X"));
				}
				finally
				{
					if (sw)	delete (IDisposable^)(sw);
				}
			}
		}
	}
}

void InitializeTrainer(HINSTANCE hInstance)
{
    DisableThreadLibraryCalls(hInstance);
    GetModuleSize(GetModuleHandle(NULL), &lpvMapleBase, &dwMapleSize); // Obtain Maple base address & size

	//Run the form
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	Application::Exit();
}

void MyForm::MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
{
	TerminateProcess(GetCurrentProcess(), 0);
	ExitProcess(0);
}
