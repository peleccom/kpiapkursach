// ---------------------------------------------------------------------------

#ifndef StylesCollectionH
#define StylesCollectionH
// ---------------------------------------------------------------------------
#include <vector>
#include "Style.h"
#include <fstream.h>
#include <Vcl.StdCtrls.hpp>
using namespace std;

typedef vector<Style*> stylesvector; // typedef для удобства
// коллекция стилей
class StylesCollection {
public:
	bool LoadFromFile(String filename); // открытие и чтение из файла
	bool SaveToFile(String filename); // запись в файл
	void FillComboBox(TComboBox *cb); // запись содержимого в TComboBox
	void AddStyle(Style *style);  // добавление нового стиля
	void DeleteStyle(String stylename); // удаление стиля

private:
	stylesvector styles;  // вектор, хранящий стили
};
#endif
