#include<iostream>
using namespace std;
int main()
{
    int c = 0, w = 0;
    int y = 0, m = 0, d = 0;
    cin >> y >> m >> d;
    

    switch(m)
    {
        case 1: case 2:
            m = m + 12;
            y = y - 1;
            break;
    }
    
    if (y < 1582 || (y == 1582 && m < 10) 
                 || (y == 1582 && m <= 10 && d <= 4))
    {
        c=y/100;
        y=y%100;
        
        m = 26 * (m + 1);
        m = m / 10;
        w=(y+(y/4)-c+m+d+4);//<1582 10 4
        w=(w%7+7)%7;
    
    } else {
        c=y/100;
        y=y%100;
       
        m = 26 * (m + 1);
        m = m / 10;
        w=(y+(y/4)+(c/4)-(2*c)+m+d-1);//>1582
        w=(w%7+7)%7; 
    }
    
    cout << w << endl;
}