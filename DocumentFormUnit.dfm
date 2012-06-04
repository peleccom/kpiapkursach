object DocumentForm: TDocumentForm
  Left = 0
  Top = 0
  Caption = 'DocumentForm'
  ClientHeight = 344
  ClientWidth = 652
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 301
    Top = 0
    Height = 344
    ExplicitLeft = 336
    ExplicitTop = 144
    ExplicitHeight = 100
  end
  object WebBrowser1: TCppWebBrowser
    Left = 304
    Top = 0
    Width = 348
    Height = 344
    Align = alClient
    TabOrder = 0
    OnDocumentComplete = WebBrowser1DocumentComplete
    ExplicitLeft = 307
    ControlData = {
      4C000000F82300008E2300000000000000000000000000000000000000000000
      000000004C000000000000000000000001000000E0D057007335CF11AE690800
      2B2E126208000000000000004C0000000114020000000000C000000000000046
      8000000000000000000000000000000000000000000000000000000000000000
      00000000000000000100000000000000000000000000000000000000}
  end
  object RichEdit1: TRichEdit
    Left = 0
    Top = 0
    Width = 301
    Height = 344
    Align = alLeft
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Lines.Strings = (
      '')
    ParentFont = False
    PlainText = True
    ScrollBars = ssVertical
    TabOrder = 1
    OnChange = RichEdit1Change
  end
end
