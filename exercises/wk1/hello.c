/* 
 * Basic C program to print out hello world! 
 * Author: Adeel Bhutta
*/

#include <stdio.h>
#include <unistd.h>

int main(void) {
  printf("\"{Hello: Welcome to Year 2020!},/\\ This is Spring 2020\'s 1st 8 Week Course @IU\"\n");
  printf("Felipe Garcilazo");
  int count = 1;
  while (1) {
    printf(".");
    sleep(1);
    if (count % 7 == 0) {
      printf("\n");
      }
    count++;
  }
/* 
  int myNumber = 0;
  printf("Hello: Welcome to C291!\n");
  printf("Please enter a number and press ENTER: ");
  scanf("%d", &myNumber);  
  printf("Here is the number yor entered: %d\n",myNumber);
*/  
  return(0);
}


