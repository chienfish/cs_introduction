#include <iostream>
using namespace std;

int GCD(int a, int b);

int main()
{
    int x, y;
    while (cin >> x >> y)
    {
        int result = GCD(x,y);
        if (x <= 0 || y <= 0)
            return 0;
        else
            cout << result << endl;
    }
}

int GCD(int a, int b)
{
    if (a > 0 && b > 0)
        return GCD(b,a%b);
    else if (a == 0)
        return b;
    else if (b == 0)
        return a;
}