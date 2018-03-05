CFLAGS = -Wall -fpic -coverage -ftest-coverage -fprofile-arcs -lm -std=c99

default: unittestrunner randomtestcard1 randomtestcard2 randomtestcard3

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
	
randomtestcard1: randomtestcard1.c randomCardHelper.c dominion.c rngs.c
	gcc -o randomtestcard1 randomtestcard1.c randomCardHelper.c dominion.c rngs.c $(CFLAGS)
	echo "Result for randomtestcard1 tests:" > randomtestcard1.out
	randomtestcard1 >> randomtestcard1.out
	gcov -b -f dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out
	
randomtestcard2: randomtestcard2.c randomCardHelper.c dominion.c rngs.c
	gcc -o randomtestcard2 randomtestcard2.c randomCardHelper.c dominion.c rngs.c $(CFLAGS)
	echo "Result for randomtestcard2 tests:" > randomtestcard2.out
	randomtestcard2 >> randomtestcard2.out
	gcov -b -f dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out
	
randomtestcard3: randomtestcard3.c randomCardHelper.c dominion.c rngs.c
	gcc -o randomtestcard3 randomtestcard3.c randomCardHelper.c dominion.c rngs.c $(CFLAGS)
	echo "Result for randomtestcard3 tests:" > randomtestcard3.out
	randomtestcard3 >> randomtestcard3.out
	gcov -b -f dominion.c >> randomtestcard3.out
	cat dominion.c.gcov >> randomtestcard3.out

unittestresults.out: unittestrunner unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
#echo "Result for Dominion unit tests and card tests:" > unittestresults.out
	
clean:
	rm unittestresults.out

cleanall: 
	rm unittestresults.out unittestrunner unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestcard1 randomtestcard2 randomtestcard3 *.gcda *.gcno *.gcov
