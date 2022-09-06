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
    private:
        char *rawString;
        int length;
        int sizeRawString;
};

class superString : public simpleString
{
    public:
        superString();
        superString(const char *str);
        void reverseString();
        void toUpper();
        void toLower();
};

superString :: superString() : simpleString(){};

superString :: superString(const char *str) : simpleString(str){};

void superString :: reverseString()
{
    int length = getLength();
    char arr[1000] = {};
    for (int i = 0; i < length; i++)
        arr[i] = getChar(i);
    for (int i = 0; i < length; i++)
        setChar(i, arr[length-1-i]);
}

void superString :: toUpper()
{
    int length = getLength();
    for (int i = 0; i < length; i++)
    {
        char arr = getChar(i);
        if (arr >= 'a' && arr <= 'z')
            setChar(i, arr-'a'+'A');
        else if (arr >= '0' && arr <= '9')
            setChar(i, ' ');
    }
}

void superString :: toLower()
{
    int length = getLength();
    for (int i = 0; i < length; i++)
    {
        char arr = getChar(i);
        if (arr >= 'A' && arr <= 'Z')
            setChar(i, arr+'a'-'A');
        else if (arr >= '0' && arr <= '9')
            setChar(i, '_');
    }
}

simpleString :: simpleString()
{
    length = 0;
    sizeRawString = 1000;
    rawString = new char[sizeRawString];
}

simpleString :: simpleString(const char *str)
{
    sizeRawString = 1000;
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
    int x;
    cin >> x;

    char arr[1000] = {};
    for (int i = 0; i < x; i++)
        cin >> arr[i];

    int a;
    superString str(arr);
    while (cin >> a)
    {
        if (a == 0)
            break;
        else if (a == 1)
            str.output();
        else if (a == 2)
        {
            char res = str.pop();
            cout << res << endl;
        }
        else if (a == 3)
        {
            char c;
            cin >> c;
            str.push(c);
        }
        else if (a == 4)
        {
            int y;
            cin >> y;
            char res = str.getChar(y);
            cout << res << endl;
        }
        else if (a == 5)
        {
            int y;
            char c;
            cin >> y >> c;
            str.setChar(y, c);
        }
        else if (a == 6)
        {
            str.reverseString();
            str.output();
        }
        else if (a == 7)
        {
            str.toUpper();
            str.output(); 
        }
        else if (a == 8)
        {
            str.toLower();
            str.output();
        }
    }
}