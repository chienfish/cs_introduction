#include <iostream>
using namespace std;

int main()
{
    int days;
    cin >> days;

    int tree1 = 0;  //鳳凰樹
    int tree2 = 0;  //樟樹
    int tree3 = 0;  //榕樹
    for (int i = 1; i <= days; i++)
    {
        int week = (i - 1) / 7;
        if (i % 7 == 1 || i % 7 == 4)
            tree1 += i % 7 + week;
        if (i % 7 == 2 || i % 7 == 5)
            tree2 += i % 7 + week;
        if (i % 7 == 3 || i % 7 == 6)
            tree3 += i % 7 + week;
    }
    int trees = (tree1 + tree2 + tree3);
    
    int chair = tree1 * 5;
    int cupboard = tree2;
    int desk = tree3 * 3;
    int furniture = (chair + cupboard + desk);

    cout << tree1 << " " << tree2 << " " << tree3 << endl;
    cout << trees << endl;

    if ((furniture*1000) > (trees*3000))
        cout << "我是家具大師" << endl;
    else if ((furniture*1000) < (trees*3000))
        cout << "我是精油大師" << endl;
    else
        cout << "太剛好了吧" << endl;


    return 0;
}