#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    ifstream inStream;
    ofstream outStream;
    inStream.open("4.in");
    outStream.open("4.out");

    char line[1000];
    int array[62]={};

    inStream.getline(line, 1000);
    int length = strlen(line);
    for (int i = 0; i < length; i++)
    {
        //char word = line[i];
        if (line[i] != '\n' && line[i] != ' ') 
        {
            if(line[i] >= 'a' && line[i] <= 'z')
                array[line[i] - 'a']++;
            else if(line[i] >= 'A' && line[i] <= 'Z')
                array[line[i] - 'A' + 26]++;
            else if(line[i] >= '0' && line[i] <= '9')
                array[line[i] - '0' + 52]++;
        }
    }

    int max = -1;
    int x;
    for (int i = 0; i < 62; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
            x = i;
        }
    }

    char result;
    if(x >= 0 && x <= 25)
        result = x +'a';
    else if(x >= 26 && x <= 51)
        result = (x - 26) + 'A';
    else if(x >= 52 && x <= 61)
        result = (x - 52) + '0';

    outStream << result << endl;
    inStream.close();
    outStream.close();
    return 0;
}