/*
Felipe Garcilazo
02/4/2020
*/

#include<stdio.h>
#include<stdlib.h> 
#include<time.h> 

int airplane_array[6][12], seats_arr[72][2], funct_random(int min, int max), funct_first(), funct_business(), funct_economy(), funct_map(), funct_names(), funct_boarding_pass(char row_char, int col_num), counter_ns=0;
char funct_full_checker(char class), names_arr[72][10];

int main(){
 int menu2, column_pass; 
 char user_menu, row_pass;

 while(1){

	//Menu
 
  printf("Welcome to Airline Reservation System\nPlease enter your name to begin\n");
  scanf(" %9s", names_arr[counter_ns]);
  printf("\nPlease select the Seat that you would prefer:\n\tPlease type 'F' for First Class.\n\tPlease type 'B' for Business Class.\n\tPlease type 'E' for Economy Clause.\n\tPress 'Q' to exit program.\n");
  scanf(" %c", &user_menu);

	// Handles input to assigned function 

  if (user_menu == 'F' || user_menu == 'f'){
   funct_first(); 
  }else if(user_menu == 'B' || user_menu == 'b') {
   funct_business();
  }else if(user_menu == 'E' || user_menu == 'e'){
   funct_economy();
  }else if(user_menu=='q' || user_menu == 'Q'){
   printf("Exiting Program now.\n");
   break;
  }else{
   printf("That is an invalid option!\n");
  }

	//This prints the 2nd Menu

  printf("\nEnter 1 to view the airplane seating map. 1 represents that the seat is taken and 0 signifies empty.\nEnter 2 to table all the names and seat number of passengers.\nEnter 3 to view a boarding pass of a seat.\n");
  scanf(" %d", &menu2);
  if(menu2 == 1){
   funct_map();
  }else if(menu2 == 2){
   funct_names();
  }else if(menu2 == 3){
   printf("Enter the row.(A, B, C, D, E, F)\n");
   scanf(" %c", &row_pass);
   printf("Enter the row.(1-12)\n");
   scanf(" %d", &column_pass);
   funct_boarding_pass(row_pass, column_pass);
  }else{
   printf("That is an invalid option");
  }
 }
 return 0;
}

int funct_random(int min, int max){

	// My Random Generator that will randomly select numbers for the random seat assignment

 int num = (rand() % (max-min+1))+min;
 return num;
}

char funct_full_checker(char class){

	// Checks to see if the specified section is full, returns T if there is an open position and returns F if no seats are available

 int i, j;
 char seat_available;
 if(class == 'F'){
  for(i=0; i<6; i++){
   for(j=0; j<2; j++){
    if (airplane_array[i][j] == 0){
     seat_available = 'T';
     return seat_available;
    }
   }
  } 
 }else if(class=='B'){
  for(i=0; i<6; i++){
   for(j=2; j<5; j++){
    if (airplane_array[i][j] == 0){
     seat_available = 'T';
     return seat_available;
    }
   }
  }
 }else if(class=='E'){
  for(i=0; i<6; i++){
   for(j=5; j<12; j++){
    if(airplane_array[i][j] == 0){
     seat_available = 'T';
     return seat_available;
    }
   }
  }
 }
 seat_available = 'F';
 return seat_available;
}

int funct_first(){
 int counter=0, row, column;
 char downgrade, seat[4], repeat='Y';

	//Checks if First class section is full and if it is full if the customer would want to go to the business section.

 if (funct_full_checker('F')=='F'){
  printf("There are no available seats in First Class.\nWould you like to change seats in business.(y/n)\n");
  scanf(" %c", &downgrade);
  if(downgrade == 'y' || downgrade == 'Y'){
   funct_business();     
   return 0;
  }else if(downgrade == 'n' || downgrade == 'N'){
   printf("Next flight Leaves in 3 hours.\n");
  }else{
   printf("Invalid Option!\n");
   funct_first();
   return 0;
  }
 }

	//Loops until the user stops it or user has tried three separate times.

 do{

	//Randomly selects a seat in the first class section.

  row = funct_random(0, 5);
  column = funct_random(0, 1);

	//Checks if seat if not taken and prints out necessary information.

  if (airplane_array[row][column] == 0){ 

        //Prints window seat and information on seat.  

   printf("Your assigned seat is %c%d.\n", row+65, column+1);
   if(row == 0 || row==5){
    printf("Your seat is a window.\n");
   }else{
    printf("Your seat is not a window seat.\n");
   }
   printf("Would you like to change seats.(y/n)\n");
   scanf(" %c", &repeat);
   counter++;
  }
 }while((repeat == 'y' || repeat == 'Y') && counter < 3);
 
	//Reserves seat in the system. 

 printf("Finalizing seat in %c%d.\n", row+65, column+1);
 airplane_array[row][column] = 1;
 seats_arr[counter_ns][0] = row+65;
 seats_arr[counter_ns][1] = column+1;
 counter_ns++;
 return 0;
}

int funct_business(){
 int counter=0, row, column;
 char upgrade, downgrade, repeat='Y';

        //Checks if Business class section is full and if it is full if the customer would want to go to the economy section. 
 
 if (funct_full_checker('B')=='F'){
  printf("There are no available seats in Business Class.\nWould you like to change seats in Economy Class.(y/n)\n");
  scanf(" %c", &downgrade);
  if(downgrade == 'y' || downgrade == 'Y'){
   funct_business();
   return 0;
  }else if(downgrade == 'n' || downgrade == 'N'){
   printf("Next flight Leaves in 3 hours.\n");
  }else{
   printf("Invalid Option!\n");
   funct_business();
   return 0;
  }
 }

        //Loops until the user stops it or user has tried three separate times.
 
 do{

        //Randomly selects a seat in the first class section.

  row = funct_random(0, 5);
  column = funct_random(2, 4);

        //Checks if seat if not taken and prints out necessary information.


  if (airplane_array[row][column] == 0){

        //Prints window seat and information on seat.  

   printf("Your assigned seat is %c%d.\n", row+65, column+1);
   if(row == 0 || row==5){
    printf("Your seat is a window.\n");
   }else{
    printf("Your seat is not a window seat.\n");
   }
   printf("Would you like to change seats.(y/n)\n");
   scanf(" %c", &repeat);
   counter++;
  }
 }while((repeat == 'y' || repeat == 'Y') && counter < 3);

	//Upgrade option

 if(funct_full_checker('F')=='T'){
  printf("Would you like to upgrade to First Class(y/n)!\n");
  scanf(" %c", &upgrade);
  if(upgrade == 'y' || upgrade == 'Y'){
   funct_first();
   return 0;
  }
 }

        //Reserves seat in the system. 

 printf("Finalizing seat in %c%d.\n", row+65, column+1); 
 airplane_array[row][column] = 1;
 seats_arr[counter_ns][0] = row+65;
 seats_arr[counter_ns][1] = column+1; 
 counter_ns++;
 return 0;
}

int funct_economy(){
 int counter=0, row, column;
 char upgrade, downgrade, repeat='Y';

        //Checks if Economy class section is full and if it is full if the customer would want to go to the ecosection.

 if (funct_full_checker('B')=='F'){
  printf("There are no available seats in Economy Class.\nWould you like to upgrade to business Class.(y/n)\n");
  scanf(" %c", &downgrade);
  if(downgrade == 'y' || downgrade == 'Y'){
   funct_business();
   return 0;
  }else if(downgrade == 'n' || downgrade == 'N'){
   printf("Next flight Leaves in 3 hours.\n");
  }else{
   printf("Invalid Option!\n");
   funct_economy();
   return 0;
  }
 }

        //Loops until the user stops it or user has tried three separate times.

 do{

        //Randomly selects a seat in the first class section.

  row = funct_random(0, 5);
  column = funct_random(5, 11);

        //Checks if seat if not taken and prints out necessary information.

  if (airplane_array[row][column] == 0){

        //Prints window seat and information on seat.  

   printf("Your assigned seat is %c%d.\n", row+65, column+1);
   if(row == 0 || row==5){
    printf("Your seat is a window.\n");
   }else{
    printf("Your seat is not a window seat.\n");
   }
   printf("Would you like to change seats.(y/n)\n");
   scanf(" %c", &repeat);
   counter++;
  }
 }while((repeat == 'y' || repeat == 'Y') && counter < 3);

        //Upgrade option

 if(funct_full_checker('F')=='T'){
  printf("Would you like to upgrade to Business Class(y/n)!\n");
  scanf(" %c", &upgrade);
  if(upgrade == 'y' || upgrade == 'Y'){
   funct_business();
   return 0;
  }
 }

        //Reserves seat in the system.

 printf("Finalizing seat in %c%d.\n", row+65, column+1);
 airplane_array[row][column] = 1;
 seats_arr[counter_ns][0] = row+65;
 seats_arr[counter_ns][1] = column+1;
 counter_ns++;
 return 0;   
}

int funct_map(){
 int i, j;
 
	//Displays the map of the airplane with 1 and 0.
 
 printf("\n\t\tWindow\n");
 for(i=0; i<6; i++){
  for(j=0; j<12; j++){
   printf("%d, ", airplane_array[i][j]);
  }
  printf("\n");
  if(i==2){
   printf("\n\n");
  }
 }
 printf("\n\t\tWindow\n\n");
 return 0;
}

int funct_names(){
 int i;

	//Prints names and seats that are occupied.

 printf("Name\tSeat Number\n---------------------------------------------\n");
 for(i=0; i<counter_ns; i++){
  printf("%s\t%c%d\n", names_arr[i], seats_arr[i][0], seats_arr[i][1]);   
 }
 printf("\n");
 return 0;
}

int funct_boarding_pass(char row_char, int col_num){
 int i, row_num = 0;
 row_num = row_char;

	//Searches for the boarding seat and prints out the information needed.
	
 for(i=0; i<counter_ns; i++){
  if(row_num == seats_arr[i][0]){
   if(col_num == seats_arr[i][1]){
    if(col_num<=2){
     printf("%s, SEAT: %c%d, Level: First Class.\n", names_arr[i], seats_arr[i][0], seats_arr[i][1]);
    }else if(col_num>=3 && col_num<=5){
     printf("%s, SEAT: %c%d, Level: Business Class.\n", names_arr[i], seats_arr[i][0], seats_arr[i][1]);
    }else if(col_num>=5 && col_num<=12){
     printf("%s, SEAT: %c%d, Level: Economy Class\n", names_arr[i], seats_arr[i][0], seats_arr[i][1]);
    }
    return 0;
   }
  }
 }
 printf("There was no passenger sitting in %c%d.\n", row_char, col_num);
 return 0; 
}
