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

bool BrowserSys::CanCut(){
	return wb->QueryStatusWB(Shdocvw::OLECMDID_CUT) != 1;
}

IHTMLTxtRange* BrowserSys::TxtRange()
{
	IHTMLSelectionObject *sel;
	BSTR SelType;
	HRESULT hr;
	IDispatch *range;
	Editor->get_selection(&sel);
	sel->get_type(&SelType);
	if (String(SelType) != "Control") {
		hr = sel->createRange(&range);
		if (!hr)
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

void BrowserSys::InsertImage(){
	TxtRange()->execCommand(L"InsertImage", true,  var, &rec);
}

void BrowserSys::Undo(){
	wb->ExecWB(OLECMDID_UNDO, OLECMDEXECOPT_DONTPROMPTUSER);
}

void BrowserSys::Redo(){
	wb->ExecWB(OLECMDID_REDO, OLECMDEXECOPT_DONTPROMPTUSER);
}

bool BrowserSys::CanUndo(){
	return  wb->QueryStatusWB(Shdocvw::OLECMDID_UNDO) > 1;
}

bool BrowserSys::CanRedo(){
	return  wb->QueryStatusWB(Shdocvw::OLECMDID_REDO) > 1;
}

void BrowserSys::SetSize(int size){
	Variant V;
	if (size>7 || size <1)
		V = "error";
	else
		V = IntToStr(size);
	TxtRange()->execCommand(L"FontSize",false,V,&rec);
}

void BrowserSys::SetFont(const String &font){
	Variant V = font;
	TxtRange()->execCommand(L"FontName",false,V,&rec);
}

void BrowserSys::SetColor(int color){
	Variant V = HtmlColor(color);
	TxtRange()->execCommand(L"ForeColor",false,V,&rec);
}

const String BrowserSys::HtmlColor(int color){
	String s;
	TColor col;
	col =  static_cast <TColor> (color);
	s.sprintf(L"#%.2X%.2X%.2X",GetRValue(col),GetGValue(col),GetBValue(col));
	return s;
}


int BrowserSys::GetSize(IHTMLTxtRange *TextRange){
	tagVARIANT *v;
	VARIANT v1;
	HRESULT hr;
	String s;
	int res = 0;
	BSTR text;
	if (TextRange)
	{
	v =(tagVARIANT*) text;
		hr =TextRange->queryCommandValue(L"jjj",v);
		if(SUCCEEDED(hr))
		{

			v1 = *v;
			if (VarIsNull(v1)) {
				res =0;
			}
			else
				s = v1.bstrVal;
				res = StrToInt(s);
		}
		else res =0;
	}

	return res;
}

bool BrowserSys::isItalic(IHTMLTxtRange *TextRange){
	HRESULT hr;
	short sh;
	if (TextRange) {
		hr = TextRange->queryCommandState(L"Italic",&sh) ;
		if (sh)
			return true;
		}
	return false ;
}

bool BrowserSys::isBold(IHTMLTxtRange *TextRange){
	short sh;
	if (TextRange) {
		TextRange->queryCommandState(L"Bold",&sh) ;
		if (sh)
			return true;
		}
	return false ;
}

bool BrowserSys::isUnderline(IHTMLTxtRange *TextRange){
	short sh;
	if (TextRange) {
		TextRange->queryCommandState(L"Underline",&sh) ;
		if (sh)
			return true;
		}
	return false ;
}


void BrowserSys::SetStyle(Style *style){
	SetSize(style->getsize());
	SetColor(style->getcolor());
	SetFont(style->getface());
	int k = style->getfontstyle();
	if	(k & fsBOLD == fsBOLD)
	 this->Bold();
	if (k & fsITALIC == fsITALIC)
		this->Italic();
	if (k & fsUNDERLINE == fsUNDERLINE)
		this->UnderLine();
}

String BrowserSys::GetText(){
	IHTMLElement* pElement;
	BSTR s;
	if (FAILED(Editor->get_body(&pElement))) return NULL;
	pElement->get_parentElement(&pElement);
	pElement->get_outerHTML(&s);
	pElement->Release();
	return String(s);
}

