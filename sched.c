	#include <stdio.h>
#include <stdlib.h>
#include "defs.h"



int compareDates(DateType *d1, DateType *d2){


	if(d1->year < d2->year)
		return C_OK;


	if(d1->year == d2->year){
		if(d1->month < d2->month)
			return C_OK;
		if(d1->month == d2->month){
			if(d1->day < d2->day)
				return C_OK;
			if(d1->day == d2->day){
				if((d1->tt.hour*60)+d1->tt.mins < (d2->tt.hour*60)+d2->tt.mins)
				       return C_OK;

			}
		}
	}

	return C_NOK;

}


int overlapAppts(AppointmentType *a1, AppointmentType *a2){
//all apointments are 30 mins

	DateType *d1 = a1->dt;
	DateType *d2 = a2->dt;

	if(d1->year == d2->year && d1->month == d2->month && d1->day == d2->day){

		if(d1->tt.mins == d2->tt.mins && d1->tt.hour == d2->tt.hour)
				return C_NOK;

		if(d1->tt.hour - d2->tt.hour >= -1 && d1->tt.hour - d2->tt.hour <= 1){
				if(d1->tt.mins - d2->tt.mins >= -15 && d1->tt.mins - d2->tt.mins <= 15){
						return C_NOK;
					 	}
				}
	}

	//printf("D1 : %02d:%02d, D2 : %02d:%02d\n",d1->tt.hour,d1->tt.mins,d2->tt.hour,d2->tt.mins);
	return C_OK;

}


int addAppointment(ScheduleType *sched, AppointmentType *appt){
	//check for overlap
	NodeType *cur = sched->List->Head;
	NodeType *least = NULL;
	NodeType *next;
	NodeType *new;


	while(cur != NULL){
		if(overlapAppts(cur->data,appt) == C_NOK){
			printf("This appointment overlapped with prexisting appointment\n");
			free(appt->dt);
			free(appt);
			return C_NOK;
			}

	cur = cur->next;
	}

	new = malloc(sizeof(NodeType));
	new->data = appt;
	new->prev = NULL;
	new->next = NULL;


	//Add it to Appointments
	cur=sched->List->Head;

	while(cur != NULL){
	if(compareDates(appt->dt,cur->data->dt) == C_OK)
			break;

		least = cur;
		cur= cur->next;
	}

	if(least == NULL)
		sched->List->Head = new;
	else
		least->next = new;

	new->prev = least;
	new->next = cur;

	if(cur != NULL)
		cur->prev = new;

return C_OK;
}


void printSchedule(ScheduleType *sched){
	NodeType *cur = sched->List->Head;
	NodeType *last;

	while(cur != NULL){

		printf("ID :%4d, Date :%d-%d-%d at %02d:%02d,",cur->data->id ,cur->data->dt->year ,cur->data->dt->month ,cur->data->dt->day ,cur->data->dt->tt.hour ,cur->data->dt->tt.mins);
		printf(" Animal : %7s\n",cur->data->animal->name);

		//printf("ID :%d, Date :%d-%d-%d at %02d:%02d, Customer : %s, Animal : %s\n",cur->data->id ,cur->data->dt->year ,cur->data->dt->month ,cur->data->dt->day ,cur->data->dt->tt.hour ,cur->data->dt->tt.mins ,cur->data->cust->name ,cur->data->animal->name );

	last = cur;
	cur = cur->next;
}

	printf("\n");
	cur = last;
	while(cur != NULL){
		//printf("ID :%d,Date :%d-%d-%d at %02d:%02d, Customer :%s, Animal :%s\n",cur->data->id,cur->data->dt->year,cur->data->dt->month,cur->data->dt->day,cur->data->dt->tt.hour,cur->data->dt->tt.mins,cur->data->cust->name,cur->data->animal->name);
		printf("ID :%d, Date :%d-%d-%d at %02d:%02d,",cur->data->id ,cur->data->dt->year ,cur->data->dt->month ,cur->data->dt->day ,cur->data->dt->tt.hour ,cur->data->dt->tt.mins);
		printf(" Animal : %s\n" ,cur->data->animal->name);

	cur = cur->prev;
	}

}


void cleanupSchedule(ScheduleType *sched){
	NodeType *cur = sched->List->Head;

	while(cur != NULL){
		NodeType *t;
		t = cur;
		cur = cur->next;
		free(t->data->dt);
		free(t->data);
		free(t);
	}
	free(sched->List);
}
