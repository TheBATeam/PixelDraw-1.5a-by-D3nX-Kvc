@Echo off
cls

Title PixelDraw 1.5a - Demo - www.thebateam.org
Set "Path=%Path%;%cd%;%cd%\files"
Color 0a
SetLocal EnableDelayedExpansion
Mode 120,35
Cls
For /l %%a in (0,1,300) do (
	Pixeldraw /dc 450 275 /cr %%a /rgb !Random:~0,3! !Random:~0,3! !Random:~0,3!
	REM PixelDraw /refresh 07
)
pause
exit