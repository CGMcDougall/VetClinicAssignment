#include <stdio.h>
#include <stdlib.h>
#include "defs.h"


int addCustomer(CustomerArrayType *arr, CustomerType *cust){

	arr->arr[arr->size] = cust;
	++(arr->size);
}

int findCustomer(CustomerArrayType *arr, int id, CustomerType **cust){

	for(int i = 0; i < arr->size; ++i){
		CustomerType *c = arr->arr[i];
		if(c->id == id){
			*cust = c;
			return C_OK;
		}
	}
	return C_NOK;

}

int addToCustomer(ClinicType *clinic, int custId, int animalId){

	CustomerType *c;
	AnimalType *a;

	if(findCustomer(&clinic->custArr,custId,&c) == C_NOK){
		printf("Couldnt find Customer\n");
		return C_NOK;
	}

	if(findAnimal(&clinic->animalArr,animalId,&a) == C_NOK){
		printf("Couldnt find Animal\n");
		return C_NOK;
	}

	if(a->parent != NULL){
		printf("Pet already has Owner\n");
		return C_NOK;
	}

	if(addAnimal(&c->pets,a) == C_NOK){
		printf("Couldnt add pet to owners pet collection\n");
		return C_NOK;
	}

	//printf(c-)
	a->parent = c;

	return C_OK;
}

void printCustomer(CustomerArrayType *arr){

	for(int i = 0; i < arr->size; ++i){
		printf("ID :%d, Name :%s,",arr->arr[i]->id,arr->arr[i]->name);

		if(arr->arr[i]->pets.size != 0){
				printf(" Has following Pets:\n");
				printAnimals(&arr->arr[i]->pets);
			}

		else
				printf(" Has no Pets\n");

		printf("\n");

	}

}

void cleanupCustomers(CustomerArrayType *arr){

	for(int i = 0; i < arr->size; ++i){
		CustomerType *c = arr->arr[i];
		free(c);
	}
	free(arr->arr);
}
