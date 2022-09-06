#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    int s, x;
    cin >> s >> x;
    srand(s);

    int *ptr[1024];
    float sum = 0;
    float av = 0;
    for (int i = 0; i < x; i++)
    {
        ptr[i] = new int ;
        *ptr[i] = rand() % 201 - 100;

        sum += *ptr[i];
        
    }
    av = sum / x;


    float stsum = 0;
    float st = 0;
    for (int i = 0; i < x; i++)
        stsum += (*ptr[i] - av) * (*ptr[i] - av);
    st = sqrt(stsum / x);


    cout << av << endl << st << endl;
    return 0;

}