@REM set folder name to "bin" for storing generated files
SET folderName=bin

@REM check if the folder exists first, if not, then create one, else, do nothing
IF NOT EXIST "%folderName%" (
    MKDIR "%folderName%"
)

@REM compile the project
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o "%folderName%\main.o" src\main.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -o "%folderName%\main.gb" "%folderName%\main.o"