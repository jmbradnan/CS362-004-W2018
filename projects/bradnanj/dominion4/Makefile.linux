CFLAGS = -Wall -fpic -coverage -ftest-coverage -fprofile-arcs -lm -std=c99


default: randomtestcard1 randomtestcard2 randomtestcard3
	
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

clean:
	rm -f *.o randomtestcard1 randomtestcard2 randomtestcard3 *.o