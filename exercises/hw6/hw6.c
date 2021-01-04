#include <stdio.h>
#include <stdlib.h>

#define NUM_LINES 4

int main(){
//initializes variables and file pointers
  char name[50];
  float currentBalance, dollarAmount[4], sum_balances = 0;
  int accountNum, accountNum2[4], i, x, num_customers=0;

  FILE* ofPtr = fopen( "oldmast.dat", "r" );
  if(ofPtr==NULL){
    printf("Error!");
    exit(1);
  }
  FILE* tfPtr = fopen( "trans.dat", "r" );
  if(tfPtr==NULL){
    printf("Error!");
    exit(1);
  }
  FILE* nfPtr = fopen( "newmast.dat", "w" );
  if(nfPtr==NULL){
    printf("Error!");
    exit(1);
  }  

//This for loop is used to match the account numbers and putting it in the newmast.dat.
  for(i=0; i<NUM_LINES; i++){
    fscanf(ofPtr, "%[^\t]\t%f\t%d", name, &currentBalance, &accountNum);
    for(x=0; x<NUM_LINES; x++){
      fscanf(tfPtr, "%d\t%f", &accountNum2[x], &dollarAmount[x]);
      if(accountNum == accountNum2[x]){
        currentBalance -= dollarAmount[x];
      } 
    }
    fprintf(nfPtr, "%s\t%.2f\t%d", name, currentBalance, accountNum);
    num_customers++;
    sum_balances += currentBalance;
    rewind(tfPtr);
  }

  fclose(tfPtr);
  fclose(nfPtr);  
  rewind(ofPtr);

//This loop is for printing the account number in the trans.dat that do not have an account number in oldmast.dat  
  for(i=0; i<NUM_LINES; i++){
    int counter=0;
    for(x=0;x<NUM_LINES;x++){
      fscanf(ofPtr, "%[^\t]\t%f\t%d", name, &currentBalance, &accountNum);
      if(accountNum2[i]!=accountNum){
        counter++;
      }
    }
    if(counter==4){//if counter is equal to four then there is an unmatched transaction
      printf("Unmatched transaction record for account number %d\n", accountNum2[i]);
    }
    rewind(ofPtr);
  }

  fclose(ofPtr);

//This is the third file that contains the  
  FILE* thPtr = fopen("third_file.dat", "w");
  if(thPtr==NULL){
    printf("Error!");
    exit(1);
  } 
  fprintf(thPtr, "%d\n%.2f", num_customers, sum_balances);
  fclose(thPtr);

  return 0;
}

//bonus question
/*
int clean_quotes(){
  char* name1;
  char* name2;
  char* name3;
  printf("Enter name with no quotes:\n");
  scanf("%s", name1);
  printf("Enter name with double quotes:\n");
  scanf("%*c%[^\"]", name2);
  printf("Enter name with single quotes:\n");
  scanf("%*c%[^']", name3);

  printf(" %c", *name3);

  return 0;
}
*/
