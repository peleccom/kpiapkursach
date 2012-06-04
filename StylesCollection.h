// ---------------------------------------------------------------------------

#ifndef StylesCollectionH
#define StylesCollectionH
// ---------------------------------------------------------------------------
#include <vector>
#include "Style.h"
#include <fstream.h>
#include <Vcl.StdCtrls.hpp>
using namespace std;

typedef vector<Style*> stylesvector; // typedef ��� ��������
// ��������� ������
class StylesCollection {
public:
	bool LoadFromFile(String filename); // �������� � ������ �� �����
	bool SaveToFile(String filename); // ������ � ����
	void FillComboBox(TComboBox *cb); // ������ ����������� � TComboBox
	void AddStyle(Style *style);  // ���������� ������ �����
	void DeleteStyle(String stylename); // �������� �����

private:
	stylesvector styles;  // ������, �������� �����
};
#endif
