	
	
OBJ = main.o clinic.o animals.c sched.c init.c customers.c

a3:	$(OBJ)
	gcc $(OPT) -o a3 $(OBJ)

main.o:	main.c defs.h
	gcc $(OPT) -c main.c

clinic.o:clinic.c defs.h
	gcc $(OPT) -c clinic.c

sched.o:sched.c defs.h
	gcc $(OPT) -c sched.c

init.o:	init.c defs.h
	gcc $(OPT) -c init.c

animals.o:animals.c defs.h
	gcc $(OPT) -c animals.c

customers.o:customers.c defs.h
	gcc $(OPT) -c customers.c


clean:
	rm -f $(OBJ) a3

