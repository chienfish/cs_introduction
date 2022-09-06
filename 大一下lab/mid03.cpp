#include <iostream>
using namespace std;

class myList
{
    private:
        int cur_size;
        int max_size;
        int array[10000];

    public:
        myList(void);
        myList(const int maxSize);
        myList(const int maxSize, int data[], const int size);

        bool addInt(const int data);
        bool subInt(const int data);
        bool searchInt(const int data);

};

myList::myList(void)
{
    cur_size = 0;
    max_size = 100;
}

myList::myList(const int maxSize)
{
    cur_size = 0;
    max_size = maxSize;
}

myList::myList(const int maxSize, int data[], const int size)
{
    cur_size = size;
    max_size = maxSize;
    for (int i = 0; i < size; i ++) 
        array[i] = data[i];
}

bool myList::addInt(const int data)
{
    if (cur_size < max_size) {
        array[cur_size++] = data;
        return true;
    } else 
        return false;
}

bool myList::subInt(const int data)
{
    for (int i = 0; i < cur_size; i ++) {
        if (array[i] == data) {
            for (int j = i; j < cur_size - 1; j ++)
                array[j] = array[j + 1];
            cur_size -= 1;
            return true;
        } 
    }
    return false;
}

bool myList::searchInt(const int data)
{
    for (int i = 0; i < cur_size; i ++) {
        if (array[i] == data) 
            return true;
    } 
    return false;
}

int main(void)
{
    int maxsize, size;
    cin >> maxsize >> size;

    int input[10000];
    for (int i = 0; i < size; i ++)
        cin >> input[i];

    myList Data(maxsize, input, size);

    int op;
    cin >> op;

    while (op != 4) {
        int x;
        cin >> x;

        switch(op) {
            case 1:
                Data.addInt(x);
                break;
            case 2:
                Data.subInt(x);
                break;
            case 3:
                if (Data.searchInt(x)) 
                    cout << "T\n";
                else 
                    cout << "F\n";
                break;
        }
        cin >> op;
    }

}