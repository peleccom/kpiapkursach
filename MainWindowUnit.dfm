object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1056#1077#1076#1072#1082#1090#1086#1088' HTML'
  ClientHeight = 453
  ClientWidth = 790
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 337
    Top = 33
    Height = 420
    ExplicitLeft = 336
    ExplicitTop = 224
    ExplicitHeight = 100
  end
  object ControlBar1: TControlBar
    Left = 0
    Top = 0
    Width = 790
    Height = 33
    Align = alTop
    TabOrder = 0
    ExplicitWidth = 672
  end
  object RichEdit1: TRichEdit
    Left = 0
    Top = 33
    Width = 337
    Height = 420
    Align = alLeft
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 1
    OnChange = RichEdit1Change
  end
  object WebBrowser1: TWebBrowser
    Left = 340
    Top = 33
    Width = 329
    Height = 420
    Align = alClient
    TabOrder = 2
    ExplicitLeft = 334
    ExplicitTop = 39
    ControlData = {
      4C00000001220000692B00000000000000000000000000000000000000000000
      000000004C000000000000000000000001000000E0D057007335CF11AE690800
      2B2E126208000000000000004C0000000114020000000000C000000000000046
      8000000000000000000000000000000000000000000000000000000000000000
      00000000000000000100000000000000000000000000000000000000}
  end
  object TreeView1: TTreeView
    Left = 669
    Top = 33
    Width = 121
    Height = 420
    Align = alRight
    Indent = 19
    TabOrder = 3
    ExplicitLeft = 678
    ExplicitTop = 39
    ExplicitHeight = 97
  end
  object MainMenu1: TMainMenu
    Left = 640
    Top = 352
    object N1: TMenuItem
      Caption = '&'#1060#1072#1081#1083
      object NOpenDocument: TMenuItem
        Caption = '&'#1054#1090#1082#1088#1099#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090
        OnClick = NOpenDocumentClick
      end
      object N8: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090
      end
      object N9: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100' '#1096#1072#1073#1083#1086#1085
      end
      object N10: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1096#1072#1073#1083#1086#1085
      end
      object NClose: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        OnClick = NCloseClick
      end
    end
    object N3: TMenuItem
      Caption = '&'#1042#1080#1076
      object NShowTree: TMenuItem
        AutoCheck = True
        Caption = #1054#1090#1086#1073#1088#1072#1078#1072#1090#1100' '#1076#1077#1088#1077#1074#1086
        Checked = True
      end
    end
    object N2: TMenuItem
      Caption = '&'#1055#1086#1084#1086#1097#1100
      object AboutAction: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        OnClick = AboutActionClick
      end
      object N6: TMenuItem
        Caption = #1054#1073' '#1072#1074#1090#1086#1088#1077
      end
    end
  end
  object OpenDocumentDialog: TOpenDialog
    Filter = #1042#1089#1077' '#1087#1086#1076#1076#1077#1088#1078#1080#1074#1072#1077#1084#1099#1077' '#1092#1086#1088#1084#1072#1090#1099'|*.html;*.txt;*.htm'
    Left = 208
    Top = 65528
  end
  object SaveDocumentDialog: TSaveDialog
    Left = 296
  end
end
