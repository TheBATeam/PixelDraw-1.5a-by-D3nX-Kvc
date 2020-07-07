/*
UniBatch Team - 2017
PIXELDRAW 1.5a - By D3nX & Kvc
*/
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;

//Global variable
#define PI 3.14
COLORREF color = RGB(0,0,0);

double getlength_x(int len, int dir)
{
    return cos(dir * PI / 180) * len;
}

double getlength_y(int len, int dir)
{
    return sin(dir * PI / 180) * len;
}

//Here a function for color
const COLORREF setcolor(string input)
{
    //Set the color
    if (input == "0")
    {
        color = RGB(0,0,0);
    }
        else if (input == "1")
    {
        color = RGB(0,0,128);
    }
        else if (input == "2")
    {
        color = RGB(0,128,0);
    }
        else if (input == "3")
    {
        color = RGB(0,128,128);
    }
        else if (input == "4")
    {
        color = RGB(128,0,0);
    }
        else if (input == "5")
    {
        color = RGB(128,0,128);
    }
    else if (input == "6")
    {
        color = RGB(128,128,0);
    }
    else if (input == "7")
    {
        color = RGB(192,192,192);
    }
    else if (input == "8")
    {
        color = RGB(128,128,128);
    }
    else if (input == "9")
    {
        color = RGB(0,0,255);
    }
    else if (input == "a" || input == "A")
    {
        color = RGB(0,255,0);
    }
    else if (input == "b" || input == "B")
    {
        color = RGB(0,255,255);
    }
    else if (input == "c" || input == "C")
    {
        color = RGB(255,0,0);
    }
    else if (input == "d" || input == "D")
    {
        color = RGB(255,0,255);
    }
        else if (input == "e" || input == "E")
    {
        color = RGB(255,255,0);
    }
    else if (input == "f" || input == "F")
    {
        color = RGB(255,255,255);
    }

    //Return the color
    return color;
}

int main(int argn, const char *arg[])
{
    HWND console = GetConsoleWindow();
    HDC device = GetDC(console);

    if (argn == 1) exit(0);

    if (argn == 0)
        system("exit");

    string command[argn];

    for (int i = 0; i < argn; i++)
    {
        command[i] = arg[i];
    };

    if (command[1] == "/p" && (command[4] == "/c" || "/rgb"))
    {
        //set the color
        if (command[4] == "/rgb")
        {
            stringstream ss_r;
            stringstream ss_g;
            stringstream ss_b;
            ss_r << command[5];
            ss_g << command[6];
            ss_b << command[7];

            int r;
            int g;
            int b;
            ss_r >> r;
            ss_g >> g;
            ss_b >> b;

            color = RGB(r,g,b);
        }
        else if (command[4] == "/c")
        {
            color = setcolor(command[5]);
        }


        //Convert string to int
        stringstream strValue_a;
        stringstream strValue_b;
        strValue_a << command[2];
        strValue_b << command[3];


        int x;
        int y;
        strValue_a >> x;
        strValue_b >> y;

        //Draw the pixel
        SetPixel(device, x, y, color);

        return 0;
    }
    //Line draw
    else if (command[1] == "/dl" && command[4] == "/lh" && (command[6] == "/v" || "/h") && (command[7] == "/c" || "/rgb"))
    {
        //set the color
        if (command[7] == "/rgb")
        {
            stringstream ss_r;
            stringstream ss_g;
            stringstream ss_b;
            ss_r << command[8];
            ss_g << command[9];
            ss_b << command[10];

            int r;
            int g;
            int b;
            ss_r >> r;
            ss_g >> g;
            ss_b >> b;

            color = RGB(r,g,b);
        }
        else if (command[7] == "/c")
        {
            color = setcolor(command[7]);
        }

        //Convert string to int
        stringstream strValue_a;
        stringstream strValue_b;
        stringstream strValue_c;
        strValue_a << command[2];
        strValue_b << command[3];
        strValue_c << command[5];


        int x;
        int y;
        int h;
        strValue_a >> x;
        strValue_b >> y;
        strValue_c >> h;

        //Draw the line of pixel
        if (command[6] == "/v") {
            for (int i = y; i<(y+h); i++)
            {
                SetPixel(device, x, i, color);
            }
        }
        else if (command[6] == "/h")
        {
            for (int i = x; i<(x+h); i++)
            {
                SetPixel(device, i, y, color);
            }
        }

    }
    //Line point draw
    else if (command[1] == "/dl" && command[2] == "/p" && (command[7] == "/c" || "/rgb"))
    {
        //set the color
        if (command[7] == "/rgb")
        {
            stringstream ss_r;
            stringstream ss_g;
            stringstream ss_b;
            ss_r << command[8];
            ss_g << command[9];
            ss_b << command[10];

            int r;
            int g;
            int b;
            ss_r >> r;
            ss_g >> g;
            ss_b >> b;

            color = RGB(r,g,b);
        }
        else if (command[7] == "/c")
        {
            color = setcolor(command[8]);
        }

        //Convert string to int
        stringstream str_x1;
        stringstream str_y1;
        stringstream str_x2;
        stringstream str_y2;
        str_x1 << command[3];
        str_y1 << command[4];
        str_x2 << command[5];
        str_y2 << command[6];

        //And put it in the int
        int x1, x2, y1, y2;
        str_x1 >> x1;
        str_y1 >> y1;
        str_x2 >> x2;
        str_y2 >> y2;

        int stepy=1;
        int stepx=1;

        int dx = x2 - x1;
        int dy = y2 - y1;

        if (dy<0) {
            dy=dy*-1;
            stepy=-1;
        }

        if (dx<0) {
            dx=dx*-1;
            stepx=-1;
        }

        dy <<= 1;
        dx <<= 1;

        int x=x1;
        int y=y1;

        if (dx>dy) {
            int fraction=dy-(dx>>1);

            // loop variable...
            int i=x1;

            while (i!=x2) {
                SetPixel(device,x,y,color);
                if (fraction>=0) {
                    y+=stepy;
                    fraction-=dx;
                }
                fraction+=dy;
                x+=stepx;
                i+=stepx;
            }

        } else {
            int fraction=dx-(dy>>1);

            // loop variable...
            int i=y1;

            while (i!=y2) {
                SetPixel(device,x,y, color);
                if (fraction>=0) {
                    x+=stepx;
                    fraction-=dy;
                }
                fraction+=dx;
                y+=stepy;
                i+=stepy;
            }
        }


    }
    //Circle draw
    else if (command[1] == "/dc" && command[4] == "/cr" && (command[6] == "/c" || "/rgb"))
    {
        //set the color
        if (command[6] == "/rgb")
        {
            stringstream ss_r;
            stringstream ss_g;
            stringstream ss_b;
            ss_r << command[7];
            ss_g << command[8];
            ss_b << command[9];

            int r;
            int g;
            int b;
            ss_r >> r;
            ss_g >> g;
            ss_b >> b;

            color = RGB(r,g,b);
        }
        else if (command[6] == "/c")
        {
            color = setcolor(command[7]);
        }



        //Convert string to int
        stringstream strValue_a;
        stringstream strValue_b;
        stringstream strValue_c;
        strValue_a << command[2];
        strValue_b << command[3];
        strValue_c << command[5];


        int x;
        int y;
        int radius;
        strValue_a >> x;
        strValue_b >> y;
        strValue_c >> radius;

        for (unsigned int i = 0; i < 360; i++)
        {
            SetPixel(device, x + getlength_x(radius, i), y + getlength_y(radius, i), color);
        }

    }
    //Square draw
    else if (command[1] == "/ds" && command[4] == "/sh" && (command[6] == "/rgb" || "/c"))
    {
        //set the color
        if (command[6] == "/rgb")
        {
            stringstream ss_r;
            stringstream ss_g;
            stringstream ss_b;
            ss_r << command[7];
            ss_g << command[8];
            ss_b << command[9];

            int r;
            int g;
            int b;
            ss_r >> r;
            ss_g >> g;
            ss_b >> b;

            color = RGB(r,g,b);
        }
        else if (command[6] == "/c")
        {
            color = setcolor(command[7]);
        }


        //Convert string to int
        stringstream strValue_a;
        stringstream strValue_b;
        stringstream strValue_c;
        strValue_a << command[2];
        strValue_b << command[3];
        strValue_c << command[5];


        int x;
        int y;
        int h;
        strValue_a >> x;
        strValue_b >> y;
        strValue_c >> h;
        h-=1;

        for (unsigned int i=0; i<(h+1); i++)
        {
            SetPixel(device, x, y+i, color);
            SetPixel(device, x+i, y, color);
            SetPixel(device, x+h, y+i, color);
            SetPixel(device, x+i, y+h, color);
        }

    }
    //Rectangle draw
    else if (command[1] == "/dr" && command[4] == "/rd" && (command[7] == "/c" || "/rgb"))
    {
        //set the color
        if (command[7] == "/rgb")
        {
            stringstream ss_r;
            stringstream ss_g;
            stringstream ss_b;
            ss_r << command[8];
            ss_g << command[9];
            ss_b << command[10];

            int r;
            int g;
            int b;
            ss_r >> r;
            ss_g >> g;
            ss_b >> b;

            color = RGB(r,g,b);
        }
        else if (command[7] == "/c")
        {
            color = setcolor(command[8]);
        }

        //Convert string to int
        stringstream strValue_a;
        stringstream strValue_b;
        stringstream strValue_c;
        stringstream strValue_d;
        strValue_a << command[2];
        strValue_b << command[3];
        strValue_c << command[5];
        strValue_d << command[6];


        int x;
        int y;
        int h;
        int w;
        strValue_a >> x;
        strValue_b >> y;
        strValue_c >> h;
        strValue_d >> w;
        h-=1;
        w-=1;

        for (unsigned int i = 0; i < (h+1); i++)
        {
            SetPixel(device, x+i, y, color);
            SetPixel(device, x+i, y+w, color);
        }

        for (unsigned int i = 0; i < (w+1); i++)
        {
            SetPixel(device, x, y+i, color);
            SetPixel(device, x+h, y+i, color);
        }

    }
    //Refresh
    if ((command[1] == "/refresh" || command[1] == "/REFRESH") && argn == 3)
    {
        string color = "color 06 & color 0f & color " + command[2];
        const char* setColor =  color.c_str();
        system(setColor);
    }
    //Triangle draw
    else if (command[1] == "/dt" && command[2] == "/p" && (command[9] == "/c" || "/rgb"))
    {
        //set the color
        if (command[9] == "/rgb")
        {
            stringstream ss_r;
            stringstream ss_g;
            stringstream ss_b;
            ss_r << command[10];
            ss_g << command[11];
            ss_b << command[12];

            int r;
            int g;
            int b;
            ss_r >> r;
            ss_g >> g;
            ss_b >> b;

            color = RGB(r,g,b);
        }
        else if (command[9] == "/c")
        {
            color = setcolor(command[10]);
        }

        //Convert string to int
        stringstream str_x1;
        stringstream str_y1;
        stringstream str_x2;
        stringstream str_y2;
        stringstream str_x3;
        stringstream str_y3;
        str_x1 << command[3];
        str_y1 << command[4];
        str_x2 << command[5];
        str_y2 << command[6];
        str_x3 << command[7];
        str_y3 << command[8];


        //And put it in the int
        int x1, x2, x3, y1, y2, y3;
        str_x1 >> x1;
        str_y1 >> y1;
        str_x2 >> x2;
        str_y2 >> y2;
        str_x3 >> x3;
        str_y3 >> y3;

        /*cout << x1 << " " << x2 << " " << x3 << endl;
        cout << y1 << " " << y2 << " " << y3 << endl;*/

        const int x1Bis = x1,
                  y1Bis = y1;

        //Get a handle to device context
        for (int e = 0; e < 3; e++) {

            if (e == 1)
            {
                x1 = x2;
                y1 = y2;
                x2 = x3;
                y2 = y3;
            }

            if (e == 2)
            {
                x1 = x3;
                y1 = y3;
                x2 = x1Bis;
                y2 = y1Bis;
            }

            int temp;

            int stepy=1;
            int stepx=1;

            int dx = x2 - x1;
            int dy = y2 - y1;

            if (dy<0) {
                dy=dy*-1;
                stepy=-1;
            }

            if (dx<0) {
                dx=dx*-1;
                stepx=-1;
            }

            dy <<= 1;
            dx <<= 1;

            int x=x1;
            int y=y1;

            if (dx>dy) {
                int fraction=dy-(dx>>1);

                // loop variable...
                int i=x1;

                while (i!=x2) {
                    SetPixel(device,x,y,color);
                    if (fraction>=0) {
                        y+=stepy;
                        fraction-=dx;
                    }
                    fraction+=dy;
                    x+=stepx;
                    i+=stepx;
                }

            } else {
                int fraction=dx-(dy>>1);

                // loop variable...
                int i=y1;

                while (i!=y2) {
                    SetPixel(device,x,y, color);
                    if (fraction>=0) {
                        x+=stepx;
                        fraction-=dy;
                    }
                    fraction+=dx;
                    y+=stepy;
                    i+=stepy;
                }
            }
        }


    }

    return 0;
}
