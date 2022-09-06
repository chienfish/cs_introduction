#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(void)
{
    ifstream in;
    ofstream out;
    in.open("1.in");
    out.open("1.out");

    char *ptr = (char*) malloc(10000);
    int len = 0;
    while (in.get(*(ptr + len))) {
        len += 1;
    }

    srand(100);
    for (int i = 0; i < 50; i ++) {
        int index = rand() % len + 1;
        out << ptr[index - 1];
    }

    in.close();
    out.close();
}