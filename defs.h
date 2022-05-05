#include <stdio.h>

#define C_TRUE     1
#define C_FALSE    0

#define C_OK       0
#define C_NOK     -1

#define MAX_STR   32
#define MAX_ARR  128

typedef enum {C_DOG, C_CAT, C_SPEC_OTHER} SpeciesType;

struct Customer;

typedef struct {
  int             id;
  SpeciesType     species;
  char            name[MAX_STR];
  char            gender[MAX_STR];
  int             age;
  struct Customer *parent;
} AnimalType;


typedef struct {
  int size;
  AnimalType* a[MAX_ARR];

} AnimalArrayType;

typedef struct Customer {
  int  id;
  char name[MAX_STR];
  AnimalArrayType pets;
} CustomerType;


typedef struct {

  int size;
  CustomerType **arr;

} CustomerArrayType;



typedef struct {
  int hour;
  int mins;
} TimeType;

typedef struct {
  int      year;
  int      month;
  int      day;
  TimeType tt;
} DateType;

typedef struct {
  int          id;
  DateType     *dt;
  CustomerType *cust;
  AnimalType   *animal;
} AppointmentType;

/*** Define the other data types here ***/

typedef struct Node {
  AppointmentType *data;
  struct Node *prev;
  struct Node *next;
} NodeType;

typedef struct {

  int size;
  NodeType *Head;

}ListType;


typedef struct {

  ListType *List;

}ScheduleType;

typedef struct {

  char name[MAX_STR];
  AnimalArrayType animalArr;
  CustomerArrayType custArr;
  ScheduleType masterSchedule;


}ClinicType;


void initSchedule(ScheduleType*,AnimalArrayType*);
void initSchedList(ScheduleType*);

int initAppointment(AnimalArrayType*,int,int,int,int,int,int,int,AppointmentType**);

//Main Functions
void initAnimalArray(AnimalArrayType*);
void initAnimals(AnimalArrayType*);
void initCustomerArray(CustomerArrayType*);
void initAnimal(int,SpeciesType,char*,char*,int,int,AnimalType**);


int addAnimal(AnimalArrayType*, AnimalType*);
int findAnimal(AnimalArrayType*,int,AnimalType**);
void printAnimals(AnimalArrayType*);
void cleanupAnimals(AnimalArrayType*);
int addCustomer(CustomerArrayType*,CustomerType*);
int findCustomer(CustomerArrayType*,int,CustomerType**);
int addToCustomer(ClinicType*,int,int);
void printCustomer(CustomerArrayType*);
void cleanupCustomers(CustomerArrayType*);
int compareDates(DateType*,DateType*);
int overlapAppts(AppointmentType*,AppointmentType*);
int addAppointment(ScheduleType*,AppointmentType*);
void printSchedule(ScheduleType*);
void cleanupSchedule(ScheduleType*);
void initClinic(ClinicType*,char*);
void cleanupClinic(ClinicType*);



void printMenu(int*);
