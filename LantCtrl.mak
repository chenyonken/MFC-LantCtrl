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
	"$(INTDIR)\LantCtrl.obj" \
	"$(INTDIR)\LantCtrlDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\LantCtrl.res" \
	"$(INTDIR)\BackWnd.obj" \
	"$(INTDIR)\TextWnd.obj"

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

ALL : "$(OUTDIR)\LantCtrl.exe"


CLEAN :
	-@erase "$(INTDIR)\BackWnd.obj"
	-@erase "$(INTDIR)\LantCtrl.obj"
	-@erase "$(INTDIR)\LantCtrl.pch"
	-@erase "$(INTDIR)\LantCtrl.res"
	-@erase "$(INTDIR)\LantCtrlDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TextWnd.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\LantCtrl.exe"
	-@erase "$(OUTDIR)\LantCtrl.ilk"
	-@erase "$(OUTDIR)\LantCtrl.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\LantCtrl.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ   /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\LantCtrl.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\LantCtrl.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\LantCtrl.pdb" /debug /machine:I386 /out:"$(OUTDIR)\LantCtrl.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\LantCtrl.obj" \
	"$(INTDIR)\LantCtrlDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\LantCtrl.res" \
	"$(INTDIR)\BackWnd.obj" \
	"$(INTDIR)\TextWnd.obj"

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

"$(INTDIR)\BackWnd.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LantCtrl.pch"


SOURCE=.\LantCtrl.cpp

"$(INTDIR)\LantCtrl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LantCtrl.pch"


SOURCE=.\LantCtrl.rc

"$(INTDIR)\LantCtrl.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\LantCtrlDlg.cpp

"$(INTDIR)\LantCtrlDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LantCtrl.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "LantCtrl - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\LantCtrl.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\LantCtrl.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "LantCtrl - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\LantCtrl.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ   /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\LantCtrl.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\TextWnd.cpp

"$(INTDIR)\TextWnd.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LantCtrl.pch"



!ENDIF 

