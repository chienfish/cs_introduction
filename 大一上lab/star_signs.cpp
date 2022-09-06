#include <iostream>
using namespace std;

int main()
{
    int mon , day;
    cin >> mon >> day;

    if ((mon == 1 && day >=21)||(mon == 2 && day <= 19)){
        cout << "Aquarius" << endl;
    }
    if ((mon == 2 && day >=20)||(mon == 3 && day <= 20)){
        cout << "Pisces" << endl;
    }
    if ((mon == 3 && day >=21)||(mon == 4 && day <= 19)){
        cout << "Aries" << endl;
    }
    if ((mon == 4 && day >=20)||(mon == 5 && day <= 20)){
        cout << "Taurus" << endl;
    }
    if ((mon == 5 && day >=21)||(mon == 6 && day <= 21)){
        cout << "Gemini" << endl;
    }
    if ((mon == 6 && day >=22)||(mon == 7 && day <= 22)){
        cout << "Cancer" << endl;
    }
    if ((mon == 7 && day >=23)||(mon == 8 && day <= 22)){
        cout << "Leo" << endl;
    }
    if ((mon == 8 && day >=23)||(mon == 9 && day <= 22)){
        cout << "Virgo" << endl;
    }
    if ((mon == 9 && day >=23)||(mon == 10 && day <= 23)){
        cout << "Libra" << endl;
    }
    if ((mon == 10 && day >=24)||(mon == 11 && day <= 21)){
        cout << "Scorpio" << endl;
    }
    if ((mon == 11 && day >=22)||(mon == 12 && day <= 20)){
        cout << "Sagittarius" << endl;
    }
    if ((mon == 12 && day >=21)||(mon == 1 && day <= 20)){
        cout << "Capricorn" << endl;
    }
}