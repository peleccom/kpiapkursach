//---------------------------------------------------------------------------

#ifndef DOMTreeUnitH
#define DOMTreeUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TDOMTreeForm : public TForm
{
__published:	// IDE-managed Components
	TTreeView *TreeView1;
private:	// User declarations
public:		// User declarations
	__fastcall TDOMTreeForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDOMTreeForm *DOMTreeForm;
//---------------------------------------------------------------------------
#endif
