#CFLAGS = -Wall -fpic -coverage -lm -std=c99
CFLAGS = 
CC = cl
DBG = /Zi

default: unittest3.exe

unittest: unittestresults.out 

all: unittest1.exe unittest2.exe unittest3.exe unittestresults.out

unittest1.exe: unittest1.c dominion.c rngs.c
	$(CC) -o unittest1 dominion.c rngs.c unittest1.c $(CFLAGS) $(DBG)
	
unittest2.exe: unittest2.c dominion.c rngs.c
	$(CC) -o unittest2 dominion.c rngs.c unittest2.c $(CFLAGS) $(DBG)
	
unittest3.exe: unittest3.c dominion.c rngs.c
	$(CC) -o unittest3 dominion.c rngs.c unittest3.c $(CFLAGS) $(DBG)

unittestresults.out: unittest1.exe unittest2.exe unittest3.exe
	echo "Result for Dominion unit tests and card tests:" > unittestresults.out
	
	echo "unittest1.c:" >> unittestresults.out
	unittest1 >> unittestresults.out
	
	echo. >> unittestresults.out
	
	echo "unittest2.c:" >> unittestresults.out
	unittest2 >> unittestresults.out
	
	echo. >> unittestresults.out
	
	echo "unittest3.c:" >> unittestresults.out
	unittest3 >> unittestresults.out
	
	echo. >> unittestresults.out
	
clean:
	erase unittestresults.out

cleanall: 
	erase unittestresults.out unittest1.exe unittest2.exe unittest3.exe *.gcda *.gcno *.gcov
