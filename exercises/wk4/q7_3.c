//This program uses a function called CharacterScan to read a char from the user
//The function must take an int pointer as a parameter
//The program should print the char and ascii code for each character the user enters
//The program should only exit whe nthe user enters escape

#include <stdio.h>
#include <stdlib.h>
char CharacterScan(int* iPtr);

int main(void){
    int* iPtr;
    char exit;
    int aCode;
    while(1){
        char c = CharacterScan(iPtr); 
	aCode = (int) c;
        if(aCode == 27){
            printf("Exiting the code!\n");
            break;
        }
        else{
            printf("%c is ASCII code %d.\n", c, aCode);
        }
    }
}

char CharacterScan(int* iPtr){
    char c;
    printf("Enter a character: ");   
    scanf(" %c", &c);
    int a = (int) c;
    iPtr = &a;
    return c;
}
