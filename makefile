.PHONY: clean all
CC=gcc
FLAGS= -Wall -g
AR=ar

isort.o: isort.c
	$(CC) -c $(FLAGS) isort.c

txtfind.o: txtfind.c
	$(CC) -c $(FLAGS) txtfind.c

isort: isort.o
	gcc -Wall isort.o -o isort 

txtfind: txtfind.o
	gcc -Wall txtfind.o -o txtfind 

all: isort txtfind

clean:
	rm -rf *.o isort txtfind