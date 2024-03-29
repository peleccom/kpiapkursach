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


#include <VCLTee.TeCanvas.hpp>
#include <Vcl.StdActns.hpp>
#include <vector>
#include "Style.h"
#include "StylesCollection.h"
#include "DocumentFormUnit.h"

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
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *NCloseDocument;
	TMenuItem *N7;
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
	TAction *acSwitchEditMode;
	TAction *acCopy;
	TAction *acPaste;
	TAction *acCut;
	TfrxFontComboBox *cbTextFont;
	TComboBox *cbTextSize;
	TLabel *Label2;
	TLabel *Label3;
	TAction *acSaveUserStyle;
	TAction *acDeleteStyle;
	TAction *acClose;
	TMenuItem *Gh1;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N12;
	TTimer *tmUpdater;
	TAction *acUndo;
	TAction *acRedo;
	TPopupMenu *PopupMenu1;
	TMenuItem *N13;
	TMenuItem *N14;
	TMenuItem *N15;
	TMenuItem *N16;
	TMenuItem *N17;
	TMenuItem *N18;
	TMenuItem *N6;
	TMenuItem *N8;
	TMenuItem *N11;
	TWindowCascade *WindowCascade1;
	TWindowTileHorizontal *WindowTileHorizontal1;
	TWindowTileVertical *WindowTileVertical1;
	TWindowMinimizeAll *WindowMinimizeAll1;
	TWindowArrange *WindowArrange1;
	TMenuItem *ileHorizontally1;
	TMenuItem *ileVertically1;
	TMenuItem *Arrange1;
	TSaveDialog *SaveDocumentDialog;
	TOpenDialog *OpenDocumentDialog;
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
	TToolButton *ToolButton7;
	TToolButton *ToolButton15;
	TToolButton *ToolButton16;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton4;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	TButtonColor *bTextColor;
	TLabel *Label1;
	TLabel *Label4;
	TComboBox *cbStyle;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	void __fastcall AboutActionClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall acOpenFileExecute(TObject *Sender);
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
	void __fastcall cbStyleSelect(TObject *Sender);
private:	// User declarations
	String FormTitle;
	StylesCollection *defaultstyles,*styles;  //��������� �� ��������� ����������
		//� ���������������� ������
	Style *curstyle;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	void SetStyleToUI(Style *style); // ���������� �������� ���������� ������
		// � ����������� �� ������ style
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
