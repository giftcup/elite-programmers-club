latin: latin.o line.o word.o
	gcc -o latin latin.o line.o word.o
latin.o: latin.c line.h word.h
	gcc -c latin.c
word.o: word.c word.h
	gcc -c word.c
line.o: line.c line.h
	gcc -c line.c