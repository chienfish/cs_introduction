#include <iostream>
#include <algorithm>

using namespace std;

void Array(int nchars, char x[], char res[], int cur_pos);

bool used[1000];

int main()
{
    int n;
    cin >> n;

    char x[1000];
    for (int i = 0; i < n; i++) 
        cin >> x[i];

    sort(x, x + n);
    for (int i = 0; i < n; i ++)
        used[i] = false;

    char res[1000];
    Array(n, x, res, 0);
}


void Array(int nchars, char x[], char res[], int cur_pos)
{
    if (cur_pos == nchars) 
    {
        for (int i = 0; i < nchars; i ++)
            cout << res[i];
            
        cout << "\n";
    } else {
        for (int i = 0; i < nchars; i ++) 
        {
            if (!used[i]) 
            {
                used[i] = true;
                res[cur_pos] = x[i];
                Array(nchars, x, res, cur_pos + 1);
                used[i] = false;
            }
        }
    }
}