#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    ifstream inStream;
    ofstream outStream;
    inStream.open("5.in");
    outStream.open("5.out");

    char words1[9487];
    char words2[9487];
    inStream >> words1 >> words2;

    for(int a = 0; a < strlen(words1); a++)
	{
		if(words1[a] >= 'a' && words1[a] <= 'z')
            words1[a] -= 32;    //利用ASCII  加上32變成大寫
    }
    for(int a = 0; a < strlen(words2); a++)
	{
		if(words2[a] >= 'a' && words2[a] <= 'z')
            words2[a] -= 32;    //利用ASCII  加上32變成大寫
    }

    bool cover1[26], cover2[26];
    for (int i = 0; i < 26; i ++) {
        cover1[i] = false;
        cover2[i] = false;
    }

    for (int i = 0; i < strlen(words1); i++)
    {
        cover1[(words1[i] - 'A')] = true;
    }
    
    for (int i = 0; i < strlen(words2); i++)
    {
        cover2[(words2[i] - 'A')] = true;
    }

    for (int i = 0; i < 26; i ++) {
        if (cover1[i] && cover2[i]) 
            outStream << (char)('A' + i);
    }
    outStream << endl;

    inStream.close();
    outStream.close();
    return 0;
}