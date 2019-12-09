# list/Makefile
#
# Makefile for list implementation and test file.
#
# Serge Selenou

list: main.c
	gcc -o main main.c list.c
