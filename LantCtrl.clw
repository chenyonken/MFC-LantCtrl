; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTextWnd
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "lantctrl.h"
LastPage=0

ClassCount=5
Class1=CBackWnd
Class2=CInfoDlg
Class3=CLantCtrlApp
Class4=CLantCtrlDlg
Class5=CTextWnd

ResourceCount=3
Resource1=IDD_LANTCTRL_DIALOG
Resource2=IDD_INFODLG
Resource3=IDR_MENU1

[CLS:CBackWnd]
Type=0
BaseClass=CWnd
HeaderFile=BackWnd.h
ImplementationFile=BackWnd.cpp
LastObject=CBackWnd
Filter=W
VirtualFilter=WC

[CLS:CInfoDlg]
Type=0
BaseClass=CDialog
HeaderFile=InfoDlg.h
ImplementationFile=InfoDlg.cpp

[CLS:CLantCtrlApp]
Type=0
BaseClass=CWinApp
HeaderFile=LantCtrl.h
ImplementationFile=LantCtrl.cpp

[CLS:CLantCtrlDlg]
Type=0
BaseClass=CDialog
HeaderFile=LantCtrlDlg.h
ImplementationFile=LantCtrlDlg.cpp

[CLS:CTextWnd]
Type=0
BaseClass=CWnd
HeaderFile=TextWnd.h
ImplementationFile=TextWnd.cpp
Filter=W
VirtualFilter=WC
LastObject=ID_SHOW_ADD

[DLG:IDD_INFODLG]
Type=1
Class=CInfoDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT,edit,1350631556

[DLG:IDD_LANTCTRL_DIALOG]
Type=1
Class=CLantCtrlDlg
ControlCount=0

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_SHOW_MOD
Command2=ID_SHOW_DEL
Command3=ID_SHOW_ADD
CommandCount=3

