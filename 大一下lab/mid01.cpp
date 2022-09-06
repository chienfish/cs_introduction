#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;


int main()
{
    ifstream in;
    ofstream out;
    in.open("1.in");
    out.open("1.out");

    int m = 0, n = 0;
    int a = 0, b = 0;
    in >> m >> n;

    char **x;
    x = new char *[m];

    for (int c = 0; c < m; c++)
        x[c] = new char[n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            in >> x[i][j];
            
    }

    while(in >> a >> b)
    {
        if (a < 0 || b < 0)
            break;

        out << x[a][b] << endl;
    }

    delete x;
    return 0;
    in.close();
    out.close();
}