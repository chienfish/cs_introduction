#include <iostream>
#include <stdlib.h>
using namespace std;

int issueCard();
int cmpCard(int card1,int card2);
void printCard(int card);

int main()
{
    int s,x;
    int max = 0,min = 53;
    int card;
    cin >> s >> x;
    srand(s);

    for (int i = 0; i < x; i++){
        card = issueCard();
        printCard(card);
        if (cmpCard(card,max) > 0)
            max = card;
        if (cmpCard(card,min) < 0)
            min = card;
    }
        printCard(max);
        printCard(min);
        return 0;
}

int issueCard()
{
    return (rand() % 52 +1);
}

int cmpCard(int card1,int card2)
{
    return card1 - card2;
}

void printCard(int card)
{
    int flower = (card-1) / 13 + 1;
    int number = (card-1) % 13 + 1;

    switch (flower){
        case 1 : cout << "S"; break;
        case 2 : cout << "H"; break;
        case 3 : cout << "D"; break;
        case 4 : cout << "C"; break;
    }
    switch (number){
        case 1  : cout << "A"; break;
        case 11 : cout << "J"; break;
        case 12 : cout << "Q"; break;
        case 13 : cout << "K"; break;
        default : cout << number; break;
    }
    cout << endl;
}