/*
* cardtest4.c
*

*/

/*
* Include the following lines in your makefile:
*
* cardtest4: cardtest4.c dominion.o rngs.o
*      gcc -o cardtest1 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "village"

int main() {
	int newCards = 0;
	int discarded;
	int testsPassed = 0;

	int i, j, m;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int seed = 1000;
	int numPlayers = 2;
	int p = 0;
	int oldNumActions, oldDiscardCount;

	struct gameState G, testG;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	printf("Testing %s card\n", TESTCARD);
	printf("Test 1: play basic village card.\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	oldDiscardCount = testG.discardCount[p];
	oldNumActions = testG.numActions;

	cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);
	
	if (oldNumActions + 2 == testG.numActions && oldDiscardCount + 1 == testG.discardCount[p]) {
		printf("villageCard():  PASS\n");
	}
	else {
		testsPassed = -1;
		printf("villageCard():  FAIL\n");
		if (oldNumActions + 2 != testG.numActions) {
			printf("\t numActions = %d, expected = %d\n", testG.numActions, oldNumActions + 2);
		}
		if (oldDiscardCount + 1 != testG.discardCount[p]) {
			printf("\t discardCount = %d, expected = %d\n", testG.discardCount[p], oldDiscardCount + 1);
		}
	}

	testsPassed == 0 ? printf("All tests passed!\n") : printf("All tests did not pass!  Please review the test output for more details.\n");


	return 0;
}


