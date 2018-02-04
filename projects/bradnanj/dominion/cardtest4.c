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
	printf("Test 1: Trash copper and gain silver.  Discard a copper.\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	testG.hand[p][0] = 4;  //ensure handPos contains a copper
	choice1 = 4;
	choice2 = 5;
	initialCopperCount = numOfCoins(4, &testG, p);
	initialSilverCount = numOfCoins(5, &testG, p);
	oldPlayedCount = testG.playedCardCount[p];
	oldHandCount = testG.handCount[p];
	result = cardEffect(mine, choice1, choice2, choice3, &testG, handpos, &bonus);
	finalCopperCount = numOfCoins(4, &testG, p);
	finalSilverCount = numOfCoins(5, &testG, p);

	if ( (result == 0) && (testG.playedCardCount[p] == oldPlayedCount - 2) &&
		(testG.handCount[p] == oldHandCount -1) && (initialCopperCount == finalCopperCount + 2) && 
		(initialSilverCount == finalSilverCount + 1) ) {
		printf("mineCard():  PASS testing trash copper and gain silver.\n");
	}
	else {
		testsPassed = -1;
		printf("mineCard():  FAIL testing trash copper and gain silver.\n");
		if (testG.playedCardCount[p] != oldPlayedCount - 2) {
			printf("\t discardCount = %d, expected = %d\n", testG.discardCount[p], oldDiscardCount - 1);
		}
	}


	testsPassed == 0 ? printf("All tests passed!\n") : printf("All tests did not pass!  Please review the test output for more details.\n");

	return 0;
}

int numOfCoins(int coin, struct gameState *state, int p) {
	int count = 0;
	int i;

	for (i = 0; i < MAX_HAND; i++) {
		if (state->hand[p][i] == coin) {
			count++;
		}
		if (state->hand[p][i] == -1) {
			break;
		}
	}

	return count;
}


