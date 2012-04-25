//---------------------------------------------------------------------------

#ifndef MainWindowUnitH
#define MainWindowUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <SHDocVw.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.OleCtrls.hpp>
#include "SHDocVw_OCX.h"
#include <DomTreeUnit.h>
#include <Vcl.Dialogs.hpp>
#include "myutils.h"
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class HTMLDocument;
//-------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *NClose;
	TMenuItem *NOpenDocument;
	TMenuItem *AboutAction;
	TMenuItem *NSaveDocument;
	TMenuItem *N9;
	TMenuItem *N10;
	TControlBar *ControlBar1;
	TRichEdit *RichEdit1;
	TSplitter *Splitter1;
	TTreeView *TreeView1;
	TOpenDialog *OpenDocumentDialog;
	TSaveDialog *SaveDocumentDialog;
	TCppWebBrowser *WebBrowser1;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *NCloseDocument;
	TMenuItem *N7;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	void __fastcall AboutActionClick(TObject *Sender);
	void __fastcall NCloseClick(TObject *Sender);
	void __fastcall RichEdit1Change(TObject *Sender);
	void __fastcall NOpenDocumentClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall NSaveDocumentClick(TObject *Sender);
	void __fastcall NCloseDocumentClick(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private:	// User declarations
HTMLDocument *doc;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
