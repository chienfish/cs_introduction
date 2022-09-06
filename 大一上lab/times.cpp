#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int s;
    cin >> s;
    srand(s);

    int times[50]={};
    int value,max=0,min=0;

    for (int i = 0; i < 100000; i++){
        value = rand() % 50 + 1;
        times[value - 1]++;
    }
    
    for (int i = 0; i < 50; i++){
        if (times[i] > times[max])
            max = i;
        if (times[i] < times[min])
            min = i;
    }

    cout << max+1 << " " << times[max] <<endl;
    cout << min+1 << " " << times[min] <<endl;
    return 0;
}