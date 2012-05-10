//---------------------------------------------------------------------------

#pragma hdrstop
 #include <fstream.h>
#include "myutils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include "mshtml.h"
void HTMLDocument::OpenFile(const String &filename)
{
	FileName = filename;
	wb->Navigate(filename.c_str());
	while (wb->ReadyState < ::READYSTATE_INTERACTIVE)
		Application->ProcessMessages();
	rcedit->Lines->Clear();
	rcedit->Lines->LoadFromFile(FileName);
	_changed = false;
	wb->Silent = true;
}

void LoadHtmlFromString(TCppWebBrowser *pCppWebBrowser,
 const String &str)
 {
IHTMLDocument2* pHTMLDocument;
   IHTMLElement* pElement;
   if (FAILED(pCppWebBrowser->Document->QueryInterface(IID_IHTMLDocument2, (void **) &pHTMLDocument))) return;
   if (FAILED(pHTMLDocument->get_body(&pElement))) return;
   pElement->put_innerHTML(str.c_str());
   pElement->Release();
   pHTMLDocument->Release();
 }

String WebBrowserToString(TCppWebBrowser *pCppWebBrowser)
{
	IHTMLDocument2* pHTMLDocument;
   IHTMLElement* pElement;
   BSTR s;
   if (FAILED(pCppWebBrowser->Document->QueryInterface(IID_IHTMLDocument2, (void **) &pHTMLDocument))) return NULL;
   if (FAILED(pHTMLDocument->get_body(&pElement))) return NULL;
   pElement->get_innerHTML(&s);
   pElement->Release();
   pHTMLDocument->Release();
   return String(s);
}

void HTMLDocument::Update(const String &html){
	this->html = html;
	_changed = true;
	wb->Silent = true;
	LoadHtmlFromString(wb, html) ;
}

void HTMLDocument::SaveFile(const String &filename)
{	TStringList *sl = new TStringList;
	sl->Text = rcedit->Text;
	sl->SaveToFile(filename);
	delete sl;
	_changed = false;
}

bool HTMLDocument::changed(){
	return _changed;
}

HTMLDocument::HTMLDocument(TRichEdit *rche, TCppWebBrowser *wbrowser):
												rcedit(rche),wb(wbrowser)
{
	String s;
	wb->Silent = true;
	wb->Navigate(WideString("about:blank").c_bstr());
	while (wb->ReadyState < ::READYSTATE_INTERACTIVE)
		Application->ProcessMessages();
	wb->Offline = true;
};

String HTMLDocument::GetHTML(){
  return WebBrowserToString(wb);
}


bool Assigned(void *p){
if (p == NULL)
	return false;
else
	return true;
}


void HTMLDocument::setchanged(bool flag){
	_changed = flag;
}
