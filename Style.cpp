//---------------------------------------------------------------------------

#pragma hdrstop

#include "Style.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Style::Style(int size, int color, int paragraph,
const char *font, int fontstyle, String stylename){
	setsize(size);
	setcolor(color);
	setpar(paragraph);
	setface(String(font));
	setfontstyle(fontstyle);
	setstylename(stylename);
}

Style::Style(int size, TColor color, int paragraph,
const char *font, int fontstyle, String stylename){
	setsize(size);
	setcolor(color);
	setpar(paragraph);
	setface(String(font));
	setfontstyle(fontstyle);
	setstylename(stylename);
}
Style::Style(const Style &obj){
	setsize(obj.getsize());
	setcolor(obj.getcolor());
	setpar(obj.getpar());
	setface(obj.getface());
	setfontstyle(obj.getfontstyle());
	setstylename(obj.getstylename());
}

Style::Style(){
	String face("");
	setsize(0);
	setcolor(0);
	setpar(0);
	setface(face);
	setfontstyle(fsNONE);
	setstylename("");
}

void Style::setsize(int size){
	if (size <= 7 && size>=0)
		fontsize = size;
	else
		fontsize = 0;
}

int Style::getsize() const {
	return fontsize;
}

void Style::setface(String s){
	fontface = s;
}

String Style::getface() const {
	return fontface;
}

void Style::setpar(int par){
	if (par>=0 && par<=9)
		para = par;
	else
		para = 0;
}

int Style::getpar() const {
	return para;
}

void Style::setcolor(int colorRGB){
	fontcolor = colorRGB;
}

TColor Style::getcolor() const {
	return static_cast <TColor> (fontcolor);
}

void Style::setcolor(TColor color){
	fontcolor  = ColorToRGB(color);
}

void Style::setfontstyle(int style){
	fontstyle = style;
}

int Style::getfontstyle() const {
	return fontstyle;
}

String Style::getstylename() const {
	return stylename;
}

void Style::setstylename(String stylename){
	this->stylename = stylename;
}

void Style::write(ofstream &fs)
{
	// формат:
//	"имя стиля" "size" "face" "par" "color" "fontstyle"
//fs << stylename<< "|" << fontsize << "|" << fontface
	int var;
	SaveString(getstylename(),fs);
	var = getsize();
	fs.write((char*) &var,sizeof(var));
	SaveString(getface(),fs);
	var = getpar();
	fs.write((char*) &var,sizeof(var));
	var = getcolor();
	fs.write((char*) &var,sizeof(var));
	var = getfontstyle();
	fs.write((char*) &var,sizeof(var));
}

void Style::read(ifstream &fs){
// bar
	int var;
	setstylename(LoadString(fs));
	fs.read((char*) &var,sizeof(var));
	setsize(var);
	setface(LoadString(fs));
	fs.read((char*) &var,sizeof(var));
	setpar(var);
	fs.read((char*) &var,sizeof(var));
	setcolor(var);
	fs.read((char*) &var,sizeof(var));
	setfontstyle(var);
}

void Style::SaveString(String s, ofstream &fs){
	int len;
	len = s.Length() * s.ElementSize();
	fs.write((char*) &len, sizeof(len));// char count
	fs.write((char*) s.c_str(), len); //string content in unicode
}

String Style::LoadString(ifstream &fs){
	int len;
	fs.read((char *) &len, sizeof(len));
	String s;
	s.SetLength((int) len/ s.ElementSize());
	fs.read((char*) s.data(), len);
	return s;
}

