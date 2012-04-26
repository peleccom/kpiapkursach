//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <mshtml.h>
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
//
ShowMessage("Закрывает все активные окна");
}
//---------------------------------------------------------------------------


void __fastcall TForm1::RichEdit1Change(TObject *Sender)
{
 doc->Update(RichEdit1->Lines->Text);


}
//---------------------------------------------------------------------------

void __fastcall TForm1::NOpenDocumentClick(TObject *Sender)
{
if (OpenDocumentDialog->Execute())
	{
		doc->OpenFile(OpenDocumentDialog->FileName);
		this->Caption = FormTitle + ExtractFileName(OpenDocumentDialog->FileName);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
doc= new HTMLDocument(RichEdit1, WebBrowser1);
FormTitle = "Редактор HTML - " ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
delete doc;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::NSaveDocumentClick(TObject *Sender)
{
if (SaveDocumentDialog->Execute())
	{
		doc->SaveFile(SaveDocumentDialog->FileName);
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::NCloseDocumentClick(TObject *Sender)
{
	Close();
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
				NSaveDocumentClick(Sender);
			}
		}
	}
	else
	CanClose = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N4Click(TObject *Sender)
{
 //TO DO check if document opened
	TForm1 *form = new TForm1(Application);
	form->Caption = FormTitle+L"Безымянный";
	form->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
  Action = caFree; // необходима для автоуничтожения формы при закрытии
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
ShowMessage(L"Выполнили действие с выделенным текстом..");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::WebBrowser1DownloadComplete(TObject *Sender)
{
	IHTMLDocument2* doc;    //This interface is defined in mshtml.h

	HRESULT hr;
	hr = WebBrowser1->Document->QueryInterface(IID_IHTMLDocument2,(void**)&doc);
	if(SUCCEEDED(hr))
	{
		doc->put_designMode(L"On");
		doc->Release();            //Release the object

	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::DOM1Click(TObject *Sender)
{
DOM1->Checked = ! DOM1->Checked;
TreeView1->Visible = DOM1->Checked;
}
//---------------------------------------------------------------------------

