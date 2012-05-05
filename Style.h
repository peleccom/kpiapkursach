//---------------------------------------------------------------------------

#ifndef StyleH
#define StyleH
//---------------------------------------------------------------------------
#include <System.hpp>
#include <System.UITypes.hpp>
#include <Vcl.Graphics.hpp>
#include <iostream>
using namespace std;

enum FontStyle {fsNONE=0,fsBOLD=2, fsITALIC=4, fsUNDERLINE=8};


class Style{
public:
Style();
Style(int size, int color, int paragraph,const char *font,int fontstyle, String stylename = "");
Style(int size, TColor color, int paragraph,const char *font,int fontstyle, String stylename = "");
Style(Style &obj);
void setsize(int);
int getsize();
void setface(String face);
String& getface();
void setpar(int);
int getpar();
void setcolor(int);
void setcolor(TColor);
void setstylename(String stylename);
String& getstylename();
TColor getcolor();
int getfontstyle();
void setfontstyle(int style);
void write(ofstream &fs);
void read(fstream &fs);
private:
int fontsize;
int fontcolor;
int para;
String fontface;
FontStyle fontstyle;
String stylename;
};

#endif
