# Microsoft Developer Studio Generated NMAKE File, Based on LantCtrl.dsp
!IF "$(CFG)" == ""
CFG=LantCtrl - Win32 Debug
!MESSAGE No configuration specified. Defaulting to LantCtrl - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "LantCtrl - Win32 Release" && "$(CFG)" != "LantCtrl - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "LantCtrl.mak" CFG="LantCtrl - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "LantCtrl - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "LantCtrl - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "LantCtrl - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\LantCtrl.exe"


CLEAN :
	-@erase "$(INTDIR)\BackWnd.obj"
	-@erase "$(INTDIR)\InfoDlg.obj"
	-@erase "$(INTDIR)\LantCtrl.obj"
	-@erase "$(INTDIR)\LantCtrl.pch"
	-@erase "$(INTDIR)\LantCtrl.res"
	-@erase "$(INTDIR)\LantCtrlDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TextWnd.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\LantCtrl.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\LantCtrl.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\LantCtrl.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\LantCtrl.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\LantCtrl.pdb" /machine:I386 /out:"$(OUTDIR)\LantCtrl.exe" 
LINK32_OBJS= \
	"$(INTDIR)\BackWnd.obj" \
	"$(INTDIR)\InfoDlg.obj" \
	"$(INTDIR)\LantCtrl.obj" \
	"$(INTDIR)\LantCtrlDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TextWnd.obj" \
	"$(INTDIR)\LantCtrl.res"

"$(OUTDIR)\LantCtrl.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "LantCtrl - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\LantCtrl.exe" "$(OUTDIR)\LantCtrl.bsc"


CLEAN :
	-@erase "$(INTDIR)\BackWnd.obj"
	-@erase "$(INTDIR)\BackWnd.sbr"
	-@erase "$(INTDIR)\InfoDlg.obj"
	-@erase "$(INTDIR)\InfoDlg.sbr"
	-@erase "$(INTDIR)\LantCtrl.obj"
	-@erase "$(INTDIR)\LantCtrl.pch"
	-@erase "$(INTDIR)\LantCtrl.res"
	-@erase "$(INTDIR)\LantCtrl.sbr"
	-@erase "$(INTDIR)\LantCtrlDlg.obj"
	-@erase "$(INTDIR)\LantCtrlDlg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\TextWnd.obj"
	-@erase "$(INTDIR)\TextWnd.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\LantCtrl.bsc"
	-@erase "$(OUTDIR)\LantCtrl.exe"
	-@erase "$(OUTDIR)\LantCtrl.ilk"
	-@erase "$(OUTDIR)\LantCtrl.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\LantCtrl.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\LantCtrl.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\LantCtrl.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\BackWnd.sbr" \
	"$(INTDIR)\InfoDlg.sbr" \
	"$(INTDIR)\LantCtrl.sbr" \
	"$(INTDIR)\LantCtrlDlg.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\TextWnd.sbr"

"$(OUTDIR)\LantCtrl.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\LantCtrl.pdb" /debug /machine:I386 /out:"$(OUTDIR)\LantCtrl.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\BackWnd.obj" \
	"$(INTDIR)\InfoDlg.obj" \
	"$(INTDIR)\LantCtrl.obj" \
	"$(INTDIR)\LantCtrlDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TextWnd.obj" \
	"$(INTDIR)\LantCtrl.res"

"$(OUTDIR)\LantCtrl.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("LantCtrl.dep")
!INCLUDE "LantCtrl.dep"
!ELSE 
!MESSAGE Warning: cannot find "LantCtrl.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "LantCtrl - Win32 Release" || "$(CFG)" == "LantCtrl - Win32 Debug"
SOURCE=.\BackWnd.cpp

!IF  "$(CFG)" == "LantCtrl - Win32 Release"


"$(INTDIR)\BackWnd.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LantCtrl.pch"


!ELSEIF  "$(CFG)" == "LantCtrl - Win32 Debug"


"$(INTDIR)\BackWnd.obj"	"$(INTDIR)\BackWnd.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LantCtrl.pch"


!ENDIF 

SOURCE=.\InfoDlg.cpp

!IF  "$(CFG)" == "LantCtrl - Win32 Release"


"$(INTDIR)\InfoDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LantCtrl.pch"


!ELSEIF  "$(CFG)" == "LantCtrl - Win32 Debug"


"$(INTDIR)\InfoDlg.obj"	"$(INTDIR)\InfoDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LantCtrl.pch"


!ENDIF 

SOURCE=.\LantCtrl.cpp

!IF  "$(CFG)" == "LantCtrl - Win32 Release"


"$(INTDIR)\LantCtrl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LantCtrl.pch"


!ELSEIF  "$(CFG)" == "LantCtrl - Win32 Debug"


"$(INTDIR)\LantCtrl.obj"	"$(INTDIR)\LantCtrl.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LantCtrl.pch"


!ENDIF 

SOURCE=.\LantCtrl.rc

"$(INTDIR)\LantCtrl.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\LantCtrlDlg.cpp

!IF  "$(CFG)" == "LantCtrl - Win32 Release"


"$(INTDIR)\LantCtrlDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LantCtrl.pch"


!ELSEIF  "$(CFG)" == "LantCtrl - Win32 Debug"


"$(INTDIR)\LantCtrlDlg.obj"	"$(INTDIR)\LantCtrlDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LantCtrl.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "LantCtrl - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\LantCtrl.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\LantCtrl.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "LantCtrl - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\LantCtrl.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\LantCtrl.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\TextWnd.cpp

!IF  "$(CFG)" == "LantCtrl - Win32 Release"


"$(INTDIR)\TextWnd.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LantCtrl.pch"


!ELSEIF  "$(CFG)" == "LantCtrl - Win32 Debug"


"$(INTDIR)\TextWnd.obj"	"$(INTDIR)\TextWnd.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LantCtrl.pch"


!ENDIF 


!ENDIF 

