// ---------------------------------------------------------------------------

#pragma hdrstop

#include "BrowserSys.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

BrowserSys::BrowserSys(TCppWebBrowser *wb, TPopupMenu *popupmenu) {
	this->wb = wb;
	wb->Silent = true;
	wb->Navigate(WideString("about:blank").c_bstr());
	while (wb->ReadyState < ::READYSTATE_INTERACTIVE)
		Application->ProcessMessages();
	wb->Offline = true;
	Editor = NULL;
	dochandler = new MyDocHandler(popupmenu);
}

BrowserSys::~BrowserSys() {
	if (Editor) {
		Editor->Release();
		dochandler->Release();
		delete dochandler;
	}
}

bool BrowserSys::InitInterfaces() {
	HRESULT hr;
	ICustomDoc *custdoc;

	hr = wb->Document->QueryInterface(IID_IHTMLDocument2, (void**)&Editor);
	if (SUCCEEDED(hr)) {
		Editor->Release();

		wb->Document->QueryInterface(&custdoc);
		if (custdoc)
			custdoc->SetUIHandler(dochandler);
		return true;
	}
	else
		return false;
}

void BrowserSys::EditMode(bool on) {
	if (on)
		Editor->put_designMode(L"On");
	else
		Editor->put_designMode(L"Off");
}

bool BrowserSys::CanCopy() {
	return wb->QueryStatusWB(Shdocvw::OLECMDID_COPY) != 1;
}

bool BrowserSys::CanPaste() {
	return wb->QueryStatusWB(Shdocvw::OLECMDID_PASTE) != 1;
}

bool BrowserSys::CanCut() {
	return wb->QueryStatusWB(Shdocvw::OLECMDID_CUT) != 1;
}

IHTMLTxtRange* BrowserSys::TxtRange() {
	IHTMLSelectionObject *sel;
	BSTR SelType;
	HRESULT hr;
	IDispatch *disp;
	IHTMLTxtRange *txtrange;

	Editor->get_selection(&sel);
	sel->get_type(&SelType);
	if (String(SelType) != "Control") {
		hr = sel->createRange(&disp);
		if (SUCCEEDED(hr)) {
			disp->QueryInterface(IID_IHTMLTxtRange, (void**)&txtrange);
			return txtrange;
		}
	}
	return NULL;
}

void BrowserSys::Bold() {
	TxtRange()->execCommand(L"bold", false, var, &rec);
}

void BrowserSys::Italic() {
	TxtRange()->execCommand(L"italic", false, var, &rec);
}

void BrowserSys::UnderLine() {
	TxtRange()->execCommand(L"underline", false, var, &rec);
}

void BrowserSys::Paste() {
	wb->ExecWB(Shdocvw::OLECMDID_PASTE, Shdocvw::OLECMDEXECOPT_DONTPROMPTUSER);
}

void BrowserSys::Copy() {
	wb->ExecWB(Shdocvw::OLECMDID_COPY, Shdocvw::OLECMDEXECOPT_DONTPROMPTUSER);
}

void BrowserSys::Cut() {
	wb->ExecWB(Shdocvw::OLECMDID_CUT, Shdocvw::OLECMDEXECOPT_DONTPROMPTUSER);
}

void BrowserSys::InsertList() {
	TxtRange()->execCommand(L"InsertUnorderedList", false, var, &rec);
}

void BrowserSys::HyperLink() {
	TxtRange()->execCommand(L"CreateLink", true, var, &rec);
}

void BrowserSys::InsertImage() {
	TxtRange()->execCommand(L"InsertImage", true, var, &rec);
}

void BrowserSys::Undo() {
	wb->ExecWB(Shdocvw::OLECMDID_UNDO, Shdocvw::OLECMDEXECOPT_DONTPROMPTUSER);
}

void BrowserSys::Redo() {
	wb->ExecWB(Shdocvw::OLECMDID_REDO, Shdocvw::OLECMDEXECOPT_DONTPROMPTUSER);
}

bool BrowserSys::CanUndo() {
	return wb->QueryStatusWB(Shdocvw::OLECMDID_UNDO) > 1;
}

bool BrowserSys::CanRedo() {
	return wb->QueryStatusWB(Shdocvw::OLECMDID_REDO) > 1;
}

void BrowserSys::SetSize(int size) {
	Variant V;
	if (size > 7 || size < 1)
		V = "error";
	else
		V = IntToStr(size);
	TxtRange()->execCommand(L"FontSize", false, V, &rec);
}

void BrowserSys::SetFont(const String &font) {
	Variant V = font;
	TxtRange()->execCommand(L"FontName", false, V, &rec);
}

void BrowserSys::SetColor(int color) {
	Variant V = HtmlColor(color);
	TxtRange()->execCommand(L"ForeColor", false, V, &rec);
}

const String BrowserSys::HtmlColor(int color) {
	String s;
	TColor col;
	col = static_cast<TColor>(color);
	s.sprintf(L"#%.2X%.2X%.2X", GetRValue(col), GetGValue(col), GetBValue(col));
	return s;
}

int BrowserSys::GetSize(IHTMLTxtRange* TextRange) {
	OleVariant v;
	int size;
	HRESULT hr;
	if (TextRange) {
		hr = TextRange->queryCommandValue(L"FontSize", (tagVARIANT*)v);
		if (SUCCEEDED(hr)) {
			if (!v.IsNull())
				size = v.intVal;
			if (size <= 7 && size >= 0)
				return size;
		}
	}

	return 0;
}

String BrowserSys::GetFont(IHTMLTxtRange* TextRange) {
	OleVariant v;
	HRESULT hr;
	if (TextRange) {
		hr = TextRange->queryCommandValue(L"FontName", (tagVARIANT*)v);
		if (SUCCEEDED(hr)) {
			if (!v.IsNull())
				return v.bstrVal;

		}
	}

	return NULL;
}

int BrowserSys::GetColor(IHTMLTxtRange* TextRange) {
	OleVariant v;
	HRESULT hr;
	if (TextRange) {
		hr = TextRange->queryCommandValue(L"ForeColor", (tagVARIANT*)v);
		if (SUCCEEDED(hr)) {
			if (!v.IsNull())
				return v.intVal;

		}
	}

	return 0;
}

bool BrowserSys::isItalic(IHTMLTxtRange *TextRange) {
	HRESULT hr;
	short sh;
	if (TextRange) {
		hr = TextRange->queryCommandState(L"Italic", &sh);
		if (sh)
			return true;
	}
	return false;
}

bool BrowserSys::isBold(IHTMLTxtRange *TextRange) {
	short sh;
	if (TextRange) {
		TextRange->queryCommandState(L"Bold", &sh);
		if (sh)
			return true;
	}
	return false;
}

bool BrowserSys::isUnderline(IHTMLTxtRange *TextRange) {
	short sh;
	if (TextRange) {
		TextRange->queryCommandState(L"Underline", &sh);
		if (sh)
			return true;
	}
	return false;
}

void BrowserSys::SetStyle(Style *style) {
	SetSize(style->getsize());
	SetColor(style->getcolor());
	SetFont(style->getface());
	int k = style->getfontstyle();
	if (isBold(TxtRange())) {
		Bold();
	}
	if (isItalic(TxtRange())) {
		Italic();
	}
	if (isUnderline(TxtRange())) {
		UnderLine();
	}
	if ((k & fsBOLD) == fsBOLD)
		this->Bold();
	if ((k & fsITALIC) == fsITALIC)
		this->Italic();
	if ((k & fsUNDERLINE) == fsUNDERLINE)
		this->UnderLine();
}

String BrowserSys::GetText() {
	IHTMLElement* pElement;
	HRESULT hr;
	BSTR s;
	if (!Editor) {
        return NULL;
	}
	if (FAILED(Editor->get_body(&pElement)))
		return NULL;
	if (FAILED(pElement->get_parentElement(&pElement)))
		return NULL;
	pElement->get_outerHTML(&s);
	pElement->Release();
	return String(s);
}

void BrowserSys::SetText(String s) {
	IHTMLElement* pElement;
	if (!Editor)
		return;
	if (FAILED(Editor->get_body(&pElement)))
		return;
	pElement->put_innerHTML(s.c_str());
	pElement->Release();
}

void BrowserSys::OpenFile(String filename) {
	try
	{
	wb->Navigate(filename.c_str());
	}
	catch (...)
	{}
	while (wb->ReadyState < ::READYSTATE_INTERACTIVE)
		Application->ProcessMessages();
}
