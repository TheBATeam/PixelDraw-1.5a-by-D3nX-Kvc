@Echo off
cls

Title PixelDraw 1.5a - Demo - www.thebateam.org
Set "Path=%Path%;%cd%;%cd%\files"
Color 0a

set x=100
set y=100

::Draw pixel
PIXELDRAW /p 20 20 /c 9
::Draw line
PIXELDRAW /dl 0 0 /lh 15 /v /rgb 0 128 128
PIXELDRAW /dl 1 0 /lh 15 /h /rgb 128 0 128
::Draw line width start and end point
PIXELDRAW /dl /p 50 50 60 60 /rgb 255 255 255
::Draw circle
PIXELDRAW /dc %x% %y% /cr 15 /rgb 255 255 128
::Draw square
PIXELDRAW /ds 64 64 /sh 4 /rgb 128 128 128
::Draw rectangle
PIXELDRAW /dr 80 80 /rd 10 15 /c c
::Draw triangle
PIXELDRAW /dt /p 0 0 10 10 20 0 /rgb 255 255 255

Pause
::Refresh screen
PIXELDRAW /REFRESH 0f

echo Refreshed
echo Now enjoy using PixelDraw in your batch program !
pause