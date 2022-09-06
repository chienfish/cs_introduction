#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
void myOutput(T x, T y) 
{
    cout << "SYSTEM LOG:[M1:" << x << "][M2:" << y << "]" << endl;
}


int main()
{
    int a;

    while(cin >> a)
    {
        if (a == 0)
            break;
        else if (a == 1)
        {
            int b, c;
            cin >> b >> c;
            myOutput(b, c);
        }
        else if (a == 2)
        {
            string d, e;
            cin >> d >> e;
            myOutput(d, e);
        }
        else
        {
            double f, g;
            cin >> f >> g;
            myOutput(f, g);
        }
    }

    return 0;
}