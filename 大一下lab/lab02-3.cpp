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

    char word[10000] = {};
    int length;
    while(inStream >> word)
    {
        length = strlen(word);
        for (int i = 1; i < length; i++)
        {
            word[i] ^= word[0];
            outStream << word[i];
        }
    }
    outStream << endl;
    
    inStream.close();
    outStream.close();
}