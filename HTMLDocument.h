// ---------------------------------------------------------------------------

#ifndef HTMLDocumentH
#define HTMLDocumentH
// ---------------------------------------------------------------------------
#include <system.hpp>
#include <Vcl.ComCtrls.hpp>
#include "BrowserSys.h"
#include "mshtml.h"
// класс для хранения текущего документа
class HTMLDocument {
public:
	String FileName; // имя ассоцированного файла на ЖД
	String html; // документ в виде строки
	// конструктор, связывает RichEdit с BrowserSys
	HTMLDocument(TRichEdit *rche, BrowserSys *browser);
	void OpenFile(const String &filename); // загрузить из файла
	void SaveFile(const String &filename); // сохранить в файл
	bool changed(); // изменилось ли содержимое документа с последней
				//загрузки/сохранения
	void setchanged(bool flag); // изменение флага изменения документа
	void Update(const String &html); // каждый раз когда содержимое изменилось

private:
	bool _changed; // флаг изменнения
	BrowserSys *browser; // указатель на ассоциированный BrowserSys
	TRichEdit *rcedit;
};

#endif
