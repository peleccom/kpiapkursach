//---------------------------------------------------------------------------

#ifndef myutilsH
#define myutilsH
//---------------------------------------------------------------------------
//#include <string>
#include <MainWindowUnit.h>
class HTMLDocument
{
   private:
	String infilename;
	String html;
	bool _changed;
	TRichEdit *rcedit;
	TCppWebBrowser *wb;
   public:
	HTMLDocument(TRichEdit *rche, TCppWebBrowser *wbrowser);
	void OpenFile(const String &filename);
	void SaveFile(const String &filename);
	bool changed(); // content changed ?
	void Update(const String &html); // every time then update content
};
#endif
