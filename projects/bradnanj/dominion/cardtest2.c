/* -----------------------------------------------------------------------
* Unit tests for dominion-base game --> dominion.c
*
* This set of tests validates the Adventurer card.
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

int cardtest2() {
	int testsPassed = 0;
	int numberOfDiscards;
	int i, j, m;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int remove1, remove2;
	int seed = 1000;
	int numPlayers = 2;
	int p = 0;
	int oldDiscardCount, oldHandCount;
	struct gameState G, testG;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	printf("Test 1: pick up two treasure cards (coppers), discard one card.\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	numberOfDiscards = 1;
	oldDiscardCount = testG.discardCount[p];
	oldHandCount = testG.handCount[p];
	testG.deck[p][4] = 8;
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	//should result in one discarded card, 2 added treasure cards
	if (oldDiscardCount + numberOfDiscards == testG.discardCount[p] && oldHandCount + 2 == testG.handCount[p]) {
		printf("AdventurerCard():  PASS pick up two treasure cards (coppers), discard one card\n");
	}
	else {
		testsPassed = -1;
		printf("AdventurerCard():  FAIL pick up two treasure cards (coppers), discard one card\n");
		if (oldDiscardCount + numberOfDiscards != testG.discardCount[p]) {
			printf("\t discard count = %d, expected to be = %d\n", testG.discardCount[p], oldDiscardCount + numberOfDiscards);
		}
		if (oldHandCount + 2 != testG.handCount[p]) {
			printf("\t hand count = %d, expected to be = %d\n", testG.handCount[p], oldHandCount + 2);
		}
	}
	
	printf("Test 2: pick up two treasure cards (copper and silver), discard two cards.\n");
	numberOfDiscards = 2;
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	oldDiscardCount = testG.discardCount[p];
	oldHandCount = testG.handCount[p];
	testG.deck[p][4] = 8;
	testG.deck[p][3] = 7;
	testG.deck[p][1] = 5;
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	//should result in one discarded card, 2 added treasure cards
	if (oldDiscardCount + numberOfDiscards == testG.discardCount[p] && oldHandCount + 2 == testG.handCount[p]) {
		printf("AdventurerCard():  PASS pick up two treasure cards (copper and silver), discard two cards\n");
	}
	else {
		testsPassed = -1;
		printf("AdventurerCard():  FAIL pick up two treasure cards (copper and silver), discard two cards\n");
		if (oldDiscardCount + numberOfDiscards != testG.discardCount[p]) {
			printf("\t discard count = %d, expected to be = %d\n", testG.discardCount[p], oldDiscardCount + numberOfDiscards);
		}
		if (oldHandCount + 2 != testG.handCount[p]) {
			printf("\t hand count = %d, expected to be = %d\n", testG.handCount[p], oldHandCount + 2);
		}
	}

	printf("Test 3: pick up two treasure cards (silver and gold), discard zero cards.\n");
	numberOfDiscards = 0;
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	oldDiscardCount = testG.discardCount[p];
	oldHandCount = testG.handCount[p];
	testG.deck[p][4] = 5;
	testG.deck[p][3] = 6;
	
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	//should result in one discarded card, 2 added treasure cards
	if (oldDiscardCount + numberOfDiscards == testG.discardCount[p] && oldHandCount + 2 == testG.handCount[p]) {
		printf("AdventurerCard():  PASS pick up two treasure cards (silver and gold), discard zero cards\n");
	}
	else {
		testsPassed = -1;
		printf("AdventurerCard():  FAIL pick up two treasure cards (silver and gold), discard zero cards\n");
		if (oldDiscardCount + numberOfDiscards != testG.discardCount[p]) {
			printf("\t discard count = %d, expected to be = %d\n", testG.discardCount[p], oldDiscardCount + numberOfDiscards);
		}
		if (oldHandCount + 2 != testG.handCount[p]) {
			printf("\t hand count = %d, expected to be = %d\n", testG.handCount[p], oldHandCount + 2);
		}
	}
	printf("Test 4: keep digging for treasure -- DISABLED due to infinite loop.\n");
	/*
	The following test was designed to make adventurer keep digging for treasure.     It causes an infinite loop so it is not enabled.

	testG.deck[p][4] = 8;
	testG.deck[p][3] = 7;
	testG.deck[p][2] = 9;
	testG.deck[p][1] = 10;
	testG.deck[p][0] = 8;

	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	*/

	testsPassed == 0 ? printf("All tests passed!\n") : printf("All tests did not pass!  Please review the test output for more details.\n");

	return 0;
}


