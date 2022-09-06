#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ifstream inStream;
    ofstream outStream;
    inStream.open("3.in");
    outStream.open("3.out");

    char alphabet;
    while (inStream >> alphabet){
            if ((alphabet>='a') && (alphabet<='z')){
                alphabet = alphabet- 'a' + 'A';
            }
            outStream << (char)alphabet ;
    }
    outStream << endl;
    
    inStream.close();
    outStream.close();
    return 0;
}