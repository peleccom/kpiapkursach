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
ShowMessage(EventInfo.GestureID);
}
//---------------------------------------------------------------------------


