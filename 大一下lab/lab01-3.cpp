#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int s;
    int d1, d2, d3;
    cin >> s;
    srand(s);
    
    for (int i = 0; i < 1000; i++)
    {
        int num = rand() % 999 + 1;
        d1 = num / 100;
        d2 = (num % 100) / 10;
        d3 = num % 10;

        if (d1 == d2 || d1 == d3 || d2 == d3)
            cout << num << endl;
    }

    return 0;
}