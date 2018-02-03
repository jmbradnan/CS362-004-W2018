/* -----------------------------------------------------------------------
* Unit tests for dominion-base game --> dominion.c
* Include the following lines in your makefile:
*
* This set of tests validates the gainCard method.
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main() {
	int i, j;
	int seed = 1000;
	int numPlayer = 2;
	int p, r;
	int testsPassed = 0;
	int supplyPos;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState state;
	int result = -1;

	printf("Results for running buyCard() tests:\n");

	memset(&state, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &state); // initialize a new game

	// Test buying cards when funds are sufficient and also insufficient
	supplyPos = 1; // estate
	state.supplyCount[supplyPos] = 10;
	state.numBuys = 3;
	state.coins = 10;
	result = buyCard(supplyPos, &state);

	if (result == 0) {
		printf("buyCard():  PASS when buying estate card with %d coins and %d buys remaining.\n", p);
	}
	else {
		printf("buyCard():  FAIL when buying estate card with %d coins and %d buys remaining.\n", p);
	}

	supplyPos = 3; // province
	result = buyCard(supplyPos, &state);

	if (result == 0) {
		printf("buyCard():  PASS when buying province card with %d coins and %d buys remaining.\n", p);
	}
	else {
		printf("buyCard():  FAIL when buying province card with %d coins and %d buys remaining.\n", p);
	}

	supplyPos = 7; // adventurer
	result = buyCard(supplyPos, &state);

	if (result == 0) {
		printf("buyCard():  PASS when attempting to buy adventurer card with insufficient funds (%d coins and %d buys remaining).\n", p);
	}
	else {
		printf("buyCard():  FAIL when attempting to buy adventurer card with insufficient funds (%d coins and %d buys remaining).\n", p);
	}

	// Test buying cards when there are no more of that card left

	// Test buying cards when there are no more buys left


	testsPassed == 0 ? printf("All tests passed!\n") : printf("All tests did not pass!  Please review the test output for more details.\n");
	return 0;
}