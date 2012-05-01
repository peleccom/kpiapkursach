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
	if (on) {
		Editor->put_designMode(L"On");
	}
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

