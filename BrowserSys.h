//---------------------------------------------------------------------------

#ifndef BrowserSysH
#define BrowserSysH
#include <oaidl.h>
#include "SHDocVw_OCX.h"
#include <SHDocVw.hpp>
#include <mshtml.h>
#include <Vcl.Graphics.hpp>
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
		IHTMLTxtRange* TxtRange();
	private:
		TCppWebBrowser *wb;
		IHTMLDocument2 *Editor;
		VARIANT var;
		VARIANT_BOOL rec;
		const String HtmlColor(int color);
};

//---------------------------------------------------------------------------
#endif
