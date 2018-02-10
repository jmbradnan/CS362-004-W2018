#CFLAGS = -Wall -fpic -coverage -lm
CFLAGS = 
CC = cl
DBG = /Zi

default: randomtestcard1.exe

randomtestcard1.exe: randomtestcard1.c dominion.c rngs.c
	$(CC) randomtestcard1.c dominion.c rngs.c $(CFLAGS) $(DBG)

clean:
	erase -f *.o randomtestcard1.exe  *.o