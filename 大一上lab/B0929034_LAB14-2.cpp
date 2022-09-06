#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ifstream inStream;
    ofstream outStream;
    inStream.open("2.in");
    outStream.open("2.out");

    char str[70];

    while (inStream >> str)
        outStream << strlen(str) << str << endl;

    inStream.close();
    outStream.close();
    return 0;

}