#include <iostream>
using namespace std;

class myTime
{
    public:
        int hr;
        int min;
        int sec;
        void input();
        void output();
        void outputSeconds();

};

void myTime :: input()
{
    if ((hr > 23) || (hr < 0))
        hr = 0;
    if ((min > 59) || (min < 0))
        min = 0;
    if ((sec > 59) || (sec < 0))
        sec = 0;
}

void myTime :: output()
{
    if (hr / 10 == 0)
        cout << "0" << hr << ":";
    else
        cout << hr << ":";

    if (min / 10 == 0)
        cout << "0" << min << ":";
    else
        cout << min << ":";

    if (sec / 10 == 0)
        cout << "0" << sec << endl;
    else
        cout << sec << endl;

}

void myTime :: outputSeconds()
{
    sec = sec + (min*60) + (hr*3600);
    
    if ((sec < 10000) && (sec > 1000))
        cout << "0" << sec << endl;
    else if ((sec < 1000) && (sec > 100))
        cout << "00" << sec <<endl;
    else if ((sec < 100) && (sec > 10))
        cout << "000" << sec <<endl;
    else if (sec < 10)
        cout << "0000" << sec <<endl;
    else
        cout << sec << endl;
}

int main()
{
    myTime mytime;
    cin >> mytime.hr >> mytime.min >> mytime.sec;
    mytime.input();
    mytime.output();
    mytime.outputSeconds();
    
    return 0;
}