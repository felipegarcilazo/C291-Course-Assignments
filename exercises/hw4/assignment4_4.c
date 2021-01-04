// Fig. 7.24: fig07_24.c
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52
// prototypes
void shuffle(unsigned int wDeck[][FACES]); // shuffling modifies wDeck
void deal(unsigned int wDeck[][FACES],const char *wFace[],const char *wSuit[],unsigned int hand[][2]); // dealing doesn't modify the arrays
//new functions
void pair(unsigned int hand[][2], const char *wFace[], const char *wSuit[]); 
void threeOfAKind(unsigned int hand[][2], const char *wFace[], const char *wSuit[]);
void fourOfAKind(unsigned int hand[][2], const char *wFace[], const char *wSuit[]);
void straightHand(unsigned int hand[][2], const char *wFace[], const char *wSuit[]);
void fiveFaces(unsigned int hand[][2], const char *wFace[], const char *wSuit[]);

int main(void)
{
   // initialize deck array
   unsigned int deck[SUITS][FACES] = { 0 };

   srand(time(NULL)); // seed random-number generator

   shuffle(deck); // shuffle the deck

   // initialize suit array
   const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
   const char *face[FACES] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
   
   //will be used to store a five hand card by using integer values of faces and suits where [x][0] is for suits and [x][1] is for faces    
   unsigned int hand[5][2];
   
   deal(deck, face, suit, hand); // deal the deck
   //new functions
   pair(hand, face, suit);
   threeOfAKind(hand, face, suit);
}

// shuffle cards in deck
void shuffle(unsigned int wDeck[][FACES])
{
   // for each of the cards, choose slot of deck randomly
   for (size_t card = 1; card <= CARDS; ++card) {
      size_t row; // row number
      size_t column; // column number

      // choose new random location until unoccupied slot found
      do {                                                        
         row = rand() % SUITS;                                   
         column = rand() % FACES;                             
      } while(wDeck[row][column] != 0); // end do...while

      // place card number in chosen slot of deck
      wDeck[row][column] = card;
   } 
}

// deal cards in deck
void deal(unsigned int wDeck[][FACES],const char *wFace[],const char *wSuit[], unsigned int hand[][2])
{
   int i;
   printf("Your hand is:\n");
   // deal each of the cards
   for (size_t card = 1, i=0; card <= 5; card++, i++) {
      // loop through rows of wDeck
      for (size_t row = 0; row < SUITS; row++) {
         // loop through columns of wDeck for current row
         for (size_t column = 0; column < FACES; column++) {
            // if slot contains current card, display card
            if (wDeck[row][column] == card) {
               hand[i][0]=row;//suits
               hand[i][1]=column;//faces       
               printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t'); // 2-column format
            } 
         } 
      } 
   }
   printf("\n");
}

//checks for pairs
void pair(unsigned int hand[][2], const char *wFace[], const char *wSuit[])
{
 // counter that checks how many unique faces there are
 unsigned int counter[FACES]={0};
 int i;
 for(i=0; i<5; i++){
  ++counter[hand[i][1]];
 }
 
 for(i=0; i<FACES; i++){
  if(counter[i]==2){
   printf("There is a pair of %ss.\n", wFace[i]);
  }
 }

}

void threeOfAKind(unsigned int hand[][2], const char *wFace[], const char *wSuit[])
{
 unsigned int counter[FACES]={0};
 int i;

 for(i=0; i<5; i++){
  ++counter[hand[i][1]];
 }

 for(i=0; i<FACES; i++){
  if(counter[i] == 3){
   printf("There are 3 %ss.\n", wFace[i]);
  }
 }
}

void fourOfAKind(unsigned int hand[][2], const char *wFace[], const char *wSuit[])
{
 unsigned int counter[FACES]={0};
 int i;
 
 for(i=0; i<5; i++){
  ++counter[hand[i][1]];
 }

 for(i=0; i<FACES; i++){
  if(counter[i] == 4){
   printf("There are 4 %ss.\n", wFace[i]);
  }
 }
}

void straightHand(unsigned int hand[][2], const char *wFace[], const char *wSuit[])
{
 unsigned int copy_hand[5]={0};
 int i, x;

 for(i=0; i<5; i++){
  copy_hand[i]=hand[i][1];
 }
	//bubble sort used to swithc places if the card before is greater this orders it so that it can check it in the if statement
 for(i=1; i<5; i++){
  for(x=0; x<4; x++){
   if(copy_hand[x]>copy_hand[x+1]){
    unsigned int x_copy= copy_hand[x];
    copy_hand[x]=copy_hand[x+1];
    copy_hand[x+1]=x_copy;
   }
  }
 }
 if(copy_hand[4]-1 == copy_hand[3] && copy_hand[3]-1 == copy_hand[2] && copy_hand[2]-1 == copy_hand[1] && copy_hand[1]-1 == copy_hand[0]) {
  printf("There is a straight from %s to %s.\n", wFace[copy_hand[0]], wFace[copy_hand[4]]);
 }
}

void fiveFaces(unsigned int hand[][2], const char *wFace[], const char *wSuit[])
{
	//counter for suits similar to the faces but checks for 5 matching suits
 unsigned int counter[SUITS]={0};
 int i;

 for(i=0; i<5; i++){
  ++counter[hand[i][0]];
 }

 for(i=0; i<SUITS; i++){
  printf("There is a flush of %ss.\n", wSuit[i]);
 }

}
