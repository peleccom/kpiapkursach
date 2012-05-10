//---------------------------------------------------------------------------

#ifndef BrowserSysH
#define BrowserSysH
#include <oaidl.h>
#include "SHDocVw_OCX.h"
#include <SHDocVw.hpp>
#include <mshtml.h>
#include <Vcl.Graphics.hpp>
#include "Style.h"
class BrowserSys{
	public:
		BrowserSys(TCppWebBrowser *wb);
		bool InitInterfaces();
		void EditMode(bool on= true);
		bool CanPaste();
		bool CanCopy();
		bool CanCut();
		bool CanRedo();
		bool CanUndo();
		void Bold();
		void Italic();
		void Paste();
		void Copy();
		void Cut();
		void UnderLine();
		void InsertList();
		void HyperLink();
		void InsertImage();
		void Undo();
		void Redo();
		void SetSize(int size);
		void SetFont(const String &font);
		void SetColor(int color);
		int GetSize(IHTMLTxtRange* TextRange);
		String  GetFont();
		int GetColor();
		bool isItalic(IHTMLTxtRange* TextRange);
		bool isBold(IHTMLTxtRange* TextRange);
		bool isUnderline(IHTMLTxtRange* TextRange);
		IHTMLTxtRange* TxtRange();
		void SetStyle(Style *style);
		String GetText();
	private:
		TCppWebBrowser *wb;
		IHTMLDocument2 *Editor;
		VARIANT var;
		VARIANT_BOOL rec;
		const String HtmlColor(int color);
};

//---------------------------------------------------------------------------
#endif
