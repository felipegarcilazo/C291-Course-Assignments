// Program to read integers into a 3X3 matrix and display them

#include <stdio.h>
void display(int Matrix[3][3],int size);

int main(void) {
	
	int size = 3, Matrix[size][size];
	printf("Enter 9 elements of the matrix:\n");
	int i;
	for (i = 0; i < size; i++)
    {
      int j = 0;
      for (; j < size; j++){
        scanf(" %d", &Matrix[i][j]);
      }
    }
	display(Matrix,size);
	return 0;
}

void display(int Matrix[3][3], int size) {
	int i, j;	
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) 
      {
        printf("%d, ", Matrix[i][j]);
      }
		printf("\n");
	}
}
