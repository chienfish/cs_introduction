#include <iostream>
using namespace std;

int main()
{
    int x,y = 0;
    cin >> x;

    for (int i = 1;; i++)
    {
        y += i;

        if (y - x > 0 && x - y + i >= 0)
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}