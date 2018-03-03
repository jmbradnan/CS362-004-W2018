/* -----------------------------------------------------------------------
* Unit tests for dominion-base game --> dominion.c
*
* This set of tests validates the Mine card.
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "mine"

int numOfCoins(int coin, struct gameState *state, int p);

int cardtest4() {
	int testsPassed = 0;
	int i, j, m;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int initialCopperCount, initialSilverCount, initialGoldCount, finalCopperCount, finalSilverCount, finalGoldCount;
	int oldPlayedCount, oldHandCount;
	int result = -1;
	int seed = 1000;
	int numPlayers = 2;
	int p = 0;
	struct gameState G, testG;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	printf("Test 1: Trash copper and gain silver.  Discard a copper.\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	testG.hand[p][0] = 4;  //ensure handPos contains a copper
	testG.hand[p][4] = 4;  //ensure choice1 contains a copper
	choice1 = 4;
	choice2 = 5;
	initialCopperCount = numOfCoins(4, &testG, p);
	initialSilverCount = numOfCoins(5, &testG, p);
	oldPlayedCount = testG.playedCardCount;
	oldHandCount = testG.handCount[p];
	result = cardEffect(mine, choice1, choice2, choice3, &testG, handpos, &bonus);
	finalCopperCount = numOfCoins(4, &testG, p);
	finalSilverCount = numOfCoins(5, &testG, p);

	if ( (result == 0) && (testG.playedCardCount == oldPlayedCount + 1) &&
		(testG.handCount[p] == oldHandCount - 1) && (initialCopperCount == finalCopperCount + 2) && 
		(initialSilverCount + 1 == finalSilverCount) ) {
		printf("mineCard():  PASS testing trash copper and gain silver.\n");
	}
	else {
		testsPassed = -1;
		printf("mineCard():  FAIL testing trash copper and gain silver.\n");
		if (testG.playedCardCount != oldPlayedCount + 1) {
			printf("\t playedCardCount = %d, expected = %d\n", testG.playedCardCount, oldPlayedCount + 1);
		}
		if (testG.handCount[p] != oldHandCount - 1) {
			printf("\t handCount = %d, expected = %d\n", testG.handCount[p], oldHandCount - 1);
		}
		if (initialCopperCount != finalCopperCount + 2) {
			printf("\t copperCount = %d, expected = %d\n", finalCopperCount, initialCopperCount - 2);
		}
		if (initialSilverCount + 1 != finalSilverCount) {
			printf("\t silverCount = %d, expected = %d\n", finalSilverCount, initialSilverCount + 1);
		}
	}

	printf("Test 2: Trash copper and gain silver.  Discard something other than copper.\n");
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	testG.hand[p][0] = 11;  //ensure handPos contains mine card
	testG.hand[p][4] = 4;  //ensure choice1 contains a copper
	choice1 = 4;
	choice2 = 5;
	initialCopperCount = numOfCoins(4, &testG, p);
	initialSilverCount = numOfCoins(5, &testG, p);
	oldPlayedCount = testG.playedCardCount;
	oldHandCount = testG.handCount[p];
	result = cardEffect(mine, choice1, choice2, choice3, &testG, handpos, &bonus);
	finalCopperCount = numOfCoins(4, &testG, p);
	finalSilverCount = numOfCoins(5, &testG, p);

	if ((result == 0) && (testG.playedCardCount == oldPlayedCount + 1) &&
		(testG.handCount[p] == oldHandCount - 1) && (initialCopperCount == finalCopperCount + 1) &&
		(initialSilverCount + 1 == finalSilverCount)) {
		printf("mineCard():  PASS testing trash copper and gain silver.\n");
	}
	else {
		testsPassed = -1;
		printf("mineCard():  FAIL testing trash copper and gain silver.\n");
		if (testG.playedCardCount != oldPlayedCount + 1) {
			printf("\t playedCardCount = %d, expected = %d\n", testG.playedCardCount, oldPlayedCount + 1);
		}
		if (testG.handCount[p] != oldHandCount - 1) {
			printf("\t handCount = %d, expected = %d\n", testG.handCount[p], oldHandCount - 1);
		}
		if (initialCopperCount != finalCopperCount + 1) {
			printf("\t copperCount = %d, expected = %d\n", finalCopperCount, initialCopperCount - 1);
		}
		if (initialSilverCount + 1 != finalSilverCount) {
			printf("\t silverCount = %d, expected = %d\n", finalSilverCount, initialSilverCount + 1);
		}
	}

	printf("Test 3: Trash silver and gain gold.  Discard copper.\n");
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	testG.hand[p][0] = 4;  //ensure handPos contains mine card
	testG.hand[p][5] = 5;  //ensure choice1 contains a silver
	choice1 = 5;
	choice2 = 6;
	initialCopperCount = numOfCoins(4, &testG, p);
	initialSilverCount = numOfCoins(5, &testG, p);
	initialGoldCount = numOfCoins(6, &testG, p);
	oldPlayedCount = testG.playedCardCount;
	oldHandCount = testG.handCount[p];
	result = cardEffect(mine, choice1, choice2, choice3, &testG, handpos, &bonus);
	finalCopperCount = numOfCoins(4, &testG, p);
	finalSilverCount = numOfCoins(5, &testG, p);
	finalGoldCount = numOfCoins(6, &testG, p);

	if ((result == 0) && (testG.playedCardCount == oldPlayedCount + 1) &&
		(testG.handCount[p] == oldHandCount - 1) && (initialCopperCount == finalCopperCount + 1) &&
		(initialSilverCount - 1 == finalSilverCount) && (finalGoldCount == initialGoldCount + 1) ) {
		printf("mineCard():  PASS testing trash silver and gain gold.  Discard copper.\n");
	}
	else {
		testsPassed = -1;
		printf("mineCard():  FAIL testing trash silver and gain gold.  Discard copper.\n");
		if (testG.playedCardCount != oldPlayedCount + 1) {
			printf("\t playedCardCount = %d, expected = %d\n", testG.playedCardCount, oldPlayedCount + 1);
		}
		if (testG.handCount[p] != oldHandCount - 1) {
			printf("\t handCount = %d, expected = %d\n", testG.handCount[p], oldHandCount - 1);
		}
		if (initialCopperCount != finalCopperCount + 1) {
			printf("\t copperCount = %d, expected = %d\n", finalCopperCount, initialCopperCount - 1);
		}
		if (initialSilverCount - 1 != finalSilverCount) {
			printf("\t silverCount = %d, expected = %d\n", finalSilverCount, initialSilverCount - 1);
		}
		if (finalGoldCount != initialGoldCount + 1) {
			printf("\t goldCount = %d, expected = %d\n", finalGoldCount, initialGoldCount + 1);
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


