#include <iostream>
using namespace std;

class powerDate
{
    private :
        int year;
        int month;
        int day;
        int week;

    public :
        bool isLeap();
        bool set(const int y, const int m, const int d);
        int getWeek();
        int getYear();
        int getMonth();
        int getDay();

    powerDate(const int y, const int m, const int d)
    {
        year = y;
        month = m;
        day = d;

        if (set(y, m, d) == true)
        {
            year = y;
            month = m;
            day = d;
        } else{
            year = 1900;
            month = 1;
            day = 1;
        }
    }

    powerDate operator [] (int& a)
    {
        powerDate DateViaN(this->year, this->month, this->day);
        int m_day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30 ,31};
        if (DateViaN.isLeap())
            m_day[2] += 1;
        
        bool first = true;
        if (a > 0) {
            while (a != 0) {
                if (first) {
                    first = false;
                } else {
                    DateViaN.day = 1;
                    if (DateViaN.month == 12) {
                        DateViaN.year += 1;
                        DateViaN.month = 1;
                        if (DateViaN.isLeap())
                            m_day[2] = 29;
                        else
                            m_day[2] = 28;
                    } else {
                        DateViaN.month += 1;
                    }
                    a -= 1; 
                }
                int diff = min(a, m_day[DateViaN.month] - DateViaN.day);
                DateViaN.day += diff;
                a -= diff;
            }
        } 

        if (a < 0) {
            while (a != 0) {
                if (first) {
                    first = false;
                } else {
                    if (DateViaN.month == 1) {
                        DateViaN.year -= 1;
                        DateViaN.month = 12;
                        if (DateViaN.isLeap())
                            m_day[2] = 29;
                        else
                            m_day[2] = 28;
                    } else {
                        DateViaN.month -= 1;                        
                    }
                    DateViaN.day = m_day[DateViaN.month];
                    a += 1;
                }
                int diff = min(-a, DateViaN.day-1);
                DateViaN.day -= diff;
                a += diff;
            }
        } 

        return DateViaN;
    }
};

bool powerDate :: isLeap()  //逢4閏 逢100不閏 逢400閏
{
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return true;    
    else 
        return false;
}

int powerDate :: getWeek()
{
    int c,y;
    int w,m,d;

    y = year;
    m = month;
    d = day;

    switch (m){
        case (1) : case(2):
            y = y - 1;
            m = m + 12;
            break;
    }

    c = y / 100;
    y = y % 100;
    m = 26 * (m + 1);
    m = m / 10;
      
    w = (y + (y/4) + (c/4) - 2*c + m + d - 1) ;
    w = ( w % 7 + 7 ) % 7;


    switch (w){
        case 1: cout << "Monday" << endl;   break;
        case 2: cout << "Tuesday" << endl;  break;
        case 3: cout << "Wednesday" << endl;break;
        case 4: cout << "Thursday" << endl; break;
        case 5: cout << "Friday" << endl;   break;
        case 6: cout << "Saturday" << endl; break;
        case 0: cout << "Sunday" << endl;   break;
    }
    return 0;
}

bool powerDate :: set(const int y, const int m, const int d)
{
    if (y > 2021 || y < 1900)
        return false;  
    else if (m < 1 || m > 12) 
        return false;  
    else {
        int m_day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30 ,31};
        if (((y % 4 == 0) && (y % 100 != 0)) || y % 400 == 0) 
            m_day[2] += 1;
        
        if (d < 1 || d > m_day[m]) 
            return false;  
        else 
            return true;
    }
}

int powerDate :: getYear()
{
    cout << year << "-";
    return 0;
}

int powerDate :: getMonth()
{
    if (month > 0 && month < 10)
        cout << "0" << month << "-";
    else 
        cout << month << "-";
    return 0;
}

int powerDate :: getDay()
{
    if (day > 0 && day < 10)
        cout << "0" << day;
    else
        cout << day;
    return 0;
}

int main()
{   
    int a;
    int y, m , d;
    

    while (cin >> a)
    {
        if (a == 0)
            break;
           
        cin >> y >> m >> d;
        powerDate myDate(y, m, d); 
        
        if (a == 1) {
            int y = myDate.getYear();
            int m = myDate.getMonth();
            int d = myDate.getDay();

            //printf("%d-%02d-%02d", y, m, d);
            // cout << myDate.getYear() << "-" << myDate.getMonth() << "-" << myDate.getDay();

            if (myDate.isLeap())
                cout << "L" << " ";
            else
                cout << "l" << " ";

            myDate.getWeek();

        } else if (a == 2) {
            int n;
            cin >> n;
            powerDate newdate = myDate[n];
            int y = newdate.getYear();
            int m = newdate.getMonth();
            int d = newdate.getDay();

            //printf("%d-%02d-%02d", y, m, d);
            // cout << myDate[n].getYear() << "-" << myDate[n].getMonth() << "-" << myDate[n].getDay();

            if (newdate.isLeap())
                cout << "L" << " ";
            else
                cout << "l" << " ";

            newdate.getWeek();
        }

    }
}