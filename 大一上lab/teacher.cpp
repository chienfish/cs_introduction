#include <iostream>

using namespace std;

int issueCard();
int cmpCard( int card1, int card2 );
void showCard( int card );

int main()
{
  	int s, x;
  	int max, min, i, card;
  
  	cin >> s >> x;
  	srand(s);
  
  	max=0;min=53;
  
  	for( i=0; i<x; i++ )
    {
      card=issueCard();
      showCard(card);
      if( cmpCard( card, max ) > 0 )
        max=card;
      if( cmpCard( card, min ) < 0 )
        min=card;
    }
  	showCard(max);
  	showCard(min);
	return 0;
}

int issueCard()
{
  return rand()%52+1;
}

int cmpCard( int card1, int card2 )
{
/*  int face1, face2;
  int number1, number2;
  face1=(card1-1)/13+1;
  number1=(card1-1)%13+1;
  face2=(card2-1)/13+1;
  number2=(card2-1)%13+1;
  
  if( face1 == face2)
    return number1-number2;
  else
  	return face2-face1;*/
  return card1-card2;
}

void showCard( int card )
{
  int face, number;
  
  face=(card-1)/13+1;
  number=(card-1)%13+1;
  
  switch( face )
  {
    case 1:
      cout << "S";
      break;
    case 2:
      cout << "H";
      break;
    case 3:
      cout << "D";
      break;
    case 4:
      cout << "C";
      break;
  }
  
  switch( number )
  {
    case 1:
      cout << "A";
      break;
    case 11:
      cout << "J";
      break;
    case 12:
      cout << "Q";
      break;
    case 13:
      cout << "K";
      break;
    default:
      cout << number;
  }
  cout << endl;
}