#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int i = 2;
    bool isPrime = true;
    while (i < n) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
        i ++;
    }
    cout << isPrime << endl;
}