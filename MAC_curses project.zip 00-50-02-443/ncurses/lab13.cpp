#include <iostream>
#include <cstdlib>
#include <curses.h>
#include <unistd.h>

using namespace std;
int main()
{
    initscr();
    curs_set(0);

    int s;
    srand(s);
    for (int ix = 0; ix < 80;ix++)
    {
        move(0, ix);
        addch('*');
        move(23, ix);
        addch('*');
    }
    for (int iy = 0; iy < 24;iy++)
    {
        move(iy, 0);
        addch('*');
        move(iy, 79);
        addch('*');
    }

    start_color();
    init_pair(1, COLOR_BLUE,COLOR_BLACK);
    attron(COLOR_PAIR(1));

    int dir, newdir;

    int x = 39, y = 11;
    mvaddch(y, x, 'o');
    refresh();
    usleep(100000);
    mvaddch(y, x, ' '); 

    int num = rand() % 100 + 1;
    if (num >= 1 && num <= 25) //往右
    {
        dir = 1;
        x++;
    }
    if (num >= 26 && num <= 50) //往左
    {
        dir = 2;
        x--;
    }
    if (num >= 51 && num <= 75) //往上
    {
        dir = 3;
        y--;
    }
    if (num >= 76 && num <= 100)  //往下
    {
        dir = 4;
        y++;
    }
    mvaddch(y, x, 'o');

    refresh();
    usleep(100000);

    int old_x ;
    int old_y ;
    while(true)
    {
        old_x = x;
        old_y = y;
        move(old_y, old_x);
        addch(' ');
        refresh();
        

        if (x == 1 && y == 1)//左上角
        {   
            //cout << "左上" << endl;
            num = rand() % 100 + 1;
            if(num <= 50)
                dir = 4;//往下
            else
                dir = 1;//往右

            switch(dir)
            {
                case 1:
                    x++;break;                 
                case 4:
                    y++;break;                  
            }
        }
        if (x == 1 && y == 22)//左下角
        {
            //cout << "左下" << endl;
            num = rand() % 100+1;

            if(num <= 50)
                dir = 3;//往上
            else
                dir = 1;//往右
            
            switch(dir)
            {
                case 1:
                    x++;break;                 
                case 3:
                    y--;break;                  
            }
        }
        if (x == 78 && y == 1)//右上角
        {
            //cout << "右上" << endl;
            num = rand() % 100+1;

            if(num <= 50)
                dir = 2;//往左
            else
                dir = 4;//往下
            
            switch(dir)
            {
                case 2:
                    x--;break;                 
                case 4:
                    y++;break;                  
            }
        }
        if (x == 78 && y == 22)//右下角
        {
            //cout << "右下" << endl;
            num = rand() % 100+1;

            if(num <= 50)
                dir = 2;//往左
            else
                dir = 3;//往上
            
            switch(dir)
            {
                case 2:
                    x--;break;                 
                case 3:
                    y--;break;                  
            }
        }


        if (x == 1 && y != 1 && y != 22)//在左牆邊不在角落
        {
            //cout << "左牆" << endl;
            num = rand() % 3 + 1;
            if (num == 1)
                dir = 1;//往右
            if (num == 2)
                dir = 3;//往上
            else 
                dir = 4;//往下

            switch(dir)
            {
                case 1:
                    x++;break;                 
                case 3:
                    y--;break;                  
                case 4:
                    y++;break;                 
            }
        }
        if (x == 78 && y != 1 && y != 22)//在右牆邊不在角落
        {
            //cout << "右牆" << endl;
            num = rand() % 3 + 1;
            if (num == 1)
                dir = 2;//往左
            if (num == 2)
                dir = 3;//往上
            else 
                dir = 4;//往下

            switch(dir)
            {
                case 2:
                    x--; break;             
                case 3:
                    y--; break;                
                case 4:
                    y++; break;                
            }
        }
        if (y == 1 && x != 1 && y != 78)//在上牆邊不在角落
        {
            //cout << "上牆" << endl;
            num = rand() % 3 + 1;
            if (num == 1)
                dir = 1;//往右
            if (num == 2)
                dir = 2;//往左
            else 
                dir = 4;//往下

            switch(dir)
            {
                case 1:
                    x++;break;                
                case 2:
                    x--;break;                 
                case 4:
                    y++;break;                 
            }
        }
        if (y == 22 && x != 1 && x != 78)//在下牆邊不在角落
        {
            //cout << "下牆" << endl;
            num = rand() % 3 + 1;
            if (num == 1)
                dir = 1;//往右
            if (num == 2)
                dir = 2;//往左
            else 
                dir = 3;//往上

            switch(dir)
            {
                case 2:
                    x--;break;
                case 3:
                    y--;break;                  
                case 1:
                    x++;break;                                
            }
        }


        if (x != 1 && y != 1 && x != 78 && y != 22)//不在牆邊
        {
            //cout << "隨便" << endl;
            num = rand() % 100 + 1;
            if (num >= 1 && num <= 85) //原方向
            {
                newdir = dir;
                dir = newdir;
            }
            if (num >= 86 && num <= 90)
            {
                newdir = (dir + 1) % 4;
                dir = newdir;
            }
            if (num >= 91 && num <= 95)
            {
                newdir = (dir + 1) % 4;
                dir = newdir;
            }
            if (num >= 96 && num <= 100)
            {
                newdir = (dir + 1) % 4;
                dir = newdir;
            }
            
            switch(dir)
            {
                case 1:
                    x++;break;           
                case 2:
                    x--;break;           
                case 3:
                    y--;break;           
                case 4:
                    y++;break;           
            }
        }
        mvaddch(y, x, 'o');

        refresh();
        usleep(100000);
    }

    endwin();
    return 0;
}