#include <iostream>
using namespace std;

class cards
{
    public:
        cards();
        int getCard();
        int getCard(const int pos);
        bool swapCards(const int a, const int b);
        int remainCards();
        void newCards();
        void output(int x);
    private:
        int cardArray[52];
        int totalCards;
};

class shuffleCards : public cards
{
    public:
        shuffleCards(int seed);
        void shuffle();
        int getCard();
};

shuffleCards :: shuffleCards(int seed)
{
    srand(seed);

    for (int i = 0; i < 52; i++)
        shuffle();
}

void shuffleCards :: shuffle()
{
    int totalCards = remainCards();
    int x = rand() % totalCards + 1;
    int y = rand() % totalCards + 1;
    // if (x == y)
    //     y = rand() % totalCards + 1;

    swapCards(x, y);   
}

int shuffleCards :: getCard()
{
    int totalCards = remainCards();
    if (totalCards == 0)
    {
        newCards();
    
        for (int i = 0; i < 52; i++)
            shuffle();

    }
    
    return cards :: getCard();
}

cards :: cards()
{
    newCards();
}

int cards :: getCard()
{
    return cardArray[--totalCards];
}

int cards :: getCard(const int pos)
{
    return cardArray[pos-1];
}

bool cards :: swapCards(const int a, const int b)
{
    if (a > 0 && b  > 0)
    {
        int tmp;
        tmp = cardArray[b-1];
        cardArray[b-1] = cardArray[a-1];
        cardArray[a-1] = tmp;

        return true;
    }
    else
        return false;
}

int cards :: remainCards()
{
    return totalCards;
}

void cards :: newCards()
{
    totalCards = 52;
    for (int i = 0; i < totalCards; i++)
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
    int y;
    cin >> y;
    srand(y);

    shuffleCards mycard(y);
    int x;
    while(cin >> x)
    {
        if (x == 0)
            break;
        else if (x > 0)
        {
            for (int i = 0; i < x; i++)
            {
                int res = mycard.getCard();
                mycard.output(res);
            }
            
        }
        
    }
    return 0;
}