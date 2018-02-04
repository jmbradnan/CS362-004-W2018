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

#define TESTCARD "smithy"

int main() {
	int newCards = 0;
	int discarded;
	int testsPassed = 0;

	int i, j, m;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: choice1 = 1 = +2 cards --------------
	printf("Test play Smithy card\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

	newCards = 3;
	discarded = 1;

	if (testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded) {
		printf("SmithyCard():  PASS\n");
	}
	else {
		testsPassed = -1;
		printf("SmithyCard():  FAIL\n");
		if (testG.handCount[thisPlayer] != G.handCount[thisPlayer] + newCards - discarded) { 
			printf("\t hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
		}
	}
	
	testsPassed == 0 ? printf("All tests passed!\n") : printf("All tests did not pass!  Please review the test output for more details.\n");


	return 0;
}


