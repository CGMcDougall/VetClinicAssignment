#include <stdio.h>

#include "defs.h"


int main()
{
	ClinicType c;
	initClinic(&c,"c");

	AppointmentType *a;
	int uniqueId =0;

  int  choice = -1;
  int id,year,month,day,hour,mins;



  while (choice != 0) {

    printMenu(&choice);
    if (choice == 0){
				cleanupClinic(&c);
				break;
		}


    switch(choice) {
      case 1:   // Create appointment

	printf("Input the Id for Animal\n");
	scanf("%d",&id);
	printf("Enter the Year\n");
	scanf("%d",&year);
	printf("Enter the month\n");
	scanf("%d",&month);
	printf("Enter the Day\n");
	scanf("%d",&day);
	printf("Enter the hour\n");
	scanf("%d",&hour);
	printf("Enter th minutes\n");
	scanf("%d",&mins);

	printf("%d,%d,%d,%d,%d,%d\n",id,year,month,day,hour,mins);

	if(initAppointment(&c.animalArr,uniqueId,id,year,month,day,hour,mins,&a) == C_OK){
			if(addAppointment(&c.masterSchedule,a) == C_OK){
					uniqueId++;
					printf("Appointment Succefully Added\n");
					}
			}

        break;


      case 2:   // Print schedule
				printSchedule(&c.masterSchedule);
        break;

      case 3:   // Print animals
				printAnimals(&c.animalArr);
        break;

      case 4:   // Print customers
				printCustomer(&c.custArr);
        break;

      default:
        printf("ERROR:  invalid option\n");
    }
  }


  return 0;
}

void printMenu(int *choice)
{
  int c = -1;
  int numOptions = 4;
  char str[MAX_STR];

  printf("\nMAIN MENU\n");
  printf("  (1) Create appointment\n");
  printf("  (2) Print schedule\n");
  printf("  (3) Print animals\n");
  printf("  (4) Print customers\n");
  printf("  (0) Exit\n\n");

  printf("Please enter your selection: ");
  fgets(str, sizeof(str), stdin);
  sscanf(str, "%d", &c);

  if (c == 0) {
    *choice = c;
    return;
  }

  while (c < 0 || c > numOptions) {
    printf("Please enter your selection: ");
    fgets(str, sizeof(str), stdin);
    sscanf(str, "%d", &c);
  }

  *choice = c;
}
