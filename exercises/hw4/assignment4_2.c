/*
Felipe Garcilazo
2/11/20
Question 2:
*/

#include<stdio.h>

int main(){

	//2A
 long value2, value1 = 2000000;
 long* lPtr;
 
	//2B
 lPtr = &value1;
 
	//2C
 printf("%d", *lPtr);

	//2D
 value2 = *lPtr;

	//2E
 printf("%d\n", value2);

	//2F
 printf("%p\n", &value1);

	//2G
 //Yes the addressses are the same.
 printf("%p", lPtr);
 return 0;
}
