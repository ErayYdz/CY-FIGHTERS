all: CY-FIGHTERS

CY-FIGHTERS.o: cy_fighters.c
	gcc -c cy_fighters.c cy_fighters.o

CY-FIGHTERS: cy_fighters.o
	gcc cy_fighters.o -o CY-FIGHTERS
