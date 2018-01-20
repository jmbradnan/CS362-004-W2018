#CFLAGS = -Wall -fpic -coverage -lm
CFLAGS = 
CC = cl
DBG = /Zi

rngs.o: rngs.h rngs.c
	$(CC) -c rngs.c $(DBG) $(CFLAGS) /Fo: $@

dominion.o: dominion.h dominion.c rngs.o
	$(CC) -c dominion.c $(DBG) $(CFLAGS) /Fo: $@

playdom.exe: dominion.o playdom.c
	$(CC) playdom.c $(DBG) dominion.o rngs.o $(CFLAGS)

#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	$(CC) $(DBG)  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	$(CC) $(DBG)  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	$(CC) $(DBG)  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	$(CC) testSuite.c $(DBG)  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	$(CC) -c interface.c $(DBG)  $(CFLAGS) /Fo: $@

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	$(CC) player.c $(DBG)  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom.exe player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe