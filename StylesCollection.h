//---------------------------------------------------------------------------

#ifndef StylesCollectionH
#define StylesCollectionH
//---------------------------------------------------------------------------
#include <vector>
#include "Style.h"
#include <fstream.h>
#include <Vcl.StdCtrls.hpp>
using namespace std;

typedef vector<Style*> stylesvector;


class StylesCollection{
public:
	bool LoadFromFile(String filename);
	bool SaveToFile(String filename);
	void FillComboBox(TComboBox *cb);
	void AddStyle(Style *style);
	void DeleteStyle(String stylename); // maybe ??
private:
	stylesvector styles;
};
#endif
