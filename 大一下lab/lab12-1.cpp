#include <iostream>
using namespace std;

class myRandString
{
    public:
        myRandString(int size);
        void generate();
        friend ostream& operator << (ostream& of, const myRandString mr);
    private:
        int length;
        int SIZE;
        char array[100];
};


myRandString :: myRandString(int size)
{
    SIZE = size;
}


void myRandString :: generate()
{
    length = rand() % SIZE + 1;

    for (int i = 0; i < length; i++)
        array[i] = char(rand() % 26 + 'A');
}

ostream& operator << (ostream& of, const myRandString mr)
{
    string s = "";
    for (int i = 0; i < mr.length; i++)
        s += mr.array[i];
    of << s;
    return of;
}

int main()
{
    int seed, size, x;
    cin >> seed >> size >> x;

    srand(seed);
    myRandString sstringg(size);
    
    for (int i = 0; i < x; i++)
    {
        sstringg.generate();
        cout << sstringg << endl;
    }
}