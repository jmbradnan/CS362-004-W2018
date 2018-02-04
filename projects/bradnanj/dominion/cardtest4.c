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

#define TESTCARD "mine"

int main() {
	int testsPassed = 0;
	int i, j, m;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int initialCopperCount, initialSilverCount, initialGoldCount, finalCopperCount, finalSilverCount, finalGoldCount;
	int oldDiscardCount, oldHandCount;
	int result = -1;
	int seed = 1000;
	int numPlayers = 2;
	int p = 0;
	struct gameState G, testG;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("Testing %s card\n", TESTCARD);
	printf("Test 1: Trash copper and gain silver.\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 4;
	choice2 = 5;
	initialCopperCount = numOfCoins(4, &testG);
	initialSilverCount = numOfCoins(4, &testG);
	oldDiscardCount = testG.discardCount[p];
	oldHandCount = testG.handCount[p];
	result = cardEffect(mine, choice1, choice2, choice3, &testG, handpos, &bonus);
	finalCopperCount = numOfCoins(4, &testG);
	finalSilverCount = numOfCoins(5, &testG);

	if ( (result == 0) && (testG.discardCount[p] == oldDiscardCount - 1) && 
		(testG.handCount[p] == oldHandCount -1) && (initialCopperCount == finalCopperCount + 1) && 
		(initialSilverCount == finalSilverCount + 1) ) {
		printf("mineCard():  PASS testing trash copper and gain silver.\n");
	}
	else {
		testsPassed = -1;
		printf("mineCard():  FAIL testing trash copper and gain silver.\n");
		if (testG.discardCount[p] == oldDiscardCount - 1) {
			printf("\t discardCount = %d, expected = %d\n", testG.discardCount[p], oldDiscardCount - 1);
		}
	}


	testsPassed == 0 ? printf("All tests passed!\n") : printf("All tests did not pass!  Please review the test output for more details.\n");

	return 0;
}

int numOfCoins(int coin, struct gameState *state) {
	int count = 0;

	return count;
}


