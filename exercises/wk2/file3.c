/*Debugging quiz - File No: 3 */
/* This program should perform the duties of a basic calculator and print whether the result is >100 or <100 or equal to 100 */
/* the program should ask for the input until 'q' is enterd */
// Check for possible logical errors and rectify them 


#include<stdio.h>

int main(void){
  char input;
  float num1, num2, result;
   
  while(input != 'q')
  {
  printf("Welcome to the Calculator\nOperation choices:\tAddition(A)\n\t\t\tSubtraction(S)\n\t\t\tMultiplication(M)\n\t\t\tDivision(D)\nEnter choice: ");

  scanf(" %c", &input);

  if(input == 'A' || input == 'S' || input == 'M' || input == 'D'){
    printf("Enter both numbers in required sequence: ");
    scanf(" %f %f", &num1, &num2);
  
    switch(input){
      case 'A': 
        result = num1 + num2;
        break;  
      case 'S': 
        result = num1 - num2;
      case 'M': 
        result = num1 * num2;
      	break; 
      case 'D': 
        result = num1 / num2; 
        break;
      default: ;		
    }

    if(result < 100){
      printf("Result is %f and is less than 100.\n", result);
    }
    else if(result == 100) {
      printf("Result is %f and is Equal to 100\n", result);
    }
    else if (result > 100){
      printf("Result is %f and is Equal to 100\n", result);
    }
  

  }else{
    printf("Please choose a valid operation\n");
  } 
  printf("Quit the menu.(q)\n");
  }
  return 0;
}
