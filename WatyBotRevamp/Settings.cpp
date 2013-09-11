#include "Settings.h"
#include "Log.h"

using namespace WatyBotRevamp;
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

Object^ Settings::Deserialize(String^ path, XmlSerializer^ serializer)
{
	if (File::Exists(path))
	{
		FileStream^ stream;
		try
		{
			stream = gcnew FileStream(path, FileMode::Open, FileAccess::Read, FileShare::Read);
			return serializer->Deserialize(stream);
		}
		catch (Exception^ ex)
		{
			Log::WriteLine("Exception occured while reading from " + path + " : " + ex->Message);
		}
		finally
		{
			if (stream) delete (IDisposable^) stream;
			Log::WriteLine("Loaded " + path);
		}
	}
	return nullptr;
}

Void Settings::Serialize(String^ path, XmlSerializer^ serializer, Object^ object)
{
	if (path != nullptr && serializer != nullptr && object != nullptr)
	{
		FileStream^ stream;
		try
		{
			stream = gcnew FileStream(path, FileMode::Create, FileAccess::Write, FileShare::None);
			serializer->Serialize(stream, object);
		}
		catch (Exception^ ex)
		{
			Log::WriteLine("Exception occured while writing to " + path + " : " + ex->Message);
		}
		finally
		{
			if (stream) delete (IDisposable^) stream;
			Log::WriteLine("Saved " + path);
		}
	}
}

Void Settings::Serialize(Control^ c, String^ XmlFileName)
{
	XmlTextWriter^ xmlSerialisedForm = gcnew XmlTextWriter(XmlFileName, System::Text::Encoding::Default);
	xmlSerialisedForm->Formatting = Formatting::Indented;
	xmlSerialisedForm->WriteStartDocument();
	xmlSerialisedForm->WriteStartElement("WatyBot");
	// enumerate all controls on the form, and serialise them as appropriate
	AddChildControls(xmlSerialisedForm, c);
	xmlSerialisedForm->WriteEndElement(); // WatyBot
	xmlSerialisedForm->WriteEndDocument();
	xmlSerialisedForm->Flush();
	xmlSerialisedForm->Close();
}

Void Settings::AddChildControls(XmlTextWriter^ xmlSerialisedForm, Control^ c)
{
	for each(Control^ childCtrl in c->Controls)
	{
		auto type = childCtrl->GetType();
		if (childCtrl->HasChildren || type == ComboBox::typeid || type == NumericUpDown::typeid || childCtrl->Name == "cbLogoSkipper" || childCtrl->Name == "cbPinTyper")
		{
			// serialise this control
			xmlSerialisedForm->WriteStartElement("Control");
			xmlSerialisedForm->WriteAttributeString("Name", childCtrl->Name);
			if (type == ComboBox::typeid) xmlSerialisedForm->WriteAttributeString("SelectedIndex", safe_cast<ComboBox^>(childCtrl)->SelectedIndex.ToString());
			else if (type == NumericUpDown::typeid) xmlSerialisedForm->WriteAttributeString("Value", safe_cast<NumericUpDown^>(childCtrl)->Value.ToString());
			else if (type == CheckBox::typeid) xmlSerialisedForm->WriteAttributeString("Checked", safe_cast<CheckBox^>(childCtrl)->Checked.ToString());

			// see if this control has any children, and if so, serialise them
			if (childCtrl->HasChildren && type != NumericUpDown::typeid) AddChildControls(xmlSerialisedForm, childCtrl);
			xmlSerialisedForm->WriteEndElement(); // Control
		}
	}
}

Void Settings::Deserialize(Control^ c, String^ XmlFileName)
{
	if (File::Exists(XmlFileName))
	{
		try
		{
			XmlDocument^ xmlSerialisedForm = gcnew XmlDocument();
			xmlSerialisedForm->Load(XmlFileName);
			XmlNode^ topLevel = xmlSerialisedForm->ChildNodes[1];
			for each(XmlNode^ n in topLevel->ChildNodes) SetControlProperties(safe_cast<Control^>(c), n);
		}
		catch (Exception^ ex)
		{
			Log::WriteLine("While deserializing \"" + c->Name + "\" the dollowing exception occured: \"" + ex->Message + "\"");
		}
	}
}

Void Settings::SetControlProperties(Control^ currentCtrl, XmlNode^ n)
{
	try
	{
		// get the control's name and type
		String^ controlName = n->Attributes["Name"]->Value;
		// find the control
		auto ctrl = currentCtrl->Controls->Find(controlName, true);
		if (ctrl->Length == 1)
		{
			// the right type too ;-)
			if (n->Attributes["SelectedIndex"]) safe_cast<ComboBox^>(ctrl[0])->SelectedIndex = Convert::ToInt32(n->Attributes["SelectedIndex"]->Value);
			else if (n->Attributes["Value"]) safe_cast<NumericUpDown^>(ctrl[0])->Value = Convert::ToDecimal(n->Attributes["Value"]->Value);
			else if (n->Attributes["Checked"]) safe_cast<CheckBox^>(ctrl[0])->Checked = Convert::ToBoolean(n->Attributes["Checked"]->Value);

			// if n has any children that are controls, deserialise them as well
			if (n->HasChildNodes && ctrl[0]->HasChildren)
			{
				XmlNodeList^ xnlControls = n->SelectNodes("Control");
				for each(XmlNode^ n2 in xnlControls) SetControlProperties(ctrl[0], n2);
			}
		}
		else
		{
			Log::WriteLine(ctrl->ToString());
		}
	}
	catch (Exception^ ex)
	{
		Log::WriteLine("While deserializing \"" + n->Attributes["Name"]->Value + "\" the dollowing exception occured: \"" + ex->Message + "\"");
	}
}
