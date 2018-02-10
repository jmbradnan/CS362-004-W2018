#CFLAGS = -Wall -fpic -coverage -lm
CFLAGS = 
CC = cl
DBG = /Zi

default: randomtestcard1.exe

randomtestcard1.exe: randomtestcard1.c dominion.c rngs.c
	$(CC) randomtestcard1.c dominion.c rngs.c $(CFLAGS) $(DBG)
	
unittestrunner: unittestrunner.c cardtest2.c dominion.c rngs.c
	$(CC) unittestrunner unittestrunner.c cardtest2.c $(CFLAGS) $(DBG)
	
cardtest2.exe: cardtest2.c dominion.c rngs.c
	$(CC) cardtest2 dominion.c rngs.c cardtest2.c $(CFLAGS) $(DBG)

clean:
	erase -f *.o randomtestcard1.exe  *.o