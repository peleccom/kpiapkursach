//---------------------------------------------------------------------------

#pragma hdrstop
 #include <fstream.h>
#include "myutils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include "mshtml.h"
void HTMLDocument::OpenFile(String filename)
{
	infilename = filename;
	LoadContent();
}

void HTMLDocument::LoadContent()
{
Form1->RichEdit1->Lines->Clear();
Form1->RichEdit1->Lines->LoadFromFile(infilename);
}



void LoadHtmlFromString(TCppWebBrowser *pCppWebBrowser,
 String &str)
 {
IHTMLDocument2* pHTMLDocument;
   IHTMLElement* pElement;
   pCppWebBrowser->Silent = true;
   pCppWebBrowser->Navigate(WideString("about:blank").c_bstr());
   while (pCppWebBrowser->ReadyState < ::READYSTATE_INTERACTIVE)
	   Application->ProcessMessages();
   if (FAILED(pCppWebBrowser->Document->QueryInterface(IID_IHTMLDocument2, (LPVOID*) &pHTMLDocument))) return;
   if (FAILED(pHTMLDocument->get_body(&pElement))) return;
   pElement->put_innerHTML(str.c_str());
   pElement->Release();
   pHTMLDocument->Release();
 }

void HTMLDocument::ShowContent(TCppWebBrowser *wb, String HTMLCode)
{
	LoadHtmlFromString(wb, HTMLCode) ;

}
void HTMLDocument::SaveFile(String filename)
{
	Form1->RichEdit1->Lines->SaveToFile(filename);
}


/*TStringList *ss = new TStringList;
ss->Text = Form1->RichEdit1->Text;
ss->SaveToFile(filename);
//Form1->RichEdit1->Lines->SaveToFile("C:\\tmp\\1.html");
Form1->WebBrowser1->Navigate(filename); /*
}5 */

