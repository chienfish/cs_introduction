#include<iostream>
using namespace std;
void spacestar (int space, int star)
{
    for (int i = 0; i < space; i++)
    {
        cout << " ";
    }
    for (int i = 0; i < star; i++)
    {
        cout << "*";
    }
}
int main()
{
    int k;
    cin >> k;
    for(int i = 1; i <= k; i++)
    {
        spacestar((k-i),(2*i-1));
        cout << endl;
    }
}