#include <iostream>
using namespace std;

int main()
{
    int c,y;
    int w,m,d;

    cin >> y >> m >> d;

    switch (m){
        case (1) : case(2):
            y = y - 1;
            m = m + 12;
            break;
    }

    if (y < 1582 || (y == 1582 && m < 10)
                    || (y == 1582 && m <= 10 && d <= 4)){
      
    c = y / 100;
    y = y % 100;
    m = 26 * (m + 1);
    m = m / 10;
    // m的乘除要分開算，因為一次最多只能做一件事。
      
        w = (y + (y/4) - c + m + d + 4);
        w = ( w % 7 + 7 ) % 7;
    } else {
     c = y / 100;
     y = y % 100;
     m = 26 * (m + 1);
     m = m / 10;
    // m的乘除要分開算，因為一次最多只能做一件事。
      
        w = (y + (y/4) + (c/4) - 2*c + m + d - 1) ;
        w = ( w % 7 + 7 ) % 7;
    }

    cout << w << endl;
} 