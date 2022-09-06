#include <curses.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include<time.h>
using namespace std;

int main()
{
    initscr();
    srand(time(0));
    keypad(stdscr, TRUE);
    curs_set(0);
    start_color();
    init_pair(1, COLOR_RED,COLOR_BLACK);
    attron(COLOR_PAIR(1));
    int y = (LINES / 2), x = (COLS / 2);
    int num, path;
    mvaddch(y, x, '*');
    refresh();
    usleep(100000);
    num = rand() % 100 + 1;
    if (num >= 1 && num <= 25)
    {
        mvaddch(y, x, ' ');
        path = 0;
        y = y - 1;
    }
    else if (num >= 26 && num <= 50)
    {
        mvaddch(y, x, ' ');
        path = 1;
        y = y + 1;
    }
    else if (num >= 51 && num <= 75)
    {
        mvaddch(y, x, ' ');
        path = 2;
        x = x - 1;
    }
    else if (num >= 76 && num <= 100)
    {
        mvaddch(y, x, ' ');
        path = 3;
        x = x + 1;
    }
    mvaddch(y, x, '*');
    refresh();
    usleep(100000);
    while (true)
    {
        mvaddch(y, x, ' ');
        num = rand() % 100 + 1;
        if((x==0&&y==0)||(x==0&&y==23)||(x==79&&y==0)||(x==79&&y==23))
        {
            if (x==0&&y==0)
            {
                if(num>=1&&num<=50)
                {
                    path=1;
                    y=y+1;
                }
                if(num>=51&&num<=100)
                {
                    path=3;
                    x=x+1;
                }
            }
            if (x==0&&y==23)
            {
                if(num>=1&&num<=50)
                {
                    path=0;
                    y=y-1;
                }
                if(num>=51&&num<=100)
                {
                    path=3;
                    x=x+1;
                }
            }
            if (x==79&&y==0)
            {
                if(num>=1&&num<=50)
                {
                    path=1;
                    y=y+1;
                }
                if(num>=51&&num<=100)
                {
                    path=2;
                    x=x-1;
                }
            }
            if (x==79&&y==23)
            {
                if(num>=1&&num<=50)
                {
                    path=0;
                    y=y-1;
                }
                if(num>=51&&num<=100)
                {
                    path=2;
                    x=x-1;
                }
            }
        }
        else if (x == 0 || x == 79 || y == 0 || y == 23)
        {
            if (x == 0)
            {
                if (num >= 1 && num <= 33)
                {
                    path = 0;
                    y = y - 1;
                }
                if (num >= 34 && num <= 66)
                {
                    path = 1;
                    y = y + 1;
                }
                if (num >= 67 && num <= 100)
                {
                    path = 3;
                    x = x + 1;
                }
            }
            if (x == 79)
            {
                if (num >= 1 && num <= 33)
                {
                    path = 0;
                    y = y - 1;
                }
                if (num >= 34 && num <= 66)
                {
                    path = 1;
                    y = y + 1;
                }
                if (num >= 67 && num <= 100)
                {
                    path = 2;
                    x = x - 1;
                }
            }
            if (y == 0)
            {
                if (num >= 1 && num <= 33)
                {
                    path = 1;
                    y = y + 1;
                }
                if (num >= 34 && num <= 66)
                {
                    path = 2;
                    x = x - 1;
                }
                if (num >= 67 && num <= 100)
                {
                    path = 3;
                    x = x + 1;
                }
            }
            if (y == 23)
            {
                if (num >= 1 && num <= 33)
                {
                    path = 2;
                    x = x - 1;
                }
                if (num >= 34 && num <= 66)
                {
                    path = 0;
                    y = y - 1;
                }
                if (num >= 67 && num <= 100)
                {
                    path = 3;
                    x = x + 1;
                }
            }
        }
        else
        {
            if (path == 0)
            {
                if (num >= 1 && num <= 85)
                {
                    path = 0;
                    y = y - 1;
                }
                if (num >= 86 && num <= 90)
                {
                    path = 1;
                    y = y + 1;
                }
                if (num >= 91 && num <= 95)
                {
                    path = 2;
                    x = x - 1;
                }
                else if (num >= 96 && num <= 100)
                {
                    path = 3;
                    x = x + 1;
                }
            }
            else if (path == 1)
            {
                if (num >= 1 && num <= 85)
                {
                    path = 1;
                    y = y + 1;
                }
                if (num >= 86 && num <= 90)
                {
                    path = 0;
                    y = y - 1;
                }
                if (num >= 91 && num <= 95)
                {
                    path = 2;
                    x = x - 1;
                }
                if (num >= 96 && num <= 100)
                {
                    path = 3;
                    x = x + 1;
                }
            }
            else if (path == 2)
            {
                if (num >= 1 && num <= 85)
                {
                    path = 2;
                    x = x - 1;
                }
                if (num >= 86 && num <= 90)
                {
                    path = 1;
                    y = y + 1;
                }
                if (num >= 91 && num <= 95)
                {
                    path = 0;
                    y = y - 1;
                }
                if (num >= 96 && num <= 100)
                {
                    path = 3;
                    x = x + 1;
                }
            }
            else if (path == 3)
            {
                if (num >= 1 && num <= 85)
                {
                    path = 3;
                    x = x + 1;
                }
                if (num >= 86 && num <= 90)
                {
                    path = 1;
                    y = y + 1;
                }
                if (num >= 91 && num <= 95)
                {
                    path = 2;
                    x = x - 1;
                }
                if (num >= 96 && num <= 100)
                {
                    path = 0;
                    y = y - 1;
                }
            }
        }
        mvaddch(y, x, '*');
        refresh();
        usleep(100000);
    }
}
