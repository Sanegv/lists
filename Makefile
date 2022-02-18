run: compile
	./main

compile: main.o listes.o
	gcc -Wall -o main main.o listes.o -g

main.o: main.c listes.c listes.h
	gcc -Wall -c main.c listes.c listes.h -g

listes.o: listes.c listes.h
	gcc -Wall -c listes.h listes.c -g

valgrind: compile
	valgrind ./main

clean: 
	rm *.o
	rm *.gch
	rm main

code:
	code Makefile
	code listes.h
	code listes.c
	code main.c