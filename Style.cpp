//---------------------------------------------------------------------------

#pragma hdrstop

#include "Style.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Style::Style(int size, int color, int paragraph,
const char *font, int fontstyle){
	setsize(size);
	setcolor(color);
	setpar(paragraph);
	setface(String(font));
	setfontstyle(fontstyle);
}

Style::Style(int size, TColor color, int paragraph,
const char *font, int fontstyle){
	setsize(size);
	setcolor(color);
	setpar(paragraph);
	setface(String(font));
	setfontstyle(fontstyle);
}
Style::Style(Style &obj){
	setsize(obj.getsize());
	setcolor(obj.getcolor());
	setpar(obj.getpar());
	setface(obj.getface());
	setfontstyle(obj.getfontstyle());
}

Style::Style(){
	String face("");
	setsize(0);
	setcolor(0);
	setpar(0);
	setface(face);
	setfontstyle(fsNONE);
}

void Style::setsize(int size){
	if (size <= 7 && size>=0)
		fontsize = size;
	else
		fontsize = 0;
}

int Style::getsize(){
	return fontsize;
}

void Style::setface(String s){
	fontface = s;
}

String &Style::getface(){
	return fontface;
}

void Style::setpar(int par){
	if (par>=0 && par<=9)
		para = par;
	else
		para = 0;
}

int Style::getpar(){
	return para;
}

void Style::setcolor(int colorRGB){
	fontcolor = colorRGB;
}

TColor Style::getcolor(){
	return static_cast <TColor> (fontcolor);
}

void Style::setcolor(TColor color){
	fontcolor  = ColorToRGB(color);
}

void Style::setfontstyle(int style){
	fontstyle = style;
}

int Style::getfontstyle(){
	return fontstyle;
}

