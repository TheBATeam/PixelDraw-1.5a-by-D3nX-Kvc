@Echo off
cls

Title PixelDraw 1.5a - Demo - www.thebateam.org
Set "Path=%Path%;%cd%;%cd%\files"
Color 0a

Setlocal EnableDelayedExpansion
mode 120,40
Set color=255 100 100

::For /l %%A in (0,1,255) do (
::Set color=%%A %%A %%A

PixelDraw /dl /p 50 240 275 55 /rgb !color!
PixelDraw  /dl /p 275 55 445 120 /rgb !color!


PixelDraw /dl /p 445 120 430 75 /rgb !color!
PixelDraw /dl /p 430 75 460 100 /rgb !color!


PixelDraw /dl /p 460 100 475 85 /rgb !color!
PixelDraw /dl /p 475 85 490 100 /rgb !color!


PixelDraw /dl /p 490 100 520 75 /rgb !color!
PixelDraw /dl /p 520 75 505 120 /rgb !color!


PixelDraw /dl /p 505 120 675 55 /rgb !color!
PixelDraw /dl /p 675 55 900 240 /rgb !color!


PixelDraw /dl /p 900 240 675 255 /rgb !color!
PixelDraw /dl /p 675 255 475 450 /rgb !color!


PixelDraw /dl /p 475 450 275 255 /rgb !color!
PixelDraw /dl /p 275 255 50 240 /rgb !color!
::)







pause