#include <iostream>
#include <stdlib.h>
using namespace std;

const int NUMBER_OF_CARDS = 52;

void output(int card, char* ret_str);
void createCards(int cards[], int numberOfCards);
void shuffleCards(int cards[], int numberOfCards);
int dealCard(int cards[], int &remainCards);
int compare(const void* a, const void* b); 

int main(void)
{
	int seed;
	cin >> seed;
	srand(seed);

	int cards[52];
	int player[4][13];
	int totalCards = NUMBER_OF_CARDS;

	createCards(cards, totalCards);
	shuffleCards(cards, totalCards);

	int remainCards = totalCards;
	for (int i = 0; i < totalCards; i ++) 
		player[i % 4][i / 4] = dealCard(cards, remainCards);
	
	for (int i = 0; i < 4; i ++) 
		qsort(player[i], 13, sizeof(int), compare);
	
	for (int i = 0; i < 4; i ++) {
		for (int j = 0; j < 13; j ++) {
			char ret_str[5];
			output(player[i][j], ret_str);
			cout << ret_str << " ";
		}
		cout << endl;
	}
}

void output(int card, char ret_str[]) 
{
	const char FACE[4] = {'S', 'H', 'D', 'C'};
	const char NUMBER[13] = {'A', '2', '3', '4', '5', '6',
					         '7', '8', '9', '1', 'J', 'Q', 'K'};

	// int face = card / 13;
	// switch(face) {
	// 	case 0:
	// 		s += 'S' == FACE[0];
	// 	case 1:
	// 		s += 'H' == FACE[1];
	// 	case 2: 
	// 		s += 'D' == FACE[2];
	// }				     

	ret_str[0] = FACE[card / 13];
	ret_str[1] = NUMBER[card % 13];

	if (card % 13 + 1 == 10) {
		ret_str[2] = '0';
		ret_str[3] = '\0';
	} else 
		ret_str[2] = '\0';
}

void createCards(int cards[], int numberOfCards)
{
	for (int i = 0; i < numberOfCards; i ++) 
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
	remainCards -= 1;
	return cards[remainCards];
}

int compare(const void* a, const void* b) 
{
	int int_a = *((int*) a);
	int int_b = *((int*) b);		
	
	if (int_a % 13 < int_b % 13) 
		return -1;
	else if (int_a % 13 > int_b % 13)
		return 1;
	else 
		return int_a / 13 - int_b / 13;
}