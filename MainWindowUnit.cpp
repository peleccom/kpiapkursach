// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainWindowUnit.h"
#include "About.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma link "frxCtrls"
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}
// ---------------Показать форму "О программе"---------------------------------------------------
void __fastcall TForm1::AboutActionClick(TObject *Sender) {
	AboutBox->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender) {
	defaultstyles = new StylesCollection; // создаем коллекцию стандартных и пользовательскиъх стилей
	styles = new StylesCollection;
	styles->LoadFromFile("styles.dat");
	curstyle = new Style;
	Style *st;
	st = new Style(0, clBlack, "", fsNONE, L"Текущий стиль");
	*curstyle = *st;
	defaultstyles->AddStyle(st);
	delete st;
	st = new Style(0, clBlack, "", fsNONE, L"Стандартный");
	defaultstyles->AddStyle(st);
	delete st;
	st = new Style(7, clRed, "", fsBOLD, L"Заголовок");
	defaultstyles->AddStyle(st);
	delete st;
	st = new Style(1, clBlack, "", fsNONE, L"Маленький");
	defaultstyles->AddStyle(st);
	delete st;
	st = new Style(7, clBlack, "", fsNONE, L"Огромный");
	defaultstyles->AddStyle(st);
	delete st;
	st = new Style(0, clBlue, "", fsUNDERLINE, L"Ссылка");
	defaultstyles->AddStyle(st);
	delete st;
	defaultstyles->FillComboBox(cbStyle);
	styles->FillComboBox(cbStyle);
	cbStyle->ItemIndex = 0;
	cbTextFont->ItemIndex = -1;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender) {
							   // сохранить пользовательские стили при закрытии
	styles->SaveToFile("styles.dat");
	delete styles;
	delete defaultstyles;
	delete curstyle;
}

// Выбор имени файла для открытия и окрытие файла-----------------------------------------------
void __fastcall TForm1::acOpenFileExecute(TObject *Sender) {
	if (OpenDocumentDialog->Execute()) {
		acNewPage->Execute();
		TDocumentForm *form = (TDocumentForm*)this->ActiveMDIChild;
		if (!form)
			return;
		form->doc->OpenFile(OpenDocumentDialog->FileName);
		form->Caption = ExtractFileName(OpenDocumentDialog->FileName);
	}
}
// ---------------------------------------------------------------------------

// Удаление выбранного стиля ---------------------------------------------------
void __fastcall TForm1::acDeleteStyleExecute(TObject *Sender) {
	String stylename;
	int index = cbStyle->ItemIndex;
	stylename = cbStyle->Items->Strings[index];
	if (stylename[1] == '@') {
		styles->DeleteStyle(stylename);
		cbStyle->Clear();
		defaultstyles->FillComboBox(cbStyle);
		styles->FillComboBox(cbStyle);
		cbStyle->ItemIndex = 0;
	}
	else
		ShowMessage(L"Нельзя удалить стандартный стиль");

}

//Создание нового стиля---------------------------------------------------------
void __fastcall TForm1::acSaveUserStyleExecute(TObject *Sender) {
	//
	String stylename;
	stylename = InputBox(L"Выберите имя для нового стиля", L"Имя стиля",
		L"Новый стиль");
	Style *style = new Style;
	*style = *curstyle;
	style->setstylename("@" + stylename);
	styles->AddStyle(style);
	cbStyle->Clear();
	defaultstyles->FillComboBox(cbStyle);
	styles->FillComboBox(cbStyle);
	cbStyle->ItemIndex = cbStyle->Items->Count - 1;

}

//закрыть текущую дочернюю форму------------------------------------------------
void __fastcall TForm1::acCloseExecute(TObject *Sender) {
	TDocumentForm *form = (TDocumentForm*)this->ActiveMDIChild;
	if (!form)
		return;
	form->Close();
}

// Выбор имени файла для сохранения и сохранение--------------------------------
void __fastcall TForm1::acSaveFileExecute(TObject *Sender) {
	TDocumentForm *form = (TDocumentForm*)this->ActiveMDIChild;
	if (!form)
		return;
	if (form->doc->FileName == "") {
		SaveDocumentDialog->FileName = form->Caption;
		if (SaveDocumentDialog->Execute()) {
			form->doc->FileName = SaveDocumentDialog->FileName;
			form->Caption = SaveDocumentDialog->FileName;
		}
		else
			return;
	}
	form->doc->SaveFile(form->doc->FileName);
}

// Новый документ---------------------------------------------------------------
void __fastcall TForm1::acNewPageExecute(TObject *Sender) {
	// TO DO check if document opened
	TDocumentForm *form = new TDocumentForm(Application);
	if (!form)
		return;
	form->Caption = "Безымянный " + IntToStr(MDIChildCount);
	form->Show();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::acBoldExecute(TObject *Sender) {
	TDocumentForm *form = (TDocumentForm*)this->ActiveMDIChild;
	if (!form)
		return;
	form->browser->Bold();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::acItalicsExecute(TObject *Sender) {
	TDocumentForm *form = (TDocumentForm*)this->ActiveMDIChild;
	if (!form)
		return;
	form->browser->Italic();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::acUnderlineExecute(TObject *Sender) {
	TDocumentForm *form = (TDocumentForm*)this->ActiveMDIChild;
	if (!form)
		return;
	form->browser->UnderLine();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::acCopyExecute(TObject *Sender) {
	TDocumentForm *form = (TDocumentForm*)this->ActiveMDIChild;
	if (!form)
		return;
	if (form->RichEdit1->Focused())
		form->RichEdit1->CopyToClipboard();
	else
		form->browser->Copy();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::acPasteExecute(TObject *Sender) {
	TDocumentForm *form = (TDocumentForm*)this->ActiveMDIChild;
	if (!form)
		return;
	if (form->RichEdit1->Focused())
		form->RichEdit1->PasteFromClipboard();
	else
		form->browser->Paste();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::acInsertListExecute(TObject *Sender) {
	TDocumentForm *form = (TDocumentForm*)this->ActiveMDIChild;
	if (!form)
		return;
	form->browser->InsertList();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::acInsertHyperlinkExecute(TObject *Sender) {

	TDocumentForm *form = (TDocumentForm*)this->ActiveMDIChild;
	if (!form)
		return;
	form->browser->HyperLink();
}

// Нажатие кнопки сохранить как ...---------------------------------------------
void __fastcall TForm1::acSaveFileAsExecute(TObject *Sender) {

	TDocumentForm *form = (TDocumentForm*)this->ActiveMDIChild;
	if (!form)
		return;
	SaveDocumentDialog->FileName = ExtractFileName(form->doc->FileName);
	SaveDocumentDialog->InitialDir = ExtractFileDir(form->doc->FileName);
	if (SaveDocumentDialog->Execute()) {
		form->doc->FileName = SaveDocumentDialog->FileName;
		form->Caption = SaveDocumentDialog->FileName;
	}
	else
		return;
	form->doc->SaveFile(form->doc->FileName);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::acCutExecute(TObject *Sender) {
	TDocumentForm *form = (TDocumentForm*)this->ActiveMDIChild;
	if (!form)
		return;
	if (form->RichEdit1->Focused())
		form->RichEdit1->CutToClipboard();
	else
		form->browser->Cut();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::acInsertImageExecute(TObject *Sender) {
	TDocumentForm *form = (TDocumentForm*)this->ActiveMDIChild;
	if (!form)
		return;
	form->browser->InsertImage();
}

//Переодически вызывается раз в секунду для определения изменений в webbrowser ---------------------------------------------------------------------------
void __fastcall TForm1::tmUpdaterTimer(TObject *Sender) {

	TDocumentForm *form = (TDocumentForm*)this->ActiveMDIChild;
	if (!form) {

		return;
	}

	if (!form->RichEdit1->Focused()) {
		form->RichEdit1->Text = form->browser->GetText();

		bool is_txt = form->browser->TxtRange();
		acBold->Enabled = is_txt;
		acItalics->Enabled = is_txt;
		acUnderline->Enabled = is_txt;
		acInsertHyperlink->Enabled = is_txt;
		acInsertImage->Enabled = is_txt;
		acInsertList->Enabled = is_txt;
		acUndo->Enabled = form->browser->CanUndo();
		acRedo->Enabled = form->browser->CanRedo();
		acCut->Enabled = form->browser->CanCut();
		acCopy->Enabled = form->browser->CanCopy();
		acPaste->Enabled = form->browser->CanPaste();
	}
	else {
		acBold->Enabled = false;
		acItalics->Enabled = false;
		acUnderline->Enabled = false;
		acInsertHyperlink->Enabled = false;
		acInsertImage->Enabled = false;
		acInsertList->Enabled = false;
		acUndo->Enabled = form->RichEdit1->CanUndo;
		acRedo->Enabled = false;
		acCut->Enabled = form->RichEdit1->SelLength > 0;
		acCopy->Enabled = form->RichEdit1->SelLength > 0;
		acPaste->Enabled = form->browser->CanPaste();
	}

	IHTMLTxtRange *range = form->browser->TxtRange();
	if (range != NULL && !form->RichEdit1->Focused()) {
		acBold->Checked = form->browser->isBold(range);
		acItalics->Checked = form->browser->isItalic(range);
		acUnderline->Checked = form->browser->isUnderline(range);
		bTextColor->SymbolColor = form->browser->GetColor(range);
		cbTextFont->Text = form->browser->GetFont(range);
		cbTextSize->ItemIndex = form->browser->GetSize(range);
	}
	// exper
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::acExitExecute(TObject *Sender) {
	int count = MDIChildCount;
	for (int i = count - 1; i >= 0; i--) {
		MDIChildren[i]->Close();
	}
	Close();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::acUndoExecute(TObject *Sender) {
	TDocumentForm *form = (TDocumentForm*)this->ActiveMDIChild;
	if (!form)
		return;
	form->browser->Undo();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::acRedoExecute(TObject *Sender) {
	TDocumentForm *form = (TDocumentForm*)this->ActiveMDIChild;
	if (!form)
		return;
	form->browser->Redo();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::bTextColorClick(TObject *Sender) {
	TDocumentForm *form = (TDocumentForm*)this->ActiveMDIChild;
	if (!form)
		return;
	curstyle->setcolor(ColorToRGB(bTextColor->SymbolColor));
	cbStyle->ItemIndex = 0;
	form->browser->SetColor(ColorToRGB(bTextColor->SymbolColor));
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::cbTextSizeSelect(TObject *Sender) {
	TDocumentForm *form = (TDocumentForm*)this->ActiveMDIChild;
	if (!form)
		return;
	int size = cbTextSize->ItemIndex;
	cbStyle->ItemIndex = 0;
	curstyle->setsize(size);
	form->browser->SetSize(size);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::cbTextFontClick(TObject *Sender) {
	TDocumentForm *form = (TDocumentForm*)this->ActiveMDIChild;
	if (!form)
		return;
	curstyle->setface(cbTextFont->Text);
	cbStyle->ItemIndex = 0;
	form->browser->SetFont(cbTextFont->Text);
}
// Установить текущий стиль---------------------------------------------------------------------------
void TForm1::SetStyleToUI(Style *style) {
	cbTextSize->ItemIndex = style->getsize();
	cbTextFont->Text = style->getface();
	bTextColor->SymbolColor = style->getcolor();
	int fontstyle = style->getfontstyle();
	acBold->Checked = ((fontstyle & fsBOLD) == fsBOLD);
	acItalics->Checked = ((fontstyle & fsITALIC) == fsITALIC);
	acUnderline->Checked = ((fontstyle & fsUNDERLINE) == fsUNDERLINE);
}

void __fastcall TForm1::cbStyleSelect(TObject *Sender) {
	TDocumentForm *form = (TDocumentForm*)this->ActiveMDIChild;
	if (!form)
		return;
	int index = cbStyle->ItemIndex;
	Style *style = (Style*)cbStyle->Items->Objects[index];
	*curstyle = *style;
	SetStyleToUI(style);
	form->browser->SetStyle(style);
	cbStyle->ItemIndex = 0;
}
// ---------------------------------------------------------------------------
