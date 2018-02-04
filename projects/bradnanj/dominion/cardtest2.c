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

#define TESTCARD "adventurer"

int main() {
	int newCards = 0;
	int discarded = 1;
	int xtraCoins = 0;
	int shuffledCards = 0;

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

	// ----------- TEST 1: choice1 = 1 = +2 cards --------------
	printf("Testing Adventurer card\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	/*
	The following test was designed to make adventurer keep digging for treasure.     It causes an infinite loop so it is not enabled.

	testG.deck[p][4] = 8;
	testG.deck[p][3] = 7;
	testG.deck[p][2] = 9;
	testG.deck[p][1] = 10;
	testG.deck[p][0] = 8;

	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	*/
	oldDiscardCount = testG.discardCount[p];
	oldHandCount = testG.handCount[p];
	testG.deck[p][4] = 8;
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	//should result in one discarded card, 2 added treasure cards
	if (oldDiscardCount + 1 == testG.discardCount[p] && oldHandCount + 2 == testG.handCount[p]) {
		printf("AdventurerCard():  PASS\n");
	}
	else {
		printf("AdventurerCard():  FAIL\n");
	}
	


	return 0;
}


