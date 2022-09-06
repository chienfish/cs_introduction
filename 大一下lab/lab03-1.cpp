#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    ifstream inStream;
    ofstream outStream;
    inStream.open("1.in");
    outStream.open("1.out");

    long begin,end,size;    //算出檔案大小
    ifstream myfile("1.in");
    begin = myfile.tellg();
    myfile.seekg(0,ios::end);
    end = myfile.tellg();
    myfile.close();
    size = (end - begin);

    char *array;
    array = new char[size];

    char words[10000];
    srand(100);
    while(inStream.read(array,size))
    {
        for (int i = 0; i < 50; i++)
        {
            int x = rand() % size + 1;
            outStream << array[x-1];
        }
    }   
    outStream << endl;
 
    delete array;
    return 0;
    inStream.close();
    outStream.close();
}