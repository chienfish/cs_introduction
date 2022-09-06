#include <iostream>
#include <stdlib.h>
using namespace std;

const int NUMBER_OF_CARDS = 52;

void creatCards(int cards[], int numberOfCards);
void shuffleCards(int cards[], int numberOfCards);
int dealCard(int cards[], int &remainCards);

int main()
{
    int s;
    cin >> s;
    srand (s);

    int cards[NUMBER_OF_CARDS];
    int totalCards = NUMBER_OF_CARDS;

    creatCards(cards, totalCards);
    shuffleCards(cards, totalCards);
    for(int p = 1; p <= 4; p++){
        for(int i = p; i <= 52; i += 4 ){
            int cardFace = cards[i - 1] / 13 + 1;
            int cardNumber = cards[i - 1] % 13 +1;
            
            char f;
            switch (cardFace){
                case 1 : f = 'S'; break;
                case 2 : f = 'H'; break;
                case 3 : f = 'D'; break;
                case 4 : f = 'C'; break;
            }

            string n;
            switch (cardNumber){
                case 1 :  n = "A"; break;
                case 11 : n = "J"; break;
                case 12 : n = "Q"; break;
                case 13 : n = "K"; break;
                default : n += to_string(cardNumber); break;
            }
            cout << f << n << " ";
        }
        cout << endl;
    }
}

void creatCards(int cards[], int numberOfCards)
{
    for (int i = 0; i < numberOfCards; i++) 
		cards[i] = i;
}

void shuffleCards(int cards[], int numberOfCards)
{
    for (int i = 0; i < numberOfCards; i ++) {
		int pos1 = rand() % numberOfCards;
		int pos2 = rand() % numberOfCards;

        int tmp = cards[pos1];
		cards[pos1] = cards[pos2];
		cards[pos2] = tmp;
    }
}

int dealCard(int cards[], int &remainCards)
{
    remainCards --;
	return cards[remainCards];
}