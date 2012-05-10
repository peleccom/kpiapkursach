//---------------------------------------------------------------------------

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
std::vector<TForm1 *> TForm1::forms;

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
if (RichEdit1->Lines->Text != doc->GetHTML()) {
	doc->setchanged(true);
	doc->html = RichEdit1->Lines->Text;
}
if (RichEdit1->Focused()) {
	doc->Update(RichEdit1->Lines->Text);
}



}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
browser = new BrowserSys(WebBrowser1);
doc= new HTMLDocument(RichEdit1, WebBrowser1);
doc->setchanged(false);
FormTitle = "Редактор HTML - " ;
forms.push_back(this);
defaultstyles = new StylesCollection;
styles = new StylesCollection;
styles->LoadFromFile("styles.dat");
curstyle = new Style;
Style *st;
st = new Style(0,clBlack,0,"",fsNONE,L"Текущий стиль");
*curstyle =*st;
defaultstyles->AddStyle(st);
delete st;
st = new Style(7,clRed,0,"",fsBOLD,L"Заголовок");
defaultstyles->AddStyle(st);
delete st;
st = new Style(1,clBlack,0,"",fsNONE,L"Маленький");
defaultstyles->AddStyle(st);
delete st;
st = new Style(7,clBlack,0,"",fsNONE,L"Огромный");
defaultstyles->AddStyle(st);
delete st;
st = new Style(0,clBlue,0,"",fsUNDERLINE,L"Ссылка");
defaultstyles->AddStyle(st);
delete st;
defaultstyles->FillComboBox(cbStyle);
styles->FillComboBox(cbStyle);
cbStyle->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
delete doc;
delete browser;
styles->SaveToFile("styles.dat");
delete styles;
delete defaultstyles;
delete curstyle;
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
String stylename;
int index =cbStyle->ItemIndex;
stylename = cbStyle->Items->Strings[index];
if (stylename[1] == '@'){
	styles->DeleteStyle(stylename);
	cbStyle->Clear();
defaultstyles->FillComboBox(cbStyle);
styles->FillComboBox(cbStyle);
cbStyle->ItemIndex = 0;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::acSaveUserStyleExecute(TObject *Sender)
{
//
String stylename;
stylename = InputBox(L"Выберите имя для нового стиля",L"Имя стиля",L"Новый стиль");
Style *style = new Style;
*style = *curstyle;
style->setstylename("@"+stylename);
styles->AddStyle(style);
cbStyle->Clear();
defaultstyles->FillComboBox(cbStyle);
styles->FillComboBox(cbStyle);
cbStyle->ItemIndex = cbStyle->Items->Count -1;

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
	if (RichEdit1->Focused())
		RichEdit1->CopyToClipboard();
	else
		browser->Copy();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::acPasteExecute(TObject *Sender)
{
	if (RichEdit1->Focused())
		RichEdit1->PasteFromClipboard();
	else
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
	if (RichEdit1->Focused())
		RichEdit1->CutToClipboard();
	else
		browser->Cut();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::acInsertImageExecute(TObject *Sender)
{
	browser->InsertImage();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::tmUpdaterTimer(TObject *Sender)
{
	bool is_txt =  Assigned(browser->TxtRange());
	acBold->Enabled = is_txt;
	acItalics->Enabled = is_txt;
	acUnderline->Enabled = is_txt;
	acInsertHyperlink->Enabled = is_txt;
	acInsertImage->Enabled = is_txt;
	acInsertList->Enabled = is_txt;
	acUndo->Enabled  = browser->CanUndo();
	acRedo->Enabled = browser->CanRedo();
	acCut->Enabled = browser->CanCut();
	acCopy->Enabled = browser->CanCopy();
	acPaste->Enabled = browser->CanPaste();


	if (!RichEdit1->Focused()) {
		RichEdit1->Text = browser->GetText();
		//WebBrowser1->SetFocus();
	}
	if (this->Visible) {
	IHTMLTxtRange *range = browser->TxtRange();
	if (range != NULL) {
	acBold->Checked =browser->isBold(range);
	acItalics->Checked =browser->isItalic(range);
	acUnderline->Checked =browser->isUnderline(range);
	}}
	// exper

	}
//---------------------------------------------------------------------------


void __fastcall TForm1::acExitExecute(TObject *Sender)
{
std::vector<TForm1 *>::reverse_iterator i;
for (i = forms.rbegin(); i != forms.rend(); i++)
	(*i)->Close();
}
//---------------------------------------------------------------------------





void __fastcall TForm1::acUndoExecute(TObject *Sender)
{
	browser->Undo();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::acRedoExecute(TObject *Sender)
{
	browser->Redo();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::bTextColorClick(TObject *Sender)
{
	curstyle->setcolor(ColorToRGB(bTextColor->SymbolColor));
	cbStyle->ItemIndex = 0;
	browser->SetColor(ColorToRGB(bTextColor->SymbolColor));
}
//---------------------------------------------------------------------------




void __fastcall TForm1::cbTextSizeSelect(TObject *Sender)
{
	int size = cbTextSize->ItemIndex;
	cbStyle->ItemIndex = 0;
	curstyle->setsize(size);
	browser->SetSize(size);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cbTextFontClick(TObject *Sender)
{
	curstyle->setface(cbTextFont->Text);
	cbStyle->ItemIndex = 0;
	browser->SetFont(cbTextFont->Text);
}
//---------------------------------------------------------------------------
 /*
HRESULT TEventMethod::Invoke(
  DISPID dispIdMember,
  REFIID riid,
  LCID lcid,
  WORD wFlags,
  DISPPARAMS FAR* pDispParams,
  VARIANT FAR* pVarResult,
  EXCEPINFO FAR* pExcepInfo,
  unsigned int FAR* puArgErr
)
{
 ShowMessage("Hello");
 return 0;
}  */




void TForm1::SetStyleFromUI(Style *style){
	style->setsize(cbTextSize->ItemIndex);
	style->setface(cbTextFont->Text);
	style->setpar(cbParFormat->ItemIndex);
	style->setcolor(ColorToRGB(bTextColor->SymbolColor));
	int fontstyle = fsNONE;
	if (acBold->Checked) fontstyle += fsBOLD;
	if (acItalics->Checked) fontstyle += fsITALIC;
	if (acUnderline->Checked) fontstyle += fsUNDERLINE;
	style->setfontstyle(fontstyle);
}

void TForm1::SetStyleToUI(Style *style){
	cbTextSize->ItemIndex = style->getsize();
	cbTextFont->Text = style->getface();
	bTextColor->SymbolColor = style->getcolor();
	//cbParFormat->ItemIndex = style-getpar();
	int fontstyle = style->getfontstyle();
	acBold->Checked = ((fontstyle & fsBOLD) == fsBOLD);
	acItalics->Checked = ((fontstyle & fsITALIC) == fsITALIC);
	acUnderline->Checked = ((fontstyle & fsUNDERLINE) == fsUNDERLINE);
}



void __fastcall TForm1::cbStyleSelect(TObject *Sender)
{
	int index = 	cbStyle->ItemIndex;
	Style *style = (Style*)cbStyle->Items->Objects[index];
	*curstyle = *style;
	browser->SetStyle(style);
	SetStyleToUI(style);
}
//---------------------------------------------------------------------------




void __fastcall TForm1::WebBrowser1DocumentComplete(TObject *Sender, LPDISPATCH pDisp,
          Variant *URL)
{
	//browser.InitInterfaces();
	HRESULT hr;
	if (browser->InitInterfaces())
		browser->EditMode(true);
	tmUpdater->Enabled = true;
	tmUpdater->OnTimer(Sender);

}
//---------------------------------------------------------------------------



