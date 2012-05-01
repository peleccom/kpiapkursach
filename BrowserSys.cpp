//---------------------------------------------------------------------------

#pragma hdrstop

#include "BrowserSys.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

BrowserSys::BrowserSys(TCppWebBrowser *wb)
{
	this->wb = wb;
}

bool BrowserSys::InitInterfaces()
{
	HRESULT hr;
	hr = wb->Document->QueryInterface(IID_IHTMLDocument2,(void**)&Editor);
	if(SUCCEEDED(hr))
	{
		Editor->Release();
		return true;
	}
	else
		return false;
}

void BrowserSys::EditMode(bool on)
{
	if (on)
		Editor->put_designMode(L"On");
	else
		Editor->put_designMode(L"Off");
}

bool BrowserSys::CanCopy(){
	return wb->QueryStatusWB(Shdocvw::OLECMDID_COPY) != 1;
}

bool BrowserSys::CanPaste(){

	return wb->QueryStatusWB(Shdocvw::OLECMDID_PASTE) != 1;
}

IHTMLTxtRange* BrowserSys::TxtRange()
{
	IHTMLSelectionObject *sel;
	BSTR SelType;
	IDispatch *range;
	Editor->get_selection(&sel);
	sel->get_type(&SelType);
	if (String(SelType) != "Control") {
		sel->createRange(&range);
		return static_cast <IHTMLTxtRange*> (range);	}
	return NULL;
}

void BrowserSys::Bold(){
	TxtRange()->execCommand(L"bold",false,var, &rec);
}

void BrowserSys::Italic(){
	TxtRange()->execCommand(L"italic",false,var, &rec);
}

void BrowserSys::UnderLine(){
	TxtRange()->execCommand(L"underline",false,var, &rec);
}

void BrowserSys::Paste(){
	wb->ExecWB(OLECMDID_PASTE, OLECMDEXECOPT_DONTPROMPTUSER);
}

void BrowserSys::Copy(){
	wb->ExecWB(OLECMDID_COPY, OLECMDEXECOPT_DONTPROMPTUSER);
}

void BrowserSys::Cut(){
	wb->ExecWB(OLECMDID_CUT, OLECMDEXECOPT_DONTPROMPTUSER);
}

void BrowserSys::InsertList(){
  TxtRange()->execCommand(L"InsertUnorderedList", false, var, &rec);
}

void BrowserSys::HyperLink(){
	TxtRange()->execCommand(L"CreateLink", true, var, &rec);
}
