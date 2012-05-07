//---------------------------------------------------------------------------

#ifndef StyleH
#define StyleH
//---------------------------------------------------------------------------
#include <System.hpp>
#include <System.UITypes.hpp>
#include <Vcl.Graphics.hpp>
#include <fstream.h>

enum FontStyle {fsNONE=0,fsBOLD=2, fsITALIC=4, fsUNDERLINE=8};


class Style: public TObject{
public:
Style();
Style(int size, int color, int paragraph,const char *font,int fontstyle, String stylename = "");
Style(int size, TColor color, int paragraph,const char *font,int fontstyle, String stylename = "");
Style(const Style &obj);
void setsize(int);
int getsize() const;
void setface(String face);
String getface() const;
void setpar(int);
int getpar() const;
void setcolor(int);
void setcolor(TColor);
void setstylename(String stylename);
String getstylename() const;
TColor getcolor() const;
int getfontstyle() const;
void setfontstyle(int style);
void write(ofstream &fs);
void read(ifstream &fs);
private:
int fontsize;
int fontcolor;
int para;
String fontface;
FontStyle fontstyle;
String stylename;

void SaveString(String s, ofstream &fs);
String LoadString(ifstream &fs);
};

#endif
