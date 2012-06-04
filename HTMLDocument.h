// ---------------------------------------------------------------------------

#ifndef HTMLDocumentH
#define HTMLDocumentH
// ---------------------------------------------------------------------------
#include <system.hpp>
#include <Vcl.ComCtrls.hpp>
#include "BrowserSys.h"
#include "mshtml.h"
// ����� ��� �������� �������� ���������
class HTMLDocument {
public:
	String FileName; // ��� ��������������� ����� �� ��
	String html; // �������� � ���� ������
	// �����������, ��������� RichEdit � BrowserSys
	HTMLDocument(TRichEdit *rche, BrowserSys *browser);
	void OpenFile(const String &filename); // ��������� �� �����
	void SaveFile(const String &filename); // ��������� � ����
	bool changed(); // ���������� �� ���������� ��������� � ���������
				//��������/����������
	void setchanged(bool flag); // ��������� ����� ��������� ���������
	void Update(const String &html); // ������ ��� ����� ���������� ����������

private:
	bool _changed; // ���� ����������
	BrowserSys *browser; // ��������� �� ��������������� BrowserSys
	TRichEdit *rcedit;
};

#endif
