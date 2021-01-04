/*
Felipe Garcilazo
2/17/20

Question 2:
*/

// Fig. 10.3: fig10_03.c
// Card shuffling and dealing program using structures
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13
#define SUITS 4

// card structure definition 
struct card {
   const char *face; // define pointer face      
   const char *suit; // define pointer suit   
}; 

typedef struct card Card; // new type name for struct card   

// prototypes
void fillDeck(Card * const wDeck, const char * wFace[], const char * wSuit[]);
void shuffle(Card * const wDeck);
void deal(const Card * const wDeck);
//New functions
void user_hand(const Card* const wDeck, Card* hand);
void pair(const char* wFace[], Card* hand);
void threeOfAKind(const char* wFace[], Card* hand);
void fourOfAKind(const char* wFaces[], Card* hand);
void flush(const char* wSuit[], Card* hand);
void straightHand(const char* wFace[], Card* hand);

int main(void)
{
   Card deck[CARDS]; // define array of Cards

   // initialize array of pointers
   const char *face[] = { "Ace", "Deuce", "Three", "Four", "Five","Six", "Seven", "Eight", "Nine", "Ten","Jack", "Queen", "King"};

   // initialize array of pointers
   const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades"};

   // initialize the hand
   Card hand_arr[5];

   srand(time(NULL)); // randomize

   fillDeck(deck, face, suit); // load the deck with Cards
   shuffle(deck); // put Cards in random order
   deal(deck); // deal all 52 Cards
   printf("\n");
   user_hand(deck, hand_arr); // deals hand to the user
   printf("\n");
   pair(face, hand_arr);  //pairs are printed
   threeOfAKind(face, hand_arr); //three of a kinder are checked and printed
   fourOfAKind(face, hand_arr); //four of a kind arec checked and printed
   flush(suit, hand_arr); //Checks if all the suits are the same.

}

// place strings into Card structures
void fillDeck(Card * const wDeck, const char * wFace[], const char * wSuit[])
{
   // loop through wDeck
   for (size_t i = 0; i < CARDS; ++i) { 
      wDeck[i].face = wFace[i % FACES];
      wDeck[i].suit = wSuit[i / FACES];
   } 
}

// shuffle cards
void shuffle(Card * const wDeck)
{
   // loop through wDeck randomly swapping Cards
   for (size_t i = 0; i < CARDS; ++i) {
      size_t j = rand() % CARDS;
      Card temp = wDeck[i];      
      wDeck[i] = wDeck[j];
      wDeck[j] = temp;      
   } 
}

// deal cards
void deal(const Card * const wDeck)
{
   // loop through wDeck
   for (size_t i = 0; i < CARDS; ++i) {
      printf("%5s of %-8s%s", wDeck[i].face, wDeck[i].suit,(i + 1) % 4 ? "  " : "\n");     
   }
}

//deals 5 card hand to user
void user_hand(const Card* const wDeck, Card* hand)
{
   printf("Your hand is:\n");
   for(size_t i = 0; i < 5; i++){
      hand[i].face = wDeck[i].face;
      hand[i].suit = wDeck[i].suit;
      printf("%5s of %-8s\n",  hand[i].face, hand[i].suit);    
   }
}

//checks if a hand contains a pair.
void pair(const char* wFace[], Card* hand){
   int counter[FACES]={0}; 
   int i, j;
//loops through the values checking if there are pairs. adds one to the counter list for every pair.
   for(i=0; i<FACES; i++){
      for(j=0; j<5; j++){
         if(wFace[i] == hand[j].face){
            counter[i]++;
         }
      }
   }
//loops through the counter list and if there is a 2 there then it signifies a pair.
   for(i=0; i<FACES; i++){
      if(counter[i]==2){
        printf("There is a pair of %ss.\n", wFace[i]);
      }
   } 
}

//Checks if there is three of a kind
void threeOfAKind(const char* wFace[], Card* hand){
   int counter[FACES]={0};
   int i, j;
//loops through the values checking if there are three of a kind. adds one to the counter list for every match.
   for(i=0; i<FACES; i++){
      for(j=0; j<5; j++){
         if(wFace[i] == hand[j].face){
            counter[i]++;
         }
      }
   }
//loops through the counter list and if there is a 3 there then it signifies a pair.
   for(i=0; i<FACES; i++){
      if(counter[i]==3){
        printf("There are 3 %ss.\n", wFace[i]);
      }
   }
}

//Checks if there is four of a kind
void fourOfAKind(const char* wFace[], Card* hand){
   int counter[FACES]={0};
   int i, j;
//loops through the values checking if there are four of a kind. adds one to the counter list for every match.
   for(i=0; i<FACES; i++){
      for(j=0; j<5; j++){
         if(wFace[i] == hand[j].face){
            counter[i]++;
         }
      }
   }
//loops through the counter list and if there is a 3 there then it signifies a pair.
   for(i=0; i<FACES; i++){
      if(counter[i]==4){
        printf("There are 4 %ss.\n", wFace[i]);
      }
   }
}

//checks if they are all the same suit
void flush(const char* wSuit[], Card* hand){
   int counter[SUITS] = {0};
   int i, j;
//loops through the values checking if all the suits match
   for(i=0; i<SUITS; i++){
      for(j=0; j<5; j++){
         if(wSuit[i] == hand[j].suit){
            counter[i]++;
         }
      }
   }
//If all the suits match then they will print.
   for(i=0; i<SUITS; i++){
      if(counter[i]==5){
        printf("There is a flush of %ss.\n", wSuit[i]);
      }
   }
}

//checks if they are in sequence.
void straightHand(const char* wFace[], Card* hand){
   int i, j, copy_hand[5], x_copy;

//holds index position of the faces in the hand
   for(i=0; i<FACES; i++){
      for(j=0; j<5; j++){
         if(wFace[i] == hand[j].face){
            copy_hand[j] = i;
         }
      }
   }
//bubble sort
   for(i=1; i<5; i++){
      for(j=0; j<4; j++){
         if(copy_hand[i]<copy_hand[j]){
            x_copy = copy_hand[i];
            copy_hand[i]=copy_hand[j];
            copy_hand[j]=x_copy;        
         }
      }
   }

   if((copy_hand[1] == copy_hand[0]+1) && (copy_hand[2] == copy_hand[1]+1) && (copy_hand[3]==copy_hand[2]+1) && (copy_hand[4] == copy_hand[3]+1)){
      printf("There is a straight from %s to %s.\n", wFace[copy_hand[0]], wFace[copy_hand[4]]);
   }
}
