                                                                              //---------------------------------------------------------------------------

#pragma hdrstop
 #include <fstream.h>
#include "HTMLDocument.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
void HTMLDocument::OpenFile(const String &filename)
{
	TStringList *sl = new TStringList;
	FileName = filename;
	sl->LoadFromFile(filename);
	browser->OpenFile(filename);
	rcedit->Lines->Clear();
	html = sl->Text;
	rcedit->Text = html;
	setchanged(false);
	delete sl;
}


void HTMLDocument::Update(const String &html){
	this->html = html;
	setchanged(true);
	browser->SetText(html);
}

void HTMLDocument::SaveFile(const String &filename)
{	TStringList *sl = new TStringList;
	sl->Text = html;
	sl->SaveToFile(filename);
	delete sl;
	setchanged(false);
}

bool HTMLDocument::changed(){
	return _changed;
}

HTMLDocument::HTMLDocument(TRichEdit *rche, BrowserSys *Browser):
												rcedit(rche),browser(Browser)
{
};

void HTMLDocument::setchanged(bool flag){
	_changed = flag;
}
