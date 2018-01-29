#CFLAGS = -Wall -fpic -coverage -lm -std=c99
CFLAGS = 
CC = cl
DBG = /Zi

default: unittest1.exe 

unittest: unittestresults.out 

all: unittest1.exe unittestresults.out

unittest1.exe: unittest1.c dominion.c rngs.c
	$(CC) -o unittest1 dominion.c rngs.c unittest1.c $(CFLAGS) $(DBG)

unittestresults.out: unittest1.exe
	echo "Result for Dominion unit tests and card tests:" > unittestresults.out
	
	echo "unittest1.c:" >> unittestresults.out
	
	unittest1 >> unittestresults.out
	
clean:
	erase unittestresults.out

cleanall: 
	erase unittestresults.out unittest1.exe *.gcda *.gcno *.gcov
