#include <stdio.h>
#include <stdlib.h>
#include "defs.h"


void cleanupClinic(ClinicType *c){
	cleanupAnimals(&c->animalArr);
	cleanupCustomers(&c->custArr);
	cleanupSchedule(&c->masterSchedule);

}
