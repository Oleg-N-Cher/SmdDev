@ECHO OFF
SET "PATH=..\Bin\bin"
IF EXIST %GDK_WIN%\bin SET "PATH=%PATH%;%GDK_WIN%\bin"

make.exe -f makefile.gen
IF errorlevel 1 PAUSE

START d:\WIN32APP\Emulz\Fusion364\Fusion.exe d:\Projects\XDev\SegaDev\Obj\out\rom.bin
