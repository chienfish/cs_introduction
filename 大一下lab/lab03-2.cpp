#include <iostream>
using namespace std;

int main()
{
    int m = 0,n = 0;
    int i = 0,j = 0;
    cin >> m >> n;
    int **x; //兩層陣列
    x = new int *[m]; // 建立行

    for(int c = 0; c < m; c++) //建立列
        x[c] = new int [n];

    for (int a = 0; a < m; a++) //輸入n*m個整數
    {
        for (int b = 0; b < n; b++)
            cin >> x[a][b]; 
    }

    while(cin >> i >> j) //輸入i,j
    {
        if(i < 0 || j < 0)
            break;

        cout << x[i][j] << endl;
    }
    
    delete x;
    return 0;
}