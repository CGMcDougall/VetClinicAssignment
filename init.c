#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defs.h"



void initAnimalArray(AnimalArrayType *arr){
  arr->size = 0;
}

void initAnimal(int id, SpeciesType sp, char *name, char *g, int y, int m, AnimalType **an){

	AnimalType *a;
	a = malloc(sizeof(AnimalType));

	a->id = id;
	a->species = sp;
	a->age = m+(y*12);

	a->parent = NULL;

	strcpy(a->name, name);
	strcpy(a->gender,g);

	*an = a;

}


void initAnimals(AnimalArrayType *arr)
{
  AnimalType *a;

  initAnimalArray(arr);

  initAnimal(1008, C_DOG, "Lily", "F", 1, 6, &a);
  addAnimal(arr, a);
  initAnimal(1001, C_DOG, "Betsy", "F", 5, 0, &a);
  addAnimal(arr, a);
  initAnimal(1002, C_DOG, "Killer", "F", 3, 5, &a);
  addAnimal(arr, a);
  initAnimal(1004, C_DOG, "Fluffy", "M", 2, 7, &a);
  addAnimal(arr, a);
  initAnimal(1013, C_CAT, "Lady", "F", 11, 0, &a);
  addAnimal(arr, a);
  initAnimal(1029, C_SPEC_OTHER, "Pecorino", "M", 0, 3, &a);
  addAnimal(arr, a);
  initAnimal(1007, C_DOG, "Leon", "M", 4, 0, &a);
  addAnimal(arr, a);
  initAnimal(1027, C_SPEC_OTHER, "Quasar", "M", 1, 4, &a);
  addAnimal(arr, a);
  initAnimal(1016, C_CAT, "Shadow", "M", 5, 2, &a);
  addAnimal(arr, a);
  initAnimal(1017, C_CAT, "Luka", "M", 7, 0, &a);
  addAnimal(arr, a);
  initAnimal(1018, C_CAT, "Fiona", "F", 8, 0, &a);
  addAnimal(arr, a);
  initAnimal(1021, C_CAT, "Ruby", "F", 5, 0, &a);
  addAnimal(arr, a);
  initAnimal(1023, C_SPEC_OTHER, "Ziggy", "F", 3, 8, &a);
  addAnimal(arr, a);
  initAnimal(1024, C_SPEC_OTHER, "Quark", "M", 9, 0, &a);
  addAnimal(arr, a);
  initAnimal(1032, C_SPEC_OTHER, "Gruyere", "M", 0, 3, &a);
  addAnimal(arr, a);
  initAnimal(1033, C_SPEC_OTHER, "Limburger", "M", 0, 3, &a);
  addAnimal(arr, a);
}

void initCustomerArray(CustomerArrayType *arr){

	arr->arr = malloc(MAX_ARR*sizeof(CustomerType*));
	arr->size = 0;

}

void initCustomer(int id,char *name, CustomerType **cust){
	CustomerType *c;
	c = malloc(sizeof(CustomerType));

	c->id = id;
	strcpy(c->name,name);

	initAnimalArray(&c->pets);

	*cust = c;


}




void initCustomers(ClinicType *clinic)
{
  CustomerArrayType *arr = &clinic->custArr;
  CustomerType *c;

  initCustomerArray(arr);

  initCustomer(4010, "Lee", &c);
  addCustomer(arr, c);
  initCustomer(4012, "Kara", &c);
  addCustomer(arr, c);
  initCustomer(4015, "Laura", &c);
  addCustomer(arr, c);
  initCustomer(4016, "Gaius", &c);
  addCustomer(arr, c);
  initCustomer(4019, "Bill", &c);
  addCustomer(arr, c);
  initCustomer(4025, "Sharon", &c);
  addCustomer(arr, c);
  initCustomer(4028, "Karl", &c);
  addCustomer(arr, c);
  initCustomer(4029, "Sonja", &c);
  addCustomer(arr, c);

  addToCustomer(clinic, 4010, 1002);
  addToCustomer(clinic, 4025, 1024);
  addToCustomer(clinic, 4025, 1027);
  addToCustomer(clinic, 4015, 1013);
  addToCustomer(clinic, 4015, 1023);
  addToCustomer(clinic, 4012, 1029);
  addToCustomer(clinic, 4012, 1033);
  addToCustomer(clinic, 4012, 1032);
  addToCustomer(clinic, 4029, 1007);
  addToCustomer(clinic, 4029, 1008);
  addToCustomer(clinic, 4019, 1016);
  addToCustomer(clinic, 4019, 1017);

  addToCustomer(clinic, 4021, 1001);
  addToCustomer(clinic, 4016, 1015);
  addToCustomer(clinic, 4016, 1002);
}

//initApointment
int initAppointment(AnimalArrayType *animals, int id, int anId, int y, int m, int d, int h, int mn, AppointmentType **appt){

	AnimalType *an;

	if(findAnimal(animals,anId,&an) == C_NOK){
		printf("Couldnt find an Animal with id :%d\n",anId);
		return C_NOK;
	}
  //printf("Hour:%d\n",h);
	if(h < 9 ||  h > 16){
		printf("The hour of the appintment is not bewteen 9am and 4pm\n");
		return C_NOK;
	}
	if(mn != 0 && mn % 15 != 0){
		printf("Appointment doesnt start at appropriate time in hour\n");
		return C_NOK;
	}

	DateType *date;
  date = malloc(sizeof(DateType));
	date->year = y;
	date->month = m;
  date->day = d;
	date->tt.hour = h;
	date->tt.mins = mn;



	AppointmentType *a;
	a = malloc(sizeof(AppointmentType));
	a->id = id;
	a->dt = date;
	a->animal = an;
	a->cust = an->parent;



	*appt = a;

	return C_OK;


}


void initClinic(ClinicType *c, char *name){

	strcpy(c->name,name);
	initAnimals(&c->animalArr);
	initCustomers(c);
  initSchedule(&c->masterSchedule,&c->animalArr);


}



void initSchedList(ScheduleType *sched){

  ListType *L;
  L = malloc(sizeof(ListType));
  L->Head = NULL;
  L->size = 0;
  //sched->List = malloc(MAX_ARR*sizeof(ListType));
  sched->List = L;


}


void initSchedule(ScheduleType *sched, AnimalArrayType *animals)
{
  AppointmentType *appt;

  initSchedList(sched);

  if (initAppointment(animals, 7010, 1001, 2021, 10, 3, 11, 15, &appt) == 0)
    addAppointment(sched, appt);
  if (initAppointment(animals, 7011, 1013, 2021, 10, 3, 11, 30, &appt) == 0)
    addAppointment(sched, appt);
  if (initAppointment(animals, 7012, 1013, 2021, 10, 3, 11, 45, &appt) == 0)
    addAppointment(sched, appt);
  if (initAppointment(animals, 7018, 1021, 2021, 10, 3, 11, 45, &appt) == 0)
    addAppointment(sched, appt);
  if (initAppointment(animals, 7019, 1021, 2021, 10, 3, 12, 0, &appt) == 0)
    addAppointment(sched, appt);
  if (initAppointment(animals, 7015, 1032, 2021, 10, 3, 11, 0, &appt) == 0)
    addAppointment(sched, appt);
  if (initAppointment(animals, 7016, 1032, 2021, 10, 3, 11, 0, &appt) == 0)
    addAppointment(sched, appt);
  if (initAppointment(animals, 7014, 1023, 2021, 11, 3, 10, 0, &appt) == 0)
    addAppointment(sched, appt);
  if (initAppointment(animals, 7005, 1007, 2021, 11, 3, 9, 45, &appt) == 0)
    addAppointment(sched, appt);
  if (initAppointment(animals, 7007, 1007, 2021, 11, 3, 9, 30, &appt) == 0)
    addAppointment(sched, appt);
  if (initAppointment(animals, 7008, 1017, 2021, 10, 2, 11, 15, &appt) == 0)
    addAppointment(sched, appt);

  if (initAppointment(animals, 7017, 1015, 2021, 11, 3, 11, 15, &appt) == 0)
    addAppointment(sched, appt);
  if (initAppointment(animals, 7013, 1029, 2018, 10, 1, 11, 45, &appt) == 0)
    addAppointment(sched, appt);
  if (initAppointment(animals, 7013, 1029, 2021, 14, 1, 11, 45, &appt) == 0)
    addAppointment(sched, appt);
  if (initAppointment(animals, 7013, 1029, 2021, 10, 41, 11, 45, &appt) == 0)
    addAppointment(sched, appt);
  if (initAppointment(animals, 7013, 1029, 2021, 10, 1, 1, 45, &appt) == 0)
    addAppointment(sched, appt);
  if (initAppointment(animals, 7013, 1029, 2021, 10, 1, 11, 25, &appt) == 0)
    addAppointment(sched, appt);
}
