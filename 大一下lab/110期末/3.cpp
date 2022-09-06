#include <iostream>
#include <cstring>
using namespace std;

class simpleString
{
    public:
        simpleString();
        simpleString(const char *str);
        int getLength();
        char getChar(const int pos);
        bool setChar(const int pos, const char c);
        void output();
        void push(const char c);
        char pop();
        void clear();
        friend ostream& operator <<(ostream& ost, simpleString& str);
        friend istream& operator >>(istream& ist, simpleString& str);
    private:
        char *rawString;
        int length;
        int sizeRawString;
};

ostream& operator<<(ostream& ost, simpleString& str)
{
    for (int i = 0; i < str.length; i ++)
        ost << str.rawString[i];
    return ost;
}

istream& operator>>(istream& ist, simpleString& str)
{
    string in;
    getline(ist, in);
    str.length = in.length();
    
    for (int i = 0; i < in.length(); i ++)
        str.rawString[i] = in[i];

    return ist;
}

simpleString :: simpleString()
{
    length = 0;
    sizeRawString = 10000;
    rawString = new char[sizeRawString];
}

simpleString :: simpleString(const char *str)
{
    sizeRawString = 10000;
    rawString = new char[sizeRawString];
    length = strlen(str);

    for (int i = 0; i < length; i++) 
        rawString[i] = str[i];
}

int simpleString :: getLength()
{
    return length;
}

char simpleString :: getChar(const int pos)
{
    if (pos > length-1)
        return '\0';
    else
        return rawString[pos];
}

bool simpleString :: setChar(const int pos, const char c)
{
    if (pos > length-1)
        return false;
    else
    {
        rawString[pos] = c;
        return true;
    }
}

void simpleString :: output()
{
    for (int i = 0; i < length; i++)
        cout << rawString[i];

    cout << endl;
}

void simpleString :: push(const char c)
{
    rawString[length++] = c;
}

char simpleString :: pop()
{
    if (length == 0)
        return '\0';
    else
        return rawString[--length];
}

void simpleString :: clear()
{
    length = 0;
}


int main()
{
    simpleString newString;
    cin >> newString;
    cout << "I love " << newString << endl;
}