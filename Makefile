#This is a makefile for assignment5
assignment5: assignment5.o parse.o matrix.o linked_list.o 
	gcc -o assignment5 assignment5.o parse.o matrix.o linked_list.o
assignment5.o: assignment5.c parse.h linked_list.h
	gcc -c assignment5.c
parse.o: parse.c parse.h
	gcc -c parse.c
matrix.o: matrix.c matrix.h
	gcc -c matrix.c
linked_list.o: linked_list.c linked_list.h matrix.h
	gcc -c linked_list.c
.PHONY: clean
clean:
	rm *.o assignment5