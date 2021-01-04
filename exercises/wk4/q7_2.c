//This program includes a struct called cat that is used to store information about a given cat
//The program should ask the user for information about their cat and initialize a cat structure with the given information
//The program should also print the information using a pointer to the initialized struct
//The information printed using the struct and the pointer should be the same

#include <stdio.h>
#include <string.h>
// make name a string

struct cat{
	char* cat;
	int age;
	float speed;
};

int main(void){
	char n[20];
	int a;
	float w;

	struct cat c, *cPtr;
        cPtr = &c;


	printf("What is your favorite cat's name: ");
	scanf(" %20s", n);
	c.cat = n;

	printf("How old is it :" );
	scanf(" %d", &a);
	c.age = a;

	printf("How much speed does it give : ");
	scanf(" %f", &w);
	c.speed = w;
        

	printf("Cat's name is %s, and should be the same as %s.\n", c.cat, (*cPtr).cat);
	printf("Cat's age is %d, and should be the same as %d.\n", c.age, (*cPtr).age);
	printf("Cat's speed is %f, and should be the same as %f.\n", c.speed , (*cPtr).speed);
}
