#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int s,x;
    int flower,number;
    
    cin >> s >> x;
    srand(s);

    for (int i = 0; i < x; i++){
        flower = rand() % 4 + 1;
        number = rand() % 13 + 1;

        switch( flower ){
          case 1:
            cout << "S";
            break;
          case 2:
            cout << "H";
            break;
          case 3:
            cout << "D";
            break;
          case 4:
            cout << "C";
            break;
        }

        switch (number){
            case 11:
                cout << "J";
                break;
            case 12:
                cout << "Q";
                break;
            case 13:
                cout << "K";
                break;
            case 1:
                cout << "A";
                break;
            default:
                cout << number;
                break;
            
        }
    cout << endl;
    }
return 0;
}