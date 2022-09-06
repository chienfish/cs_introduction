#include <iostream>
using namespace std;

int main()
{
    int SEC;
    int yr,mon,day,hr,min,sec;
    cin >> SEC;
    sec = SEC % 60;
    min = (SEC % 3600 - sec)/60;
    hr  = (SEC % 86400 - sec - min*60)/3600;
    day = (SEC % 2592000 - sec - min*60 - hr*3600)/86400;
    mon = (SEC % 31104000 - sec - min*60 - hr*3600 - day*86400)/2592000; 
    yr  =  SEC/31104000;
    cout << yr <<" "<< mon <<" "<< day <<" "<< hr <<" "<< min <<" "<< sec << endl;
}