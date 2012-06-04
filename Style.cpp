// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Style.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

Style::Style(int size, int color, const char *font, int fontstyle,
	String stylename) {
	setsize(size);
	setcolor(color);
	setface(String(font));
	setfontstyle(fontstyle);
	setstylename(stylename);
}

Style::Style(int size, TColor color, const char *font, int fontstyle,
	String stylename) {
	setsize(size);
	setcolor(color);
	setface(String(font));
	setfontstyle(fontstyle);
	setstylename(stylename);
}

Style::Style(const Style &obj) {
	setsize(obj.getsize());
	setcolor(obj.getcolor());
	setface(obj.getface());
	setfontstyle(obj.getfontstyle());
	setstylename(obj.getstylename());
}

Style::Style() {
	String face("");
	setsize(0);
	setcolor(0);
	setface(face);
	setfontstyle(fsNONE);
	setstylename("");
}

void Style::setsize(int size) {
	if (size <= 7 && size >= 0)
		fontsize = size;
	else
		fontsize = 0;
}

int Style::getsize() const {
	return fontsize;
}

void Style::setface(String s) {
	fontface = s;
}

String Style::getface() const {
	return fontface;
}

void Style::setcolor(int colorRGB) {
	fontcolor = colorRGB;
}

TColor Style::getcolor() const {
	return static_cast<TColor>(fontcolor);
}

void Style::setcolor(TColor color) {
	fontcolor = ColorToRGB(color);
}

void Style::setfontstyle(int style) {
	fontstyle = style;
}

int Style::getfontstyle() const {
	return fontstyle;
}

String Style::getstylename() const {
	return stylename;
}

void Style::setstylename(String stylename) {
	this->stylename = stylename;
}

void Style::write(ofstream &fs) {
	int var;
	SaveString(getstylename(), fs);
	var = getsize();
	fs.write((char*) &var, sizeof(var));
	SaveString(getface(), fs);
	var = getcolor();
	fs.write((char*) &var, sizeof(var));
	var = getfontstyle();
	fs.write((char*) &var, sizeof(var));
}

void Style::read(ifstream &fs) {
	int var;
	setstylename(LoadString(fs));
	fs.read((char*) &var, sizeof(var));
	setsize(var);
	setface(LoadString(fs));
	fs.read((char*) &var, sizeof(var));
	setcolor(var);
	fs.read((char*) &var, sizeof(var));
	setfontstyle(var);
}

void Style::SaveString(String s, ofstream &fs) {
	int len;
	len = s.Length() * s.ElementSize();
	fs.write((char*) &len, sizeof(len)); // char count
	fs.write((char*) s.c_str(), len); // string content in unicode
}

String Style::LoadString(ifstream &fs) {
	int len;
	fs.read((char *) &len, sizeof(len));
	String s;
	s.SetLength((int) len / s.ElementSize());
	fs.read((char*) s.data(), len);
	return s;
}

Style& Style:: operator = (const Style & right) {
	if (this == &right) {
		return *this;
	}
	setsize(right.getsize());
	setcolor(right.getcolor());
	setface(right.getface());
	setfontstyle(right.getfontstyle());
	setstylename(right.getstylename()); // ??
	return *this;
}
