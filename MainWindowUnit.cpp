//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainWindowUnit.h"
#include "About.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AboutActionClick(TObject *Sender)
{
AboutBox->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::NCloseClick(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::RichEdit1Change(TObject *Sender)
{
 doc->ShowContent(Form1->WebBrowser1,Form1->RichEdit1->Lines->Text);


}
//---------------------------------------------------------------------------










void __fastcall TForm1::NOpenDocumentClick(TObject *Sender)
{
if (OpenDocumentDialog->Execute())
	{
		doc->OpenFile(OpenDocumentDialog->FileName);
		doc->ShowContent(Form1->WebBrowser1,Form1->RichEdit1->Lines->Text);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
doc= new HTMLDocument();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
delete doc;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::NSaveDocumentClick(TObject *Sender)
{
if (OpenDocumentDialog->Execute())
	{
		doc->SaveFile(SaveDocumentDialog->FileName);
	}
}
//---------------------------------------------------------------------------


