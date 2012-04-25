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
	TMenuItem *N6;
	TMenuItem *N7;
	void __fastcall AboutActionClick(TObject *Sender);
	void __fastcall NCloseClick(TObject *Sender);
	void __fastcall RichEdit1Change(TObject *Sender);
	void __fastcall NOpenDocumentClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall NSaveDocumentClick(TObject *Sender);

private:	// User declarations
HTMLDocument *doc;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
