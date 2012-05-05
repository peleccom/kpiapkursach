//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "About.h"
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TAboutBox *AboutBox;
//--------------------------------------------------------------------- 
__fastcall TAboutBox::TAboutBox(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------

void __fastcall TAboutBox::FormGesture(TObject *Sender, const TGestureEventInfo &EventInfo,
          bool &Handled)
{
if (EventInfo.GestureID==-1) ShowMessage(L"“ут нет пасхальных €иц");
}
//---------------------------------------------------------------------------



