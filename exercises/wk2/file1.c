/*Debugging quiz - File No: 1 */
/* using a for loop, print all the characters from A-Z*/
/* Print the sum of all odd numbers from 1 to 100 */
/* Correct the logical errors in the program */



#include<stdio.h>

int main (void){

  int limit = 26, sum = 0;
  char alph = 'A';
  printf("The limit is %d\n", limit);
  int counter;
  for(counter = 0; counter < limit; counter++){
      printf("%c ",alph++);  
  }
  limit = 100;
  printf("\nThe limit is %d\n", limit);
  for(counter = 0; counter < limit; counter++){
    if (counter%2==1){
      sum += counter;
    }
  }
  printf("Sum = %d\n", sum);
  return(0);
}
