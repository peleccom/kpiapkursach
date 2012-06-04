// ---------------------------------------------------------------------------

#ifndef BrowserSysH
#define BrowserSysH
#include <oaidl.h>
#include "SHDocVw_OCX.h"
#include <SHDocVw.hpp>
#include <mshtml.h>
#include <Vcl.Graphics.hpp>
#include "Style.h"
#include <oaidl.h>
#include <Vcl.Dialogs.hpp>
#include "mshtmhst.h"
#include "SHDocVw_OCX.h"
class MyDocHandler;
// �����-������� ��� webbrowser
class BrowserSys {
public:
	BrowserSys(TCppWebBrowser *wb, TPopupMenu *popupmenu); // ����������� ��������
			// *Webbrowser � ��������� �� ����������� ����
	~BrowserSys();
	bool InitInterfaces(); // �������������
	void EditMode(bool on = true); // ������� ��������� � ����� ��������������
	bool CanPaste(); // ����� �� �������� � �������� �� ������ ������
	bool CanCopy(); // ����� �� ����������
	bool CanCut();  // ����� �� �������� � �����
	bool CanRedo(); // ����� �� ��������� ���������� ��������
	bool CanUndo(); // �������� ��������� ��������
	void Bold();    // ���������� ���������� ��������� ����������� ������
	void Italic();
	void Paste();   // �������� �� ������
	void Copy();
	void Cut();
	void UnderLine();
	void InsertList(); // �������� ��� ������
	void HyperLink();  // �������� ��� �����������
	void InsertImage(); // �������� �����������
	void Undo();
	void Redo();
	void SetSize(int size); // ���������� ������ ������
	void SetFont(const String &font); // ���������� �����
	void SetColor(int color);
	int GetSize(IHTMLTxtRange* TextRange);  // ������ ������ ������
	String GetFont(IHTMLTxtRange* TextRange);
	int GetColor(IHTMLTxtRange* TextRange);
	bool isItalic(IHTMLTxtRange* TextRange); // �������� �� ����� ���������?
	bool isBold(IHTMLTxtRange* TextRange);
	bool isUnderline(IHTMLTxtRange* TextRange);
	IHTMLTxtRange* TxtRange();  // �������� ������� ���������� ������� ������
	void SetStyle(Style *style);
	String GetText(); // ������� ����� �� webbrowser
	void SetText(String s); // ���������� �����
	void OpenFile(String filename);

private:
	TCppWebBrowser *wb;
	IHTMLDocument2 *Editor;
	MyDocHandler *dochandler;
	VARIANT var;
	VARIANT_BOOL rec;

	const String HtmlColor(int color);
};
// ---------------------------------------------------------------------------

// ��������� ����������� ��� �������� ������������ ���� � ���������� ���������
// ������� ������
class MyDocHandler : public IDocHostUIHandler {
	long refcount;
	TPopupMenu *popup;

public:

	MyDocHandler(TPopupMenu *popupmenu) : refcount(1) {
		popup = popupmenu;
	}

	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID classid,
		void** intf) {
		if (classid == IID_IUnknown)
			* intf = (IUnknown*)this;
		else if (classid == IID_IDocHostUIHandler)
			* intf = (IDocHostUIHandler*)this;
		else
			return E_NOINTERFACE;
		return S_OK;
	}

	virtual ULONG STDMETHODCALLTYPE AddRef() {
		InterlockedIncrement(&refcount);
		return refcount;
	}

	virtual ULONG STDMETHODCALLTYPE Release() {
		InterlockedDecrement(&refcount);
		if (refcount == 0)
			delete this;
		return refcount;
	}

	// Returning S_OK tells the web browser that it need not display its
	// own context menu, presumably because the application hosting it has
	// displayed its own menu to replace it.
	virtual HRESULT STDMETHODCALLTYPE ShowContextMenu(
		/* [in] */ DWORD dwID,
		/* [in] */ POINT __RPC_FAR *ppt,
		/* [in] */ IUnknown __RPC_FAR *pcmdtReserved,
		/* [in] */ IDispatch __RPC_FAR *pdispReserved) {

		popup->Popup(ppt->x, ppt->y);
		return S_OK;
	}

	virtual HRESULT STDMETHODCALLTYPE GetHostInfo(
		/* [out][in] */ DOCHOSTUIINFO __RPC_FAR *pInfo) {
		pInfo->dwFlags = 0x00000000;
		return S_OK;
	}

	virtual HRESULT STDMETHODCALLTYPE ShowUI(
		/* [in] */ DWORD dwID,
		/* [in] */ IOleInPlaceActiveObject __RPC_FAR *pActiveObject,
		/* [in] */ IOleCommandTarget __RPC_FAR *pCommandTarget,
		/* [in] */ IOleInPlaceFrame __RPC_FAR *pFrame,
		/* [in] */ IOleInPlaceUIWindow __RPC_FAR *pDoc) {
		return E_NOTIMPL;
	}

	virtual HRESULT STDMETHODCALLTYPE HideUI(void) {
		return E_NOTIMPL;
	}

	virtual HRESULT STDMETHODCALLTYPE UpdateUI(void) {
		return E_NOTIMPL;
	}

	virtual HRESULT STDMETHODCALLTYPE EnableModeless(
		/* [in] */ BOOL fEnable) {
		return E_NOTIMPL;
	}

	virtual HRESULT STDMETHODCALLTYPE OnDocWindowActivate(
		/* [in] */ BOOL fActivate) {
		return E_NOTIMPL;
	}

	virtual HRESULT STDMETHODCALLTYPE OnFrameWindowActivate(
		/* [in] */ BOOL fActivate) {
		return E_NOTIMPL;
	}

	virtual HRESULT STDMETHODCALLTYPE ResizeBorder(
		/* [in] */ LPCRECT prcBorder,
		/* [in] */ IOleInPlaceUIWindow __RPC_FAR *pUIWindow,
		/* [in] */ BOOL fRameWindow) {
		return E_NOTIMPL;
	}

	virtual HRESULT STDMETHODCALLTYPE TranslateAccelerator(
		/* [in] */ LPMSG lpMsg,
		/* [in] */ const GUID __RPC_FAR *pguidCmdGroup,
		/* [in] */ DWORD nCmdID) {
		// ShowMessage(GetKeyState(VK_CONTROL));
		if (lpMsg->message == WM_KEYDOWN)
			if ((GetKeyState(VK_CONTROL) & 0X80) == 0X80)

				return S_OK;
		return E_NOTIMPL;
	}

	virtual HRESULT STDMETHODCALLTYPE GetOptionKeyPath(
		/* [out] */ LPOLESTR __RPC_FAR *pchKey,
		/* [in] */ DWORD dw) {
		return E_NOTIMPL;
	}

	virtual HRESULT STDMETHODCALLTYPE GetDropTarget(
		/* [in] */ IDropTarget __RPC_FAR *pDropTarget,
		/* [out] */ IDropTarget __RPC_FAR *__RPC_FAR *ppDropTarget) {
		return E_NOTIMPL;
	}

	virtual HRESULT STDMETHODCALLTYPE GetExternal(
		/* [out] */ IDispatch __RPC_FAR *__RPC_FAR *ppDispatch) {
		return E_NOTIMPL;
	}

	virtual HRESULT STDMETHODCALLTYPE TranslateUrl(
		/* [in] */ DWORD dwTranslate,
		/* [in] */ OLECHAR __RPC_FAR *pchURLIn,
		/* [out] */ OLECHAR __RPC_FAR *__RPC_FAR *ppchURLOut) {
		return E_NOTIMPL;
	}

	virtual HRESULT STDMETHODCALLTYPE FilterDataObject(
		/* [in] */ IDataObject __RPC_FAR *pDO,
		/* [out] */ IDataObject __RPC_FAR *__RPC_FAR *ppDORet) {
		return E_NOTIMPL;
	}
};

#endif
