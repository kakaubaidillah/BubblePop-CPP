@echo off

cd /d "%~dp0.."

"C:\mingw64\bin\g++.exe" ^
src\main.cpp ^
src\bubble.cpp ^
src\ui.cpp ^
src\game.cpp ^
src\menu.cpp ^
src\input.cpp ^
src\gameover.cpp ^
-I"C:\raylib\raylib\src" ^
-L"C:\raylib\raylib\src" ^
-lraylib -lgdi32 -lwinmm -lopengl32 ^
-o BubblePop.exe

pause