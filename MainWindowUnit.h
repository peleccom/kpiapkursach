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
#include <Vcl.Dialogs.hpp>
#include "myutils.h"
#include <Vcl.Buttons.hpp>
#include <Vcl.ToolWin.hpp>
#include <mshtml.h>
#include <Vcl.ActnList.hpp>
#include <Vcl.ImgList.hpp>
#include "frxCtrls.hpp"
#include <Vcl.Graphics.hpp>
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
	TMenuItem *N6;
	TMenuItem *DOM1;
	TActionList *ActionList1;
	TAction *acOpenFile;
	TAction *acSaveFile;
	TAction *acExit;
	TAction *acNewPage;
	TAction *acSaveFileAs;
	TAction *acShowDom;
	TAction *acUnderline;
	TAction *acBold;
	TAction *acItalics;
	TAction *acInsertImage;
	TAction *acInsertHyperlink;
	TAction *acInsertList;
	TImageList *ImageList1;
	TPanel *Panel1;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton4;
	TPanel *pCustomStyle;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	TMenuItem *N8;
	TMenuItem *N11;
	TAction *acSwitchEditMode;
	TToolButton *ToolButton7;
	TToolBar *ToolBar2;
	TToolButton *ToolButton8;
	TToolButton *ToolButton9;
	TToolButton *ToolButton10;
	TAction *acCopy;
	TAction *acPaste;
	TAction *acCut;
	TToolButton *ToolButton14;
	TColorBox *cbTextColor;
	TfrxFontComboBox *cbTextFont;
	TComboBox *cbTextSize;
	TComboBox *cbParFormat;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TImage *Image1;
	TComboBox *cbStyle;
	TAction *acSaveUserStyle;
	TSpeedButton *SpeedButton1;
	TAction *acDeleteStyle;
	TToolBar *ToolBar3;
	TToolButton *ToolButton11;
	TToolButton *ToolButton12;
	TToolButton *ToolButton13;
	TLabel *Label4;
	TSpeedButton *SpeedButton2;
	TAction *acEditStyle;
	TSpeedButton *SpeedButton3;
	void __fastcall AboutActionClick(TObject *Sender);
	void __fastcall NCloseClick(TObject *Sender);
	void __fastcall RichEdit1Change(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall NSaveDocumentClick(TObject *Sender);
	void __fastcall NCloseDocumentClick(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall WebBrowser1DownloadComplete(TObject *Sender);
	void __fastcall DOM1Click(TObject *Sender);
	void __fastcall ToolButton1Click(TObject *Sender);
	void __fastcall ToolButton2Click(TObject *Sender);
	void __fastcall acOpenFileExecute(TObject *Sender);
	void __fastcall acEditStyleExecute(TObject *Sender);
	void __fastcall acDeleteStyleExecute(TObject *Sender);
	void __fastcall acSaveUserStyleExecute(TObject *Sender);








private:	// User declarations
HTMLDocument *doc;
IHTMLDocument2 *Editor;
String FormTitle;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
