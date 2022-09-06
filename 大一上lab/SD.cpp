#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

int main()
{
    int s;
    cin >> s;
    srand(s);

    int array[100]={};

    int max=99,min=1001;
    for (int i = 0; i<100; i++){
        array[i] = rand() % 901 + 100;
        if (array[i] > max)
            max = array[i];
        if (array[i] < min)
            min = array[i];
    }
    
    int sum = 0;
    double average;
    for (int i = 0; i < 100; i++)
        sum += array[i];
    average = sum / 100.0;

    double SD,SDsum=0;
    for (int i = 0; i < 100; i++)
        SDsum += (array[i] - average)*(array[i] - average);
    SD = sqrt(SDsum / 100.0);

    cout << max << endl;
    cout << min << endl;
    cout << average << endl;
    cout << SD << endl;
    return 0;
}