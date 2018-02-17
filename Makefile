CFLAGS = -Wall -fpic -coverage -ftest-coverage -fprofile-arcs -lm -std=c99

default: unittestrunner

unittestrunner: unittestrunner.c unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.c rngs.c
	gcc -o unittestrunner unittestrunner.c unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.c rngs.c $(CFLAGS)
	echo "Result for Dominion unit tests and card tests:" > unittestresults.out
	unittestrunner >> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

unittest: unittestresults.out 

#all: unittestrunner.exe unittest1.exe unittest2.exe unittest3.exe unittest4.exe cardtest1.exe cardtest2.exe cardtest3.exe cardtest4.exe unittestresults.out

unittest1.exe: unittest1.c dominion.c rngs.c
	gcc -o unittest1 dominion.c rngs.c unittest1.c $(CFLAGS)
	
unittest2.exe: unittest2.c dominion.c rngs.c
	gcc -o unittest2 dominion.c rngs.c unittest2.c $(CFLAGS)
	
unittest3.exe: unittest3.c dominion.c rngs.c
	gcc -o unittest3 dominion.c rngs.c unittest3.c $(CFLAGS)
	
unittest4.exe: unittest4.c dominion.c rngs.c
	gcc -o unittest4 dominion.c rngs.c unittest4.c $(CFLAGS)
	
cardtest1.exe: cardtest1.c dominion.c rngs.c
	gcc -o cardtest1 dominion.c rngs.c cardtest1.c $(CFLAGS)
	
cardtest2.exe: cardtest2.c dominion.c rngs.c
	gcc -o cardtest2 dominion.c rngs.c cardtest2.c $(CFLAGS)
	
cardtest3.exe: cardtest3.c dominion.c rngs.c
	gcc -o cardtest3 dominion.c rngs.c cardtest3.c $(CFLAGS)
	
cardtest4.exe: cardtest4.c dominion.c rngs.c
	gcc -o cardtest4 dominion.c rngs.c cardtest4.c $(CFLAGS)

unittestresults.out: unittestrunner.exe unittest1.exe unittest2.exe unittest3.exe unittest4.exe cardtest1.exe cardtest2.exe cardtest3.exe cardtest4.exe
#echo "Result for Dominion unit tests and card tests:" > unittestresults.out
	
clean:
	rm unittestresults.out

cleanall: 
	rm unittestresults.out unittestrunner.exe unittest1.exe unittest2.exe unittest3.exe unittest4.exe cardtest1.exe cardtest2.exe cardtest3.exe cardtest4.exe *.gcda *.gcno *.gcov
