//---------------------------------------------------------------------------

#pragma hdrstop

#include "StylesCollection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void StylesCollection::FillComboBox(TComboBox *cb){
	stylesvector::const_iterator i;
	for (i=styles.begin(); i != styles.end(); i++) {
		cb->Items->AddObject((*i)->getstylename(),*i);
	}
}

bool StylesCollection::LoadFromFile(String filename){
	ifstream fs(filename.c_str());
	if (!fs) { return false;}
	int count;
	fs >> count;
	for (int i = 0; i < count; i++) {
		Style *style = new Style;
		style->read(fs);
		this->AddStyle(style);
	}
	fs.close();
	return true;
}


bool StylesCollection::SaveToFile(String filename){
	ofstream fs(filename.c_str());
	if (!fs) { return false;}
	int count = styles.size();
	fs << count;
	for (int i = 0; i < count; i++) {
		styles[i]->write(fs);
	}
	fs.close();
	return true;
}

void StylesCollection::AddStyle(Style *style){
	Style *buf_style;
	buf_style = new Style(*style);
	styles.push_back(buf_style);
}

void StylesCollection::DeleteStyle(String stylename){
	stylesvector::iterator i;
	Style *st;
	for (i=styles.begin(); i != styles.end(); i++) {
		st =*i;
		if (st->getstylename() == stylename) {
			// deleting
			styles.erase(i);
            delete st;
			break;
		}
	}
}