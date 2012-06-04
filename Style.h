// ---------------------------------------------------------------------------

#ifndef StyleH
#define StyleH
// ---------------------------------------------------------------------------
#include <System.hpp>
#include <System.UITypes.hpp>
#include <Vcl.Graphics.hpp>
#include <fstream.h>
// перечисление - возможные флаги форматирования текста
enum FontStyle {
	fsNONE = 0, fsBOLD = 2, fsITALIC = 4, fsUNDERLINE = 8
};
// класс определяющий стиль форматирования
// необходимо наследовать от TObject так как потребуется хранить указатели на
// TObject в TComboBox *cbStyle в MainWindow
class Style : public TObject {
public:
	Style(); // стандартный конструктор по умолчанию
	Style(int size, int color, const char *font, int fontstyle,
		String stylename = "");
	Style(int size, TColor color, const char *font, int fontstyle,
		String stylename = ""); // два перегруженных конструктора
	Style(const Style &obj); // конструктор копирования
	Style& operator = (const Style & right); // перегрузка оператора присвоения
	void setsize(int); // setters & getters
	int getsize() const ;
	void setface(String face);
	String getface() const ;
	void setcolor(int);
	void setcolor(TColor);
	void setstylename(String stylename);
	String getstylename() const ;
	TColor getcolor() const ;
	int getfontstyle() const ;
	void setfontstyle(int style);
	void write(ofstream &fs);  // запись стиля в открытый файловый поток
	void read(ifstream &fs);   // чтение стиля из потока

private:
	int fontsize;
	int fontcolor;
	String fontface;
	FontStyle fontstyle;
	String stylename;

	void SaveString(String s, ofstream &fs); // Сохранение Unicode строки в поток
	String LoadString(ifstream &fs); // Загрузка Unicode строки из потока
};

#endif
