﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainWindowUnit.h"
#include "About.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma link "frxCtrls"
#pragma resource "*.dfm"
TForm1 *Form1;


void OnKeyPress(DISPID id, VARIANT* pVarResult)
{
}

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


void __fastcall TForm1::RichEdit1Change(TObject *Sender)
{
 doc->Update(RichEdit1->Lines->Text);


}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
browser = new BrowserSys(WebBrowser1);
doc= new HTMLDocument(RichEdit1, WebBrowser1);
FormTitle = "Редактор HTML - " ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
delete doc;
delete browser;
}
//---------------------------------------------------------------------------







void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if (doc->changed()) {
		int qresult;
		qresult = MessageDlg("Сохранить текущий документ перед закрытием", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo << mbCancel,0);
		if (qresult == mrNo)
			CanClose = true;
		else
		{
			CanClose = false;
			if (qresult == mrYes) {
				acSaveFile->Execute();
			}
		}
	}
	else
	CanClose = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
  Action = caFree; // необходима для автоуничтожения формы при закрытии
}
//---------------------------------------------------------------------------


void __fastcall TForm1::WebBrowser1DownloadComplete(TObject *Sender)
{
	//browser.InitInterfaces();
	HRESULT hr;
	if (browser->InitInterfaces())
		browser->EditMode(true);

}
//---------------------------------------------------------------------------


void __fastcall TForm1::DOM1Click(TObject *Sender)
{
DOM1->Checked = ! DOM1->Checked;
TreeView1->Visible = DOM1->Checked;
}
//---------------------------------------------------------------------------










//---------------------------------------------------------------------------








void __fastcall TForm1::acOpenFileExecute(TObject *Sender)
{
if (OpenDocumentDialog->Execute())
	{
		doc->OpenFile(OpenDocumentDialog->FileName);
		this->Caption = FormTitle + ExtractFileName(OpenDocumentDialog->FileName);
	}
}
//---------------------------------------------------------------------------












void __fastcall TForm1::acEditStyleExecute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TForm1::acDeleteStyleExecute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TForm1::acSaveUserStyleExecute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TForm1::acCloseExecute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::acSaveFileExecute(TObject *Sender)
{
	if (doc->FileName == "")
	{
		SaveDocumentDialog->FileName = L"Безымянный";
		if (SaveDocumentDialog->Execute())
		{
			doc->FileName = SaveDocumentDialog->FileName;
		}
		else
			return;
	}
	doc->SaveFile(doc->FileName);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::acNewPageExecute(TObject *Sender)
{
 //TO DO check if document opened
	TForm1 *form = new TForm1(Application);
	form->Caption = FormTitle+L"Безымянный";
	form->Show();
}
//---------------------------------------------------------------------------






void __fastcall TForm1::acBoldExecute(TObject *Sender)
{
	browser->Bold();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::acItalicsExecute(TObject *Sender)
{
	browser->Italic();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::acUnderlineExecute(TObject *Sender)
{
	browser->UnderLine();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::acCopyExecute(TObject *Sender)
{
	browser->Copy();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::acPasteExecute(TObject *Sender)
{
	browser->Paste();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::acInsertListExecute(TObject *Sender)
{
	browser->InsertList();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::acInsertHyperlinkExecute(TObject *Sender)
{
	browser->HyperLink();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::acSaveFileAsExecute(TObject *Sender)
{
	SaveDocumentDialog->FileName = ExtractFileName(doc->FileName);
	SaveDocumentDialog->InitialDir = ExtractFileDir(doc->FileName);
	if (SaveDocumentDialog->Execute())
	{
		doc->FileName = SaveDocumentDialog->FileName;
	}
	else
		return;
	doc->SaveFile(doc->FileName);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::acCutExecute(TObject *Sender)
{
	browser->Cut();
}
//---------------------------------------------------------------------------

