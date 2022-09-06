#include <iostream>
#include <stdlib.h>
using namespace std;

bool checkNumber(int x);
int generateNumber();
bool cmpNumber(int x, int y);

int main()
{
    int s;
    int x,y;
    cin >> s;
    srand(s);

    x = generateNumber();

    cin >> y;
    while (y != 0){
        
        if (cmpNumber(x, y) == true)
            return 0;
        else 
            cin >> y;
    }

    cout << x << endl;
    return 0;
}

bool checkNumber(int x)
{
    int d1,d2,d3,d4;
    
    d1 = x / 1000;
    d2 = (x / 100) % 10;
    d3 = (x / 10) % 10;
    d4 = x % 10;

    if (d1 == d2 || d1 == d3 || d1 == d4
     || d2 == d3 || d2 == d4 || d3 == d4)
        return false;
    else
        return true;
}

int generateNumber()
{
    int x = rand() % 9754 + 123;

    while (checkNumber(x) == false){
        x = rand() % 9754 + 123;
    }

    return x;
}

bool cmpNumber(int x, int y)
{
    int i=0,j=0;
    int d1,d2,d3,d4;
    d1 =  x / 1000;
    d2 = (x / 100) % 10;
    d3 = (x / 10) % 10;
    d4 =  x % 10;

    int g1,g2,g3,g4;
    g1 =  y / 1000;
    g2 = (y / 100) % 10;
    g3 = (y / 10) % 10;
    g4 =  y % 10;

    if (x == y){
        cout << "4A0B" << endl;
        return true;
    }
    
    if(g1==d2 || g1==d3 || g1==d4)
        j++;
    else if (g1==d1)
        i++;
    if(g2==d1 || g2==d3 || g2==d4)
        j++;
    else if (g2==d2)
        i++;
    if(g3==d1 || g3==d2 || g3==d4)
        j++;
    else if (g3==d3)
        i++;
    if(g4==d1 || g4==d2 || g4==d3)
        j++;
    else if (g4==d4)
        i++;

    cout << i << "A" << j << "B" << endl;
    return false;
}