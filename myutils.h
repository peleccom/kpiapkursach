//---------------------------------------------------------------------------

#ifndef myutilsH
#define myutilsH
//---------------------------------------------------------------------------
//#include <string>
#include <MainWindowUnit.h>
class HTMLDocument
{
   public:
	String FileName;
	HTMLDocument(TRichEdit *rche, TCppWebBrowser *wbrowser);
	void OpenFile(const String &filename);
	void SaveFile(const String &filename);
	bool changed(); // content changed ?
	void Update(const String &html); // every time then update content
	String GetHTML();
   private:
	String html;
	bool _changed;
	TRichEdit *rcedit;
	TCppWebBrowser *wb;
};
#endif
