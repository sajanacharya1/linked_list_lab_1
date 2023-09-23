# list/Makefile
#
# Makefile for list implementation and test file.
#
# <Sajan Acharya>
list: list.c main.c
	gcc list.c main.c -o list
