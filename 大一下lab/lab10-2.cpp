#include <iostream>
using namespace std;

class intList
{
    public:
        intList();
        void insert(int value);
        bool remove(int pos);
        int getvalue(int pos);
        bool setValue(int pos, int value);
        int getSize();
    protected:
        bool swapValue(int pos1, int pos2);
    private:
        int *data;
        int totalSize;
        int sizeUsed;
        void expandSize();
};

class searchList : public intList
{
    public:
        int search (int value);
};

int searchList :: search(int value)
{
    int sizeUsed = getSize();

    for(int i = 1; i <= sizeUsed; i++)
    {
        if( getvalue(i) == value )
            return i;
    }
    return -1;
}

bool intList :: remove(int pos)
{
    if (pos > 0 && pos <= sizeUsed)
    {
        data[pos-1] = data[sizeUsed - 1];
        sizeUsed -= 1;
        return true;
    }
    else
        return false;
}

int intList :: getvalue(int pos)
{
    return data[pos-1];
}

intList :: intList()
{
    data = new int [1000];
    totalSize = 1000;
    sizeUsed = 0;
}

void intList :: insert(int value)
{
    if (totalSize == sizeUsed)
        expandSize();
    else
    {
        sizeUsed += 1;
        data[sizeUsed-1] = value;
    }
    
}



bool intList :: setValue(int pos, int value)
{
    if (pos > 0 && pos <= sizeUsed)
    {
        data[pos - 1] = value;
        return true;
    }
    else
        return false;
}


int intList :: getSize()
{
    return sizeUsed;
}


bool intList :: swapValue(int pos1, int pos2)
{
    if (pos1 < 0 || pos2 < 0)
        return false;
    else
    {
        int tmp;
        tmp = data[pos2-1];
        data[pos2-1] = data[pos1-1];
        data[pos1-1] = tmp;

        return true;
    }
    
}

void intList :: expandSize()
{
    int newdata[totalSize];

    for (int i = 0; i < sizeUsed; i++)
        newdata[i] = data[i];
    
    delete [] data; 
    
    totalSize *= 2;
    data = new int[totalSize];

    for (int i = 0; i < sizeUsed; i++)
        data[i] = newdata[i];
}

int main()
{
    int x;
    searchList myList;

    while(cin >> x)
    {
        if (x == 0)
            break;
        else if (x > 0)
            myList.insert(x);
        else
        {
            x = abs(x);
            //int res = myList.getvalue(x);
            int pos = myList.search(x);

            if (pos == -1)
                cout << "no" << endl;
            else
            {
                myList.remove(pos);
                cout << "ok" << endl;
            }
        }
    }

    return 0;
}