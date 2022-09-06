#include <iostream>
using namespace std;

int f(int m)
{
    if (m == 0 || m == 1)
        return 1;
    else
    {
        return 2 * f(m-1) + f(m-2);
    }
}


int main()
{
    int x;
    cin >> x;
    cout << f(x) << endl;

    return 0;
}