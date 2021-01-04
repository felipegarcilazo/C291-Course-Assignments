/*
Felipe Garcilazo
02/18/20

Question 3
*/

#include<stdio.h>

unsigned packCharacters(unsigned char1, char char2);

int main(){
  char let1, let2, let3, let4;
  unsigned combine1, combine2, combine3;
//Getting inputs
  printf("Enter first character:\n");
  scanf(" %c", &let1);
  printf("Enter second character:\n");
  scanf(" %c", &let2);  
  printf("Enter third character:\n");
  scanf(" %c", &let3);
  printf("Enter fourth character:\n");
  scanf(" %c", &let4);
//call function packCharacters
  unsigned ch = let1;
  combine1 = packCharacters(ch, let2);
  combine2 = packCharacters(combine1, let3);
  combine3 = packCharacters(combine2, let4);
//printfing the final product:
  printf("%c, %c, %c, and %c are represented in bits as an unsigned integer is:\n", let1, let2, let3, let4);
  unsigned i;
  unsigned mask = 1<<31;
  for(i=1; i<=32; i++){
    combine3 & mask ? putchar('1') : putchar('0');
    combine3 <<= 1;
    if(i%8==0){
      printf(" ");
    }
  }
  printf("\n");
  return 0;
}

unsigned packCharacters(unsigned char1, char char2){
  unsigned packing = char1;
//shift the unsigned by 8 bits
  packing <<= 8;
//using bitwise or
  packing|=char2;
  return packing;
}
