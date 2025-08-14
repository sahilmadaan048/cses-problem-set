@echo off
setlocal enabledelayedexpansion

:: Find all .cpp files recursively
set count=0
echo Searching for .cpp files...
for /r %%f in (*.cpp) do (
    set /a count+=1
    set "file!count!=%%f"
    echo !count!: %%f
)

if %count%==0 (
    echo No .cpp files found!
    pause
    exit /b 1
)

:: Ask user to pick a file by number
set /p choice=Enter the number of the file to compile and run: 

:: Validate choice
if %choice% gtr %count% (
    echo Invalid choice!
    pause
    exit /b 1
)

:: Get full path of selected file
set "selectedFile=!file%choice%!"

:: Extract folder and file name without extension
for %%F in ("%selectedFile%") do (
    set "folder=%%~dpF"
    set "filename=%%~nxF"
    set "exeName=%%~nF"
)

:: Compile with C++17
g++ -std=c++17 "%selectedFile%" -o "%folder%%exeName%.exe"
if errorlevel 1 (
    echo Compilation failed.
    pause
    exit /b 1
)

:: Run executable
echo Running %exeName%...
"%folder%%exeName%.exe"

pause
