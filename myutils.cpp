//---------------------------------------------------------------------------

#pragma hdrstop
 #include <fstream.h>
#include "myutils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void HTMLDocument::OpenFile(String filename)
{
	infilename = filename;
}

void HTMLDocument::LoadContent()
{
Form1->RichEdit1->Lines->LoadFromFile(infilename);
}

void HTMLDocument::ShowContent(TWebBrowser *wb, String HTMLCode)
{
TStringList *strlist = new TStringList;
TMemoryStream *memstream = new TMemoryStream;
wb->Navigate("about:blank");
}



/*TStringList *ss = new TStringList;
ss->Text = Form1->RichEdit1->Text;
ss->SaveToFile(filename);
//Form1->RichEdit1->Lines->SaveToFile("C:\\tmp\\1.html");
Form1->WebBrowser1->Navigate(filename); /*
}5 */

