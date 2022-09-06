#include <iostream>
using namespace std;

class intList
{
    public: 
        intList();
        void insert(int value);
        bool remove(int pos);
        int getValue(int pos);
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

intList :: intList()
{
    data = new int [10];
    totalSize = 10;
    sizeUsed = 0;
}

void intList :: insert(int value)
{
    sizeUsed+=1;
    data[sizeUsed-1] = value;

    if (sizeUsed == totalSize)
       expandSize();
}

bool intList :: remove(int pos)
{
    if (pos <= sizeUsed && pos >= 1)
    {
        data[pos-1] = data[sizeUsed-1];
        sizeUsed--;
        return true;
    }
    else
        return false;

}

int intList :: getValue(int pos)
{
    return data[pos-1];
}

bool intList :: setValue(int pos, int value)
{
    if(pos > sizeUsed)
		return false;
	else
	{
		data[pos-1] = value;
		return true;
	}
}

int intList :: getSize()
{
    return sizeUsed;
}

bool intList :: swapValue(int pos1, int pos2)
{
    if(pos1 > sizeUsed || pos2 > sizeUsed)
		return false;
	else
	{
		int tmp;
		tmp = data[pos1-1];
		data[pos1-1] = data[pos2-1];
		data[pos2-1] = tmp;
		return true;
	}
}

void intList :: expandSize()
{
    int newdata[totalSize];

    for (int i = 0; i < sizeUsed; i++) //複製
        newdata[i] = data[i];
    
    delete [] data; //刪掉舊的動態陣列

    totalSize *= 2;
    data = new int[totalSize]; //建立新的動態陣列

    for (int i = 0; i < sizeUsed;i++)
        data[i] = newdata[i];
}

int main()
{
    intList array;
    int x;

    while (cin >> x)
    {
        if (x == 0)
            break;
        if (x > 0)
            array.insert(x);
        if (x < 0)
        {
            x = abs(x);
            int result = array.getValue(x);

			if(array.remove(x) == true)
				cout << result << endl;
			else
				cout << "no" << endl;
        }
         
    }

    return 0;
}