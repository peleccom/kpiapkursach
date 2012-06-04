// ---------------------------------------------------------------------------

#ifndef StyleH
#define StyleH
// ---------------------------------------------------------------------------
#include <System.hpp>
#include <System.UITypes.hpp>
#include <Vcl.Graphics.hpp>
#include <fstream.h>
// ������������ - ��������� ����� �������������� ������
enum FontStyle {
	fsNONE = 0, fsBOLD = 2, fsITALIC = 4, fsUNDERLINE = 8
};
// ����� ������������ ����� ��������������
// ���������� ����������� �� TObject ��� ��� ����������� ������� ��������� ��
// TObject � TComboBox *cbStyle � MainWindow
class Style : public TObject {
public:
	Style(); // ����������� ����������� �� ���������
	Style(int size, int color, const char *font, int fontstyle,
		String stylename = "");
	Style(int size, TColor color, const char *font, int fontstyle,
		String stylename = ""); // ��� ������������� ������������
	Style(const Style &obj); // ����������� �����������
	Style& operator = (const Style & right); // ���������� ��������� ����������
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
	void write(ofstream &fs);  // ������ ����� � �������� �������� �����
	void read(ifstream &fs);   // ������ ����� �� ������

private:
	int fontsize;
	int fontcolor;
	String fontface;
	FontStyle fontstyle;
	String stylename;

	void SaveString(String s, ofstream &fs); // ���������� Unicode ������ � �����
	String LoadString(ifstream &fs); // �������� Unicode ������ �� ������
};

#endif
