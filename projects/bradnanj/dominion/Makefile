#CFLAGS = -Wall -fpic -coverage -lm -std=c99
CFLAGS = 
CC = cl
DBG = /Zi

default: unittest2.exe

unittest: unittestresults.out 

all: unittest1.exe unittest2.exe unittestresults.out

unittest1.exe: unittest1.c dominion.c rngs.c
	$(CC) -o unittest1 dominion.c rngs.c unittest1.c $(CFLAGS) $(DBG)
	
unittest2.exe: unittest2.c dominion.c rngs.c
	$(CC) -o unittest2 dominion.c rngs.c unittest2.c $(CFLAGS) $(DBG)

unittestresults.out: unittest1.exe unittest2.exe
	echo "Result for Dominion unit tests and card tests:" > unittestresults.out
	
	echo "unittest1.c:" >> unittestresults.out
	unittest1 >> unittestresults.out
	
	echo "unittest2.c:" >> unittestresults.out
	unittest2 >> unittestresults.out
	
clean:
	erase unittestresults.out

cleanall: 
	erase unittestresults.out unittest1.exe unittest2.exe *.gcda *.gcno *.gcov
