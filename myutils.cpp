//---------------------------------------------------------------------------

#pragma hdrstop
 #include <fstream.h>
#include "myutils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include "mshtml.h"
void HTMLDocument::OpenFile(const String &filename)
{
	infilename = filename;
	wb->Navigate(filename.c_str());
	while (wb->ReadyState < ::READYSTATE_INTERACTIVE)
		Application->ProcessMessages();
	rcedit->Lines->Clear();
	rcedit->Lines->LoadFromFile(infilename);
	_changed = false;
	wb->Silent = true;
}

void LoadHtmlFromString(TCppWebBrowser *pCppWebBrowser,
 const String &str)
 {
IHTMLDocument2* pHTMLDocument;
   IHTMLElement* pElement;
   if (FAILED(pCppWebBrowser->Document->QueryInterface(IID_IHTMLDocument2, (LPVOID*) &pHTMLDocument))) return;
   if (FAILED(pHTMLDocument->get_body(&pElement))) return;
   pElement->put_innerHTML(str.c_str());
   pElement->Release();
   pHTMLDocument->Release();
 }


void HTMLDocument::Update(const String &html){
	this->html = html;
	_changed = true;
	wb->Silent = true;
	LoadHtmlFromString(wb, html) ;
}





void HTMLDocument::ShowContent(const String &HTMLCode)
{


}
void HTMLDocument::SaveFile(const String &filename)
{
	Form1->RichEdit1->Lines->SaveToFile(filename);
	_changed = false;
}

bool HTMLDocument::changed(){
	return _changed;
}

HTMLDocument::HTMLDocument(TRichEdit *rche, TCppWebBrowser *wbrowser):
												rcedit(rche),wb(wbrowser)
{
	wb->Silent = true;
	wb->Navigate(WideString("about:blank").c_bstr());
	while (wb->ReadyState < ::READYSTATE_INTERACTIVE)
		Application->ProcessMessages();
};
/*TStringList *ss = new TStringList;
ss->Text = Form1->RichEdit1->Text;
ss->SaveToFile(filename);
//Form1->RichEdit1->Lines->SaveToFile("C:\\tmp\\1.html");
Form1->WebBrowser1->Navigate(filename); /*
}5 */

