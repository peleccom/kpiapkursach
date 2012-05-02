//---------------------------------------------------------------------------

#ifndef StyleH
#define StyleH
//---------------------------------------------------------------------------
#include <System.hpp>
#include <System.UITypes.hpp>
#include <Vcl.Graphics.hpp>

enum FontStyle {fsNONE=0,fsBOLD=2, fsITALIC=4, fsUNDERLINE=8};


class Style{
public:
Style();
Style(int size, int color, int paragraph,const char *font,int fontstyle);
Style(int size, TColor color, int paragraph,const char *font,int fontstyle);
Style(Style &obj);
void setsize(int);
int getsize();
void setface(String face);
String& getface();
void setpar(int);
int getpar();
void setcolor(int);
void setcolor(TColor);
TColor getcolor();
int getfontstyle();
void setfontstyle(int style);
private:
int fontsize;
int fontcolor;
int para;
String fontface;
FontStyle fontstyle;
};

#endif
