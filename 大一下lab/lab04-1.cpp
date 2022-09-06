#include <iostream>
#include <algorithm>
using namespace std;

struct grades
{
    int num;
    double ch,eng,math,soc,eco;

};grades getdata();

grades getdata()
{
    grades number;
    cin >> number.num;
    cin >> number.ch;
    cin >> number.eng;
    cin >> number.math;
    cin >> number.soc;
    cin >> number.eco;

    return number;
}


int main()
{
    grades student;
    int x;
    cin >> x;

    int array[20] = {}; //人
    int sum[1000] = {}; //總分
    int grade[5] = {};  //成績
    for (int i = 0; i < x; i++)
    {
        student = getdata();
        array[i] = student.num;
        grade[0] = student.ch;
        grade[1] = student.eng;
        grade[2] = student.math;
        grade[3] = student.soc;
        grade[4] = student.eco;

        sort(grade,grade+5);

        for (int j = 1; j < 5; j++)
            sum[i] += grade[j];
    }


    double min = 401;
    double max = -1;
    int max_number = 0;
    int min_number = 0;


    for (int i = 0; i < x; i++)
    {
        if (sum[i] > max)
        {
            max = sum[i];
            max_number = array[i];
        }
        if (sum[i] < min)
        {
            min = sum[i];
            min_number = array[i];
        }
    }

    cout << max_number << " " << max/4.0 << endl;
    cout << min_number << " " << min/4.0 << endl;

    return 0;
}