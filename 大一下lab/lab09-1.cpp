#include <iostream>
using namespace std;

int F (int n);

int main()
{
    int x;
    while(cin >> x)
    {
        if (x < 1)
            return 0;

        int result = F(x);
        cout << result << endl;
    }

}

int F (int n)
{
    if (n == 1)
        return 1;
    else if (n == 2)
        return 1;
    else 
        return F(n - 1) + F(n - 2);  
}