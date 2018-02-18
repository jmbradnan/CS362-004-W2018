#CFLAGS = -Wall -fpic -coverage -lm
CFLAGS = 
CC = cl
DBG = /Zi

default: randomtestcard3
	
randomtestcard3: randomtestcard3.c randomCardHelper.c dominion.c rngs.c
	$(CC) randomtestcard3.c randomCardHelper.c dominion.c rngs.c $(CFLAGS) $(DBG)

clean:
	erase -f *.o randomtestcard3.exe  *.o