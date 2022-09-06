#include <iostream>
#include <fstream>
using namespace std;

bool isPrime(int x);

int main()
{
    ifstream inStream;
    ofstream outStream;
    inStream.open("1.in");
    outStream.open("1.out");

    int s;
    while (inStream >> s){
        for (int n = s - 1 ; n > 1 ; n--){
            if (isPrime(n) == true){
                outStream << n << endl;
                break;
            }
        }

    }
    inStream.close();
    outStream.close();
    return 0;
}

bool isPrime(int x)
{
    if (x == 1)
        return false;
    if (x == 2)
        return true;
    for(int i = 2; i < x; i++){
        if (x % i == 0)
            return false;
    }
    return true;
}