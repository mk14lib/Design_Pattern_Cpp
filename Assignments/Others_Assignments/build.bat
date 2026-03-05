@echo off
setlocal enabledelayedexpansion
REM ============================================
REM Quiz Game Application Build Script
REM ============================================
REM This script compiles the Quiz Game Application
REM using g++ compiler and offers to run it after
REM successful compilation.
REM ============================================

echo ============================================
echo   Quiz Game Application Build Script
echo ============================================
echo.

REM Check if g++ compiler is available
where g++ >nul 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo ERROR: g++ compiler not found!
    echo Please install MinGW or ensure g++ is in your PATH.
    echo.
    pause
    exit /b 1
)

echo [1/3] Checking source files...
if not exist "main.cpp" (
    echo ERROR: main.cpp not found!
    echo Please ensure you are in the correct directory.
    echo.
    pause
    exit /b 1
)
if not exist "Question.h" (
    echo ERROR: Question.h not found!
    echo Please ensure all header files are present.
    echo.
    pause
    exit /b 1
)
if not exist "QuestionSelectionStrategy.h" (
    echo ERROR: QuestionSelectionStrategy.h not found!
    echo Please ensure all header files are present.
    echo.
    pause
exit /b 1
)
if not exist "GameManager.h" (
    echo ERROR: GameManager.h not found!
    echo Please ensure all header files are present.
    echo.
    pause
    exit /b 1
)
echo [OK] All source files found.
echo.

echo [2/3] Compiling the application...
echo Compiler: g++
echo Standard: C++11
echo Output: quiz_game.exe
echo.

REM Compile the application with g++
REM -std=c++11: Use C++11 standard
REM -O2: Enable optimization level 2
REM -Wall: Enable all warnings
g++ -std=c++11 -O2 -Wall main.cpp -o quiz_game.exe

REM Check if compilation was successful
if %ERRORLEVEL% EQU 0 (
    echo [OK] Build successful!
    echo.
    echo [3/3] Executable created: quiz_game.exe
    echo.
    
    REM Ask user if they want to run the application
    set /p run_choice="Would you like to run the application now? (Y/N): "
    
    if /i "!run_choice!"=="Y" (
        echo.
        echo ============================================
        echo   Running Quiz Game Application...
        echo ============================================
        echo.
        quiz_game.exe
        echo.
        echo ============================================
        echo   Application finished.
        echo ============================================
    ) else (
        echo.
        echo You can run the application later by executing: quiz_game.exe
    )
) else (
    echo [ERROR] Build failed!
    echo Please check the error messages above and fix any issues.
    echo.
    echo Common issues:
    echo - Syntax errors in source code
    echo - Missing header files
    echo - Compiler compatibility issues
)

echo.
exit /b 0