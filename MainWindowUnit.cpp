//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainWindowUnit.h"
#include "About.h"
#include "BrowserSys.h"
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
	HRESULT hr;
	hr = WebBrowser1->Document->QueryInterface(IID_IHTMLDocument2,(void**)&Editor);
	if(SUCCEEDED(hr))
	{
		Editor->put_designMode(L"On");
		Editor->Release();            //Release the object

	}
	else
		Editor = NULL;



}
//---------------------------------------------------------------------------


void __fastcall TForm1::DOM1Click(TObject *Sender)
{
DOM1->Checked = ! DOM1->Checked;
TreeView1->Visible = DOM1->Checked;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ToolButton1Click(TObject *Sender)
{
 IHTMLDocument2*   doc;
	HRESULT   hr   =   WebBrowser1->Document->QueryInterface(IID_IHTMLDocument2,(void**)&doc);

	if(hr   ==   S_OK)
	{
		  VARIANT   var;
		  VARIANT_BOOL         receive;
		  doc->execCommand(L"InsertImage",true,var, &receive);
		  doc->Release();
	}
}
//---------------------------------------------------------------------------








//---------------------------------------------------------------------------



void __fastcall TForm1::ToolButton2Click(TObject *Sender)
{
//RichEdit1->Text  = doc->GetHTML();
Editor->put_designMode(L"Off");
}
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

