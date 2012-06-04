// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DocumentFormUnit.h"
#include "MainWindowUnit.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"
TDocumentForm *DocumentForm;

// ---------------------------------------------------------------------------
__fastcall TDocumentForm::TDocumentForm(TComponent* Owner) : TForm(Owner) {
}

// Обновление документа при обновлениии содержимого в RichEdit------------------
void __fastcall TDocumentForm::RichEdit1Change(TObject *Sender) {
	if (RichEdit1->Lines->Text != doc->html) {
		if (updatetimes > 1)
			doc->setchanged(true);
		else
			updatetimes++;
		doc->html = RichEdit1->Lines->Text;
	}
	if (RichEdit1->Focused()) {
		doc->Update(RichEdit1->Lines->Text);
	}

}

// ---------------------------------------------------------------------------
void __fastcall TDocumentForm::FormCreate(TObject *Sender) {
	RichEdit1->PopupMenu = static_cast<TForm1*>(Application->MainForm)
		->PopupMenu1;
	browser = new BrowserSys(WebBrowser1, RichEdit1->PopupMenu);
	doc = new HTMLDocument(RichEdit1, browser);
	doc->setchanged(false);
	updatetimes = 0;
}
// ---------------------------------------------------------------------------

void __fastcall TDocumentForm::FormDestroy(TObject *Sender) {

	delete doc;
	delete browser;
}

// Запрос на закрытие формы документа-------------------------------------------
void __fastcall TDocumentForm::FormCloseQuery(TObject *Sender, bool &CanClose) {
	if (doc->changed()) {
		int qresult;
		qresult = MessageDlg("Сохранить текущий документ [" + Caption +
			"] перед закрытием", mtConfirmation,
			TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0);
		if (qresult == mrNo)
			CanClose = true;
		else {
			CanClose = false;
			if (qresult == mrYes) {
				TForm1 *form = (TForm1*)(Application->MainForm);
				this->Activate();
				form->acSaveFile->Execute();
			}
		}
	}
	else
		CanClose = true;
	if (CanClose) {
        doc->setchanged(false);
	}
}

// Инициализация интерфейсов TWebBrowser----------------------------------------
void __fastcall TDocumentForm::WebBrowser1DocumentComplete(TObject *Sender,
	LPDISPATCH pDisp, Variant *URL) {
	if (browser->InitInterfaces())
		browser->EditMode(true);

}
// ---------------------------------------------------------------------------

void __fastcall TDocumentForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree; // необходимо для автоуничтожения формы при закрытии
}
// ---------------------------------------------------------------------------
