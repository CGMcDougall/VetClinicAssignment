#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

char* getSpecies(SpeciesType);
char* getOwner(CustomerType*);



int addAnimal(AnimalArrayType *arr, AnimalType *an){

//	printf("NewInstance: %d\n",an->age);

	for(int i = 0; i <= arr->size; ++i){
		if(i == arr->size){
			arr->a[arr->size] = an;
			++(arr->size);
		return C_OK;
	}

	//	printf("TRY :%d, LISTED :%d\n",an->age,arr->a[i]->age);
		if(an->age <= arr->a[i]->age){



			for(int x = arr->size; x > i; --x)
				arr->a[x] = arr->a[x-1];

			arr->a[i] = an;

			++(arr->size);
			return C_OK;
		}
	}

	return C_NOK;

}

int findAnimal(AnimalArrayType *arr, int id, AnimalType **an){

	for(int i = 0; i < arr->size; ++i){
		if(arr->a[i]->id == id){
			*an = arr->a[i];
			return C_OK;
		}
	}
	return C_NOK;
}


void printAnimals(AnimalArrayType *arr){

	for(int i = 0; i < arr->size; ++i){
		AnimalType *a = arr->a[i];
		char* spec = getSpecies(a->species);
		char* owner = getOwner(a->parent);


		printf("ID :%d,  Name :%10s,  Species :%5s,  Age :%3d,  Parents Name: %7s\n",a->id,a->name, spec, a->age,owner);

	}

}

void cleanupAnimals(AnimalArrayType *arr){

for(int i = 0; i < arr->size; ++i){
	//free(arr->a[i]->parent);
	free(arr->a[i]);
	}
	//free(arr);
}


char* getSpecies(SpeciesType s){
	if(s == 0)
		return "Dog";
	if(s == 1)
		return "Cat";

	return "Other";
}

char* getOwner(CustomerType *c){
	if(c == NULL){
		return "NONE";
	}
	return c->name;

}
