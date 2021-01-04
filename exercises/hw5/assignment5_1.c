/*
Felipe Garcilazo
02/18/20

Question 1.
*/
#include<stdio.h>

int main(){
struct faculty{
        char lastName[20];
        char firstName[20];
        char* sis_username;
        unsigned int sis_id_number;
        struct {
                char phoneNumber[11];
                char address[60];
                char city[20];
                char state[3];
                char zipCode[6];
        }personal_address;
}facultyRecord, *facultyPtr;
facultyPtr = &facultyRecord;

	//1A:
  facultyRecord.firstName;
	//1B
  (*facultyPtr).firstName;
	//1C
  facultyRecord.sis_id_number;
	//1D
  facultyPtr->sis_id_number;
	//1E
  facultyRecord.sis_username = "bobjohn"; 
  printf("%s", facultyPtr->sis_username);
	//1F:
  facultyRecord.personal_address.phoneNumber;
	//1G
  facultyPtr->personal_address.address;
	//1H
  facultyPtr->personal_address.city;
	//1I
  facultyRecord.personal_address.state;
	//1J
  facultyRecord.personal_address.zipCode;
	//1K
  struct faculty facultyRecords[5];
  int i;
  for(i=0; i<5; i++){
    printf("%s\n", (facultyRecords[i]).personal_address.zipCode);
  }
  printf("\n");
	//1L
  struct faculty *facultyPtr2 = facultyRecords;
  for(i=0; i<5; i++){
    printf("%s\n", facultyPtr2[i].personal_address.zipCode);
  }
	return 0;
}
