#include <curses.h>
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

#define EMPTY 0
#define PRODUCER 1  // 生產者 => *
#define CONSUMER 2  // 消費者 => X

int t = 0;
int die[24][80];
bool eat[24][80];

//生產者移動
void move_producer(int arr[24][80])
{
    bool counted[24][80];
    for (int i = 1; i < 23; i++)
    {
        for (int j = 1; j < 79; j++) 
            counted[i][j] = false;
    }
        
    for (int i = 1; i < 23; i++) {
        for (int j = 1; j < 79; j++) {
            if ((!counted[i][j]) && arr[i][j] == PRODUCER ) {
                int neigh_count = 0;
                int limit = 9;
                for (int a = -1; a <= 1; a++) {
                    for (int b = -1; b <= 1; b++) {
                        if (i+a >= 1 && i+a <= 22 && j+b >= 1 && j+b <= 78) {
                            if (arr[i+a][j+b] != EMPTY) {
                                neigh_count += 1;
                            } 
                        } else {
                            limit -= 1;
                        }
                    }
                }

                if (neigh_count >= limit) {
                    continue;
                } else {
                    int mov_x = rand() % 3 - 1;
                    int mov_y = rand() % 3 - 1;
                    int new_y = min(max(i+mov_y, 1), 22);
                    int new_x = min(max(j+mov_x, 1), 78);

                    
                    while (arr[new_y][new_x] != EMPTY) {
                        mov_x = rand() % 3 - 1;
                        mov_y = rand() % 3 - 1;
                        new_x = min(max(j+mov_x, 1), 78);
                        new_y = min(max(i+mov_y, 1), 22);
                    }

                    
                    
                    mvaddch(i, j, ' ');
                    mvaddch(new_y, new_x, '*');

                    arr[i][j] = EMPTY;
                    arr[new_y][new_x] = PRODUCER;
                    counted[new_y][new_x] = true;
                }
            }
        }
    }
    refresh();
}

//生產者複製
void copy_producer(int arr[24][80])
{
    bool counted[24][80];
    for (int i = 1; i < 23; i++)
    {
        for (int j = 1; j < 79; j++) 
            counted[i][j] = false;
    }
        
    for (int i = 1; i < 23; i++) {
        for (int j = 1; j < 79; j++) {
            if ((!counted[i][j]) && arr[i][j] == PRODUCER) {
                int neigh_count = 0;
                int limit = 9;
                for (int a = -1; a <= 1; a++) {
                    for (int b = -1; b <= 1; b++) {
                        if (i+a >= 1 && i+a <= 22 && j+b >= 1 && j+b <= 78) {
                            if (arr[i+a][j+b] != EMPTY) {
                                neigh_count += 1;
                            } 
                        } else {
                            limit -= 1;
                        }
                    }
                }

                if (neigh_count >= limit) {
                    continue;
                } else {
                    int mov_x = rand() % 3 - 1;
                    int mov_y = rand() % 3 - 1;
                    int new_y = min(max(i+mov_y, 1), 22);
                    int new_x = min(max(j+mov_x, 1), 78);

                    
                    while (arr[new_y][new_x] != EMPTY) {
                        mov_x = rand() % 3 - 1;
                        mov_y = rand() % 3 - 1;
                        new_x = min(max(j+mov_x, 1), 78);
                        new_y = min(max(i+mov_y, 1), 22);
                    }

                    mvaddch(new_y, new_x, '*');

                    arr[i][j] = PRODUCER;
                    arr[new_y][new_x] = PRODUCER;
                    counted[new_y][new_x] = true;
                }
            }
        }
    }
    refresh();  
}


//消費者移動&吃生產者
void move_consumer(int arr[24][80])
{
    bool counted[24][80];
    for (int i = 1; i < 23; i++)
    {
        for (int j = 1; j < 79; j++) 
            counted[i][j] = false;
    }
        
    for (int i = 1; i < 23; i++) {
        for (int j = 1; j < 79; j++) {
            if ((!counted[i][j]) && arr[i][j] == CONSUMER) {
                int neigh_count = 0;
                int limit = 9;
                for (int a = -1; a <= 1; a++) {
                    for (int b = -1; b <= 1; b++) {
                        if (i+a >= 1 && i+a <= 22 && j+b >= 1 && j+b <= 78) {
                            if (arr[i+a][j+b] == CONSUMER) {
                                neigh_count += 1;
                            } 
                        } else {
                            limit -= 1;
                        }
                    }
                }

                if (neigh_count >= limit) {
                    continue;
                } else {
                    int mov_x = rand() % 3 - 1;
                    int mov_y = rand() % 3 - 1;
                    int new_y = min(max(i+mov_y, 1), 22);
                    int new_x = min(max(j+mov_x, 1), 78);

                    
                    while (arr[new_y][new_x] == CONSUMER) {
                        mov_x = rand() % 3 - 1;
                        mov_y = rand() % 3 - 1;
                        new_x = min(max(j+mov_x, 1), 78);
                        new_y = min(max(i+mov_y, 1), 22);
                    }

                    mvaddch(i, j, ' ');
                    mvaddch(new_y, new_x, 'X');

                    if (arr[new_y][new_x] == EMPTY){
                        die[new_y][new_x] = die[i][j];
                        eat[new_y][new_x] = false;
                    } else if (arr[new_y][new_x] == PRODUCER){
                        die[new_y][new_x] = 4;
                        eat[new_y][new_x] = true;
                    }
                        
                    arr[i][j] = EMPTY;
                    arr[new_y][new_x] = CONSUMER;
                    counted[new_y][new_x] = true;
                }
            }
        }
    }
    refresh();
}


//消費者複製
void copy_consumer(int arr[24][80])
{
    bool counted[24][80];
    for (int i = 1; i < 23; i++)
    {
        for (int j = 1; j < 79; j++) 
            counted[i][j] = false;
    }
        
    for (int i = 1; i < 23; i++) {
        for (int j = 1; j < 79; j++) {
            if ((!counted[i][j]) && (arr[i][j] == CONSUMER) && (eat[i][j] == true)) {
                int neigh_count = 0;
                int limit = 9;
                for (int a = -1; a <= 1; a++) {
                    for (int b = -1; b <= 1; b++) {
                        if (i+a >= 1 && i+a <= 22 && j+b >= 1 && j+b <= 78) {
                            if (arr[i+a][j+b] != EMPTY) {
                                neigh_count += 1;
                            } 
                        } else {
                            limit -= 1;
                        }
                    }
                }

                if (neigh_count >= limit) {
                    continue;
                } else {
                    int mov_x = rand() % 3 - 1;
                    int mov_y = rand() % 3 - 1;
                    int new_y = min(max(i+mov_y, 1), 22);
                    int new_x = min(max(j+mov_x, 1), 78);

                    
                    while (arr[new_y][new_x] != EMPTY) {
                        mov_x = rand() % 3 - 1;
                        mov_y = rand() % 3 - 1;
                        new_x = min(max(j+mov_x, 1), 78);
                        new_y = min(max(i+mov_y, 1), 22);
                    }
                    
                    mvaddch(new_y, new_x, 'X');

                    die[new_y][new_x] = 4;
                    arr[i][j] = CONSUMER;
                    arr[new_y][new_x] = CONSUMER;
                    counted[new_y][new_x] = true;
                }
            }
        }
    }
    refresh();    
}

//消費者死亡
void die_consumer(int arr[24][80])
{
    for (int i = 1; i < 23; i++) {
        for (int j = 1; j < 79; j++) {
            if ((arr[i][j] == CONSUMER) && (die[i][j] == 0) && eat[i][j] == false) {
                
                arr[i][j] = EMPTY;
                mvaddch(i, j, ' ');
            }
        }
    }
    refresh();
}



int main()
{
    int producer, consumer;
    cin >> producer >> consumer;
    
    initscr();
    curs_set(0);
    for (int ix = 0; ix < 80; ix++) 
    {
        move(0, ix);
        addch('.');
        move(23, ix);
        addch('.');
    }
    for (int iy = 0; iy < 24; iy++) 
    {
        move(iy, 0);
        addch('.');
        move(iy, 79);
        addch('.');
    }

    refresh();

    int array[24][80];
    for(int i = 0; i < 24; i++) {
        for (int j = 0; j < 80; j++) {
            array[i][j] = EMPTY;
        }
    }

    int p_pro_x ,p_pro_y;
    for (int i = 0; i < producer; i++)//放生產者
    {
        p_pro_x = rand() % 78 + 1;
        p_pro_y = rand() % 22 + 1;

        while (array[p_pro_y][p_pro_x] != EMPTY) {
            p_pro_x = rand() % 78 + 1;
            p_pro_y = rand() % 22 + 1;
        }
        mvaddch(p_pro_y, p_pro_x, '*');
        array[p_pro_y][p_pro_x] = PRODUCER;
        refresh();
    }

    int c_pro_x, c_pro_y;
    for (int i = 0; i < consumer; i++)//放消費者
    {
        c_pro_x = rand() % 78 + 1;
        c_pro_y = rand() % 22 + 1;

        while (array[c_pro_y][c_pro_x] != EMPTY) {
            c_pro_x = rand() % 78 + 1;
            c_pro_y = rand() % 22 + 1;
        }
        mvaddch(c_pro_y, c_pro_x, 'X');
        array[c_pro_y][c_pro_x] = CONSUMER;
        die[c_pro_y][c_pro_x] = 4;
        eat[c_pro_y][c_pro_x] = false;
        refresh();
    }

    usleep(500000);

    while (true) {
        t += 1;
        move_producer(array);
        usleep(500000);

        move_consumer(array);
        usleep(500000);

        copy_consumer(array);
        usleep(500000);

        if(t % 3 == 1 && t != 1)
            copy_producer(array);
        
        die_consumer(array);


        for (int i = 1; i < 23; i ++) {
            for (int j = 1; j < 79; j ++) {
                if (array[i][j] == CONSUMER) 
                    die[i][j] -= 1;
            }
        }
        for (int i = 1; i < 23; i++){
            for (int j = 1; j < 79; j++) 
                eat[i][j] = false;
        }        
    }

    endwin();
    return 0;
}