//---------------------------------------------------------------------------

#ifndef myutilsH
#define myutilsH
//---------------------------------------------------------------------------
//#include <string>
#include <MainWindowUnit.h>
class HTMLDocument
{
   private:
	String infilename;
   public:
	void OpenFile(String filename);
	void LoadContent();
	void ShowContent(TWebBrowser *wb, String HTMLCode);
};


void ShowPage();




/*
procedure loadStringHtml(WebBrowser: TWebBrowser; HTMLCode: string) ;
var
   strList:   TStringList;
   memStream: TMemoryStream;
begin
   WebBrowser.Navigate('about:blank') ;
   while WebBrowser.ReadyState < READYSTATE_INTERACTIVE do
    Application.ProcessMessages;

   if Assigned(WebBrowser.Document) then
   begin
     strList := TStringList.Create;
     try
       memStream := TMemoryStream.Create;
       try
         strList.Text := HTMLCode;
         strList.SaveToStream(memStream) ;
         memStream.Seek(0, 0) ;
         (WebBrowser.Document as IPersistStreamInit).Load(TStreamAdapter.Create(memStream)) ;
	   finally
         memStream.Free;
       end;
     finally
       strList.Free;
     end;
   end;
end;*/
#endif
