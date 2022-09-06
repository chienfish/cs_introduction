#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class cards
{
    public:
        cards();
        int getCards();
        int getCards(const int pos);
        bool swapCards(const int a, const int b);
        int remainCards();
        void newCards();
        void output(int x);
    private:
        int cardArray[52];
        int totalCards;

};


cards :: cards()
{
    totalCards = 52;

    for (int i = 0; i < 52; i++)
        cardArray[i] = i;
}

int cards :: getCards()
{
    totalCards--;
    return cardArray[totalCards];
}


int cards :: getCards(const int pos)
{
    return cardArray[pos-1];
}


bool cards :: swapCards(const int a, const int b)
{
    if(a > totalCards || b > totalCards)
		return false;
	else
    {
        int tmp;
        tmp = cardArray[a-1];
        cardArray[a-1] = cardArray[b-1];
        cardArray[b-1] = tmp;

        return true;
    }
}


int cards :: remainCards()
{
    return totalCards;
}


void cards :: newCards()
{
    totalCards = 52;

    for (int i = 0; i < 52; i++)
        cardArray[i] = i;
}


void cards :: output(int x)
{
    switch(x / 13)
    {
        case 0 : cout << "Spare "; break;
        case 1 : cout << "Heart "; break;
        case 2 : cout << "Diamond "; break;
        case 3 : cout << "Club "; break;
    }

    switch(x % 13)
    {
        case 0  : cout << "A" << endl; break;
        case 10 : cout << "J" << endl; break;
        case 11 : cout << "Q" << endl; break;
        case 12 : cout << "K" << endl; break;

        default : cout << (x%13)+1 << endl; break;
    }
}


int main()
{
    int x;
    int result;
    cards c;

    while (cin >> x)
    {
        if (x == 0)
            break;
        else if (x == 1)
        {
            result = c.getCards();
            c.output(result);
        }
        else if (x == 2)
        {
            result = c.remainCards();
            cout << result << endl;
        }
        else if (x < 0)
        {
            int b;
            cin >> b;

            x = abs(x);
            b = abs(b);
            c.swapCards(x, b);
        
        }
        
    }

    return 0;
}
