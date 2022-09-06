#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

void createCards(int cards[], int numberOfCards);
void shuffleCards(int cards[], int numberOfCards);
int dealCard(int cards[], int &remainCards);
string print(int card);

int color(int card);
int number(int card);

int main()
{
    int s;
    cin >> s;
    srand(s);

    int cards[53];
    int totalCards = 52;
    createCards(cards, totalCards);
    shuffleCards(cards, totalCards);

    int player1[5], player2[5];
    for (int i = 0; i < 5; i ++)
    {
        player1[i] = dealCard(cards, totalCards);        
    }
    for (int i = 0; i < 5; i ++)
    {
        player2[i] = dealCard(cards, totalCards);        
    }
    
    sort(begin(player1), end(player1));
    sort(begin(player2), end(player2));

    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < 5; i ++) {
        int num1 = number(player1[i]);
        if (10 <= num1 && num1 <= 13)
            sum1 += 10;
        else 
            sum1 += number(player1[i]);

        int num2 = number(player2[i]);
        if (10 <= num2 && num2 <= 13)
            sum2 += 10;
        else 
            sum2 += number(player2[i]);
    }

    string output = print(player1[0]);
    for (int i = 1; i < 5; i ++) {
        output += (" " + print(player1[i]));
    } 
    cout << output << endl;

    output = print(player2[0]);
    for (int i = 1; i < 5; i ++) {
        output += (" " + print(player2[i]));
    }
    cout << output << endl; 

    if (abs(sum1 - 21) < abs(sum2 - 21)) {
        cout << "player1" << endl;
    } else if (abs(sum1 - 21) > abs(sum2 - 21)){
        cout << "player2" << endl;
    } else
        cout << "No One Win" << endl;

    return 0;
}

void createCards(int cards[], int numberOfCards)
{
    for (int x = 1; x <= numberOfCards; x++)
        cards[x]= x;
}

void shuffleCards(int cards[], int numberOfCards)
{
    for (int i = 0; i < 52; i++)
    {
        int pos1 = rand() % 52 + 1;
        int pos2 = rand() % 52 + 1;

        while (pos1 == pos2) {
            pos1 = rand() % 52 + 1;
            pos2 = rand() % 52 + 1;
        }
        
        int tmp = cards[pos1];
        cards[pos1] = cards[pos2];
        cards[pos2] = tmp;
    }
}

int dealCard(int cards[], int &remainCards)
{
    int returnCard = cards[remainCards--];
    return returnCard;
}

int color(int card)
{
    return ((card - 1) / 13);
}

int number(int card)
{
    return ((card - 1) % 13 + 1);
}

string print(int card)
{
    string ret_st;
    switch(color(card)) {
        case 0:
            ret_st += "S";
            break;
        case 1:
            ret_st += "H";
            break;
        case 2:
            ret_st += "D";
            break;
        case 3:
            ret_st += "C";
            break;
    }
    
    switch (number(card)) {
        case 1:
            ret_st += "A";
            break;
        case 11:
            ret_st += "J";
            break;
        case 12:
            ret_st += "Q";
            break;
        case 13:
            ret_st += "K";
            break;
        default:
            ret_st += to_string(number(card));
            break;
    }
    return ret_st;
}