@Echo off
cls

Title PixelDraw 1.5a - Demo - www.thebateam.org
Set "Path=%Path%;%cd%;%cd%\files"
Color 0a
cls
Setlocal enabledelayedexpansion
TItle Graphics test in CMD | PixelDraw

for /l %%a in (0,1,1000) do (Pixeldraw /dl /p !Random:~0,3! !Random:~0,3! !Random:~0,3! !Random:~0,3! /rgb !Random:~0,3! !Random:~0,3! !Random:~0,3! )
pause