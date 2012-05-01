//---------------------------------------------------------------------------

#ifndef BrowserSysH
#define BrowserSysH
#include <oaidl.h>
#include <MainWindowUnit.h>
class BrowserSys{
	public:
		BrowserSys(TCppWebBrowser *wb);
		bool InitInterfaces();
		void EditMode(bool on= true);
		bool CanPaste();
		bool CanCopy();
		IHTMLTxtRange* TxtRange();
	private:
		TCppWebBrowser *wb;
		IHTMLDocument2 *Editor;
};

//---------------------------------------------------------------------------
#endif
