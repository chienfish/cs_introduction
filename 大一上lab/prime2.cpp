#include <iostream>
using namespace std;

bool isPrime(int num);
int main()
{
    int n;
    cin >> n;
    for (int x = n; x >= 2; x--){
        if (isPrime(x)){
            cout << x << endl;
            break;
        }
    }
    return 0;
}

bool isPrime(int num)
{
    for(int i = 2; i < num; i++){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}