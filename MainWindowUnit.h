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
#include <Vcl.Buttons.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ImgList.hpp>
#include "frxCtrls.hpp"
#include <Vcl.Graphics.hpp>
//---------------------------------------------------------------------------
#include <mshtml.h>
#include "myutils.h"
#include "BrowserSys.h"
#include <VCLTee.TeCanvas.hpp>
#include <vector>
#include "Style.h"
class HTMLDocument;
class BrowserSys;

/* class TEventMethod : public IDispatch
 {
  public:
HRESULT Invoke(
		 DISPID dispIdMember,
		 REFIID riid,
		 LCID lcid,
		 WORD wFlags,
	DISPPARAMS *pDispParams,
		VARIANT *pVarResult,
		EXCEPINFO *pExcepInfo,
		UINT *puArgErr
);
 };  */
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
	TPanel *pCustomStyle;
	TMenuItem *N8;
	TMenuItem *N11;
	TAction *acSwitchEditMode;
	TAction *acCopy;
	TAction *acPaste;
	TAction *acCut;
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
	TLabel *Label4;
	TSpeedButton *SpeedButton2;
	TAction *acEditStyle;
	TSpeedButton *SpeedButton3;
	TAction *acClose;
	TControlBar *ControlBar1;
	TToolBar *ToolBar2;
	TToolButton *ToolButton14;
	TToolButton *ToolButton8;
	TToolButton *ToolButton9;
	TToolButton *ToolButton10;
	TToolBar *ToolBar3;
	TToolButton *ToolButton11;
	TToolButton *ToolButton12;
	TToolButton *ToolButton13;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton4;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	TMenuItem *Gh1;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N12;
	TTimer *tmUpdater;
	TToolButton *ToolButton7;
	TToolButton *ToolButton15;
	TToolButton *ToolButton16;
	TAction *acUndo;
	TAction *acRedo;
	TButtonColor *bTextColor;
	TPopupMenu *PopupMenu1;
	TMenuItem *N13;
	TMenuItem *N14;
	TMenuItem *N15;
	TMenuItem *N16;
	TMenuItem *N17;
	TMenuItem *N18;
	void __fastcall AboutActionClick(TObject *Sender);
	void __fastcall RichEdit1Change(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall WebBrowser1DownloadComplete(TObject *Sender);
	void __fastcall DOM1Click(TObject *Sender);
	void __fastcall acOpenFileExecute(TObject *Sender);
	void __fastcall acEditStyleExecute(TObject *Sender);
	void __fastcall acDeleteStyleExecute(TObject *Sender);
	void __fastcall acSaveUserStyleExecute(TObject *Sender);
	void __fastcall acCloseExecute(TObject *Sender);
	void __fastcall acSaveFileExecute(TObject *Sender);
	void __fastcall acNewPageExecute(TObject *Sender);
	void __fastcall acBoldExecute(TObject *Sender);
	void __fastcall acItalicsExecute(TObject *Sender);
	void __fastcall acUnderlineExecute(TObject *Sender);
	void __fastcall acCopyExecute(TObject *Sender);
	void __fastcall acPasteExecute(TObject *Sender);
	void __fastcall acInsertListExecute(TObject *Sender);
	void __fastcall acInsertHyperlinkExecute(TObject *Sender);
	void __fastcall acSaveFileAsExecute(TObject *Sender);
	void __fastcall acCutExecute(TObject *Sender);
	void __fastcall acInsertImageExecute(TObject *Sender);
	void __fastcall tmUpdaterTimer(TObject *Sender);
	void __fastcall acExitExecute(TObject *Sender);
	void __fastcall acUndoExecute(TObject *Sender);
	void __fastcall acRedoExecute(TObject *Sender);
	void __fastcall bTextColorClick(TObject *Sender);
	void __fastcall cbTextSizeSelect(TObject *Sender);
	void __fastcall cbTextFontClick(TObject *Sender);








private:	// User declarations
	HTMLDocument *doc;
	BrowserSys *browser;
	IHTMLDocument2 *Editor; // интерфейc браузера
	String FormTitle;
public:		// User declarations
	static std::vector<TForm1 *> forms;
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
