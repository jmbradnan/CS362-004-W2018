#CFLAGS = -Wall -fpic -coverage -lm
CFLAGS = 
CC = cl
DBG = /Zi

default: unittestrunner

#randomtestcard1.exe: randomtestcard1.c dominion.c rngs.c
	#$(CC) randomtestcard1.c dominion.c rngs.c $(CFLAGS) $(DBG)
	
unittestrunner: unittestrunner.c randomtestcard1.c randomtestcard2.c randomtestcard3.c randomCardHelper.c dominion.c rngs.c
	$(CC) unittestrunner unittestrunner.c randomtestcard1.c randomtestcard2.c randomtestcard3.c randomCardHelper.c dominion.c rngs.c $(CFLAGS) $(DBG)

clean:
	erase -f *.o unittestrunner.exe  *.o