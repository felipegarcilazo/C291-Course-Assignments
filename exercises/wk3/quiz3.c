/* Instructions:
 *
 *
 1. Write a program to assign a grade to Student. 
	Get the number of assignmnets from user.
  Get the students score out of how many points for each assignmnet.
	Calculate percentage and return the grade associated with a range of marks.

 2. The overall score range and the associated grades are as follows:
     a. [97-100] = A+
     b. [90-97] = A
     c. [80-90] = B
     d. [70-80] = C
     e. less than 70 is a failing grade and should be given an F
     e. greater than 100 or less than 0 is invalid and your code should print "Invalid"

 3. Use the skeleton code provided below to create a new function "printGrade" to assign a grade based on the score ranges.

 4. Use print statements in your function to display the grade. For example, if the input marks is 77, the output should read:
        "Your grade is : C"

 5. Please adhere to standard C syntax conventions and use comments to explain your code. Failure to do so will result in a penalty.

 *
 *
 **/

#include<stdio.h>
int printGrade(int score);

int main(void){
	char ch;
	float g_score, g_max_score, score, max_score;
	int assignments, i;
	do {
		printf("How many assignmnets did you have ? ");

    //get the number of assignmnets from the student
                scanf(" %d", &assignments);

		printf("Enter your score for all assignments:\n" );

    //get the student's score and the max score for each assignment
                for(i = 1; i <= assignments; i++){
                  printf("Enter your score for assignment %d:\n", i);
                  scanf(" %f", &score);
		  g_score += score;
                  printf("Enter the max score possible for assignment %d:\n", i);
                  scanf(" %f", &max_score);
                  g_max_score += max_score;
		}  
    //calculate the student's percentage in the class using the information you've gathered.
		  float percent;
                  percent = ((g_score/g_max_score)*100);
		  printf("Your Percentage in the class is %f%%\n", percent);		 
		  printGrade(percent);

		printf(" \nDo you want to continue? (Y/N) ");
		scanf(" %c",&ch);
	} while(ch == 'y'|| ch == 'Y');
}

int printGrade(int score){
        //print the students grade based on their score in the class
        if (100>=score && score>=97){
	  printf("Your Grade in the class is: A+\n");
        }else if(97>score && score>=90){
	  printf("Your Grade in the class is: A\n");
	}else if(90>score && score>=80){
	  printf("Your Grade in the class is: B\n");
        }else if(80>score && score>=70){
	  printf("Your Grade in the class is: C\n");
	}else if(70>score && score>=0){
          printf("Your Grade in the class is: F\n");
        }
        else{
	  printf("Invalid\n");
	}
}
