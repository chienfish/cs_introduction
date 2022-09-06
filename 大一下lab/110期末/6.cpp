#include <iostream>
#include <cstdlib>
#include <curses.h>
#include <unistd.h>


int main()
{
    initscr();
    curs_set(0);
    char x1='0', x2='0', x3='0', 
        x4='0', x5='0', x6='0', 
        x7='0', x8='0', x9='0';

    mvaddch(4, 19, '0');//左上x1
    mvaddch(5, 19, '0');//中上x2
    mvaddch(6, 19, '0');//右上x3
    mvaddch(4, 20, '0');//左中x4
    mvaddch(5, 20, '0');//中心x5
    mvaddch(6, 20, '0');//右中x6
    mvaddch(4, 21, '0');//左下x7
    mvaddch(5, 21, '0');//中下x8
    mvaddch(6, 21, '0');//右下x9
    refresh();

    for(int i = 0; i < 9*9 ; i++)
    {
        int r = rand() % 9 + 1;
        if(r == 1)
        {
            x1 += 1;
            mvaddch(4, 19,x1);
            refresh();
            if(x1 == '9')
            {
                getch();
                break;
            }
        }
        if(r == 2)
        {
            x2 += 1;
            mvaddch(4, 20,x2);
            refresh();
            if(x2 == '9')
            {
                getch();
                break;
            }
        }
        if(r == 3)
        {
            x3 += 1;
            mvaddch(4, 21,x3);
            refresh();
            if(x3 == '9')
            {
                getch();
                break;
            }
        }
        if(r == 4)
        {
            x4 += 1;
            mvaddch(5, 19,x4);
            refresh();
            if(x4 == '9')
            {
                getch();
                break;
            }
        }
        if(r == 5)
        {
            x5 += 1;
            mvaddch(5, 20,x5);
            refresh();
            if(x5 == '9')
            {
                getch();
                break;
            }
        }
        if(r == 6)
        {
            x6 += 1;
            mvaddch(5, 21,x6);
            refresh();
            if(x6 == '9')
            {
                getch();
                break;
            }
        }
        if(r == 7)
        {
            x7 += 1;
            mvaddch(6, 19,x7);
            refresh();
            if(x7 == '9')
            {
                getch();
                break;
            }
        }
        if(r == 8)
        {
            x8 += 1;
            mvaddch(6, 20,x8);
            refresh();
            if(x8 == '9')
            {
                getch();
                break;
            }
        }
        if(r == 9)
        {
            x9 += 1;
            mvaddch(6, 21,x9);
            refresh();
            if(x9 == '9')
            {
                getch();
                break;
            }
        }

        usleep(500000);
        
    }
    return 0;
}
