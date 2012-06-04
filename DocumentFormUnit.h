// ---------------------------------------------------------------------------

#ifndef DocumentFormUnitH
#define DocumentFormUnitH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "SHDocVw_OCX.h"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.OleCtrls.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.Menus.hpp>
#include "BrowserSys.h"
#include "HTMLDocument.h"
#include <Vcl.ImgList.hpp>
#include <Vcl.AppEvnts.hpp>

// ---------------------------------------------------------------------------
class TDocumentForm : public TForm {
__published: // IDE-managed Components

	TRichEdit *RichEdit1;
	TCppWebBrowser *WebBrowser1;
	TSplitter *Splitter1;

	void __fastcall RichEdit1Change(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall WebBrowser1DocumentComplete(TObject *Sender,
		LPDISPATCH pDisp, Variant *URL);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private: // User declarations

		public : // User declarations
	__fastcall TDocumentForm(TComponent* Owner);

	HTMLDocument *doc;
	BrowserSys *browser;
	int updatetimes; // счетчик числа обновлений
	// RichEdit обновится из webbrowser два раза при создании нового документа
	//
};

// ---------------------------------------------------------------------------
extern PACKAGE TDocumentForm *DocumentForm;
// ---------------------------------------------------------------------------
#endif
