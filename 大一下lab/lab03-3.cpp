#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    int **arr;
    arr = new int *[m]; //二維陣列
    for (int i = 0; i < m; i++)
        arr[i] = new int [n];


    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            //sort(arr[i], arr[i]+j+1);
        }
        sort(arr[i], arr[i]+n);
    }


    int i, j;
    while (cin >> i >> j)
    {
        if (i < 0 || j < 0)
            break;
        else
            cout << arr[i][j] << endl;
    }
    

    return 0;
}