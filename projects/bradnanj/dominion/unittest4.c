/* -----------------------------------------------------------------------
* Unit tests for dominion-base game --> dominion.c
*
* This set of tests validates the buyCard method.
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

int unittest4() {
	int i, j;
	int seed = 1000;
	int numPlayer = 2;
	int p, r;
	int testsPassed = 0;
	int supplyPos, coinsBeforePurchase, buysLeftBeforePurchase, supplyCountBeforePurchase, coinsAfterPurchase, buysLeftAfterPurchase, supplyCountAfterPurchase;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState state;
	int result = -1;
	printf("----------------- Results for running buyCard() tests: ----------------\n");

	memset(&state, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &state); // initialize a new game
	printf("Test 1: buy estate card with sufficient funds.\n");
	// Test buying cards when funds are sufficient and also insufficient
	supplyPos = 1; // estate
	state.supplyCount[supplyPos] = 10;
	state.numBuys = 3;
	state.coins = 10;
	coinsBeforePurchase = state.coins;
	buysLeftBeforePurchase = state.numBuys;
	supplyCountBeforePurchase = state.supplyCount[supplyPos];
	result = buyCard(supplyPos, &state);
	coinsAfterPurchase = state.coins;
	buysLeftAfterPurchase = state.numBuys;
	supplyCountAfterPurchase = state.supplyCount[supplyPos];

	if ( (result == 0) && (buysLeftAfterPurchase == buysLeftBeforePurchase-1) && (supplyCountAfterPurchase == supplyCountBeforePurchase - 1) && (coinsAfterPurchase == coinsBeforePurchase - getCost(supplyPos)) ) {
		printf("buyCard():  PASS when buying estate card with %d coins and %d buys remaining.\n", coinsBeforePurchase, buysLeftBeforePurchase);
	}
	else {
		testsPassed = -1;
		printf("buyCard():  FAIL when buying estate card with %d coins and %d buys remaining.\n", coinsBeforePurchase, buysLeftBeforePurchase);
		if (buysLeftAfterPurchase != buysLeftBeforePurchase + 1) { printf("\t Buys remaining after purchase should be %d, and it is %d.\n", buysLeftBeforePurchase + 1, buysLeftAfterPurchase); }
		if (supplyCountAfterPurchase != supplyCountBeforePurchase + 1) { printf("\t Supply count after purchase should be %d, and it is %d.\n", supplyCountBeforePurchase + 1, supplyCountAfterPurchase); }
		if (coinsAfterPurchase != coinsBeforePurchase + getCost(supplyPos)) { printf("\t Coins remaining after purchase should be %d, and it is %d.\n", coinsBeforePurchase + getCost(supplyPos), coinsAfterPurchase); }
	}
	printf("Test 2: buy province card with sufficient funds.\n");
	supplyPos = 3; // province
	coinsBeforePurchase = state.coins;
	buysLeftBeforePurchase = state.numBuys;
	supplyCountBeforePurchase = state.supplyCount[supplyPos];
	result = buyCard(supplyPos, &state);
	coinsAfterPurchase = state.coins;
	buysLeftAfterPurchase = state.numBuys;
	supplyCountAfterPurchase = state.supplyCount[supplyPos];

	if ((result == 0) && (buysLeftAfterPurchase == buysLeftBeforePurchase - 1) && (supplyCountAfterPurchase == supplyCountBeforePurchase - 1) && (coinsAfterPurchase == coinsBeforePurchase - getCost(supplyPos))) {
		printf("buyCard():  PASS when buying province card with %d coins and %d buys remaining.\n", coinsBeforePurchase, buysLeftBeforePurchase);
	}
	else {
		testsPassed = -1;
		printf("buyCard():  FAIL when buying province card with %d coins and %d buys remaining.\n", coinsBeforePurchase, buysLeftBeforePurchase);
		if (buysLeftAfterPurchase != buysLeftBeforePurchase + 1) { printf("\t Buys remaining after purchase should be %d, and it is %d.\n", buysLeftBeforePurchase + 1, buysLeftAfterPurchase); }
		if (supplyCountAfterPurchase != supplyCountBeforePurchase + 1) { printf("\t Supply count after purchase should be %d, and it is %d.\n", supplyCountBeforePurchase + 1, supplyCountAfterPurchase); }
		if (coinsAfterPurchase != coinsBeforePurchase + getCost(supplyPos)) { printf("\t Coins remaining after purchase should be %d, and it is %d.\n", coinsBeforePurchase + getCost(supplyPos), coinsAfterPurchase); }
	}
	printf("Test 3: attempt to buy adventurer cards with insufficient funds.\n");
	supplyPos = 7; // adventurer
	coinsBeforePurchase = state.coins;
	buysLeftBeforePurchase = state.numBuys;
	supplyCountBeforePurchase = state.supplyCount[supplyPos];
	result = buyCard(supplyPos, &state);
	coinsAfterPurchase = state.coins;
	buysLeftAfterPurchase = state.numBuys;
	supplyCountAfterPurchase = state.supplyCount[supplyPos];
	// You should not be able to buy this card, you have no coins remaining
	if (result == -1) {
		printf("buyCard():  PASS when attempting to buy adventurer card with insufficient funds (%d coins available).\n", coinsBeforePurchase);
	}
	else {
		testsPassed = -1;
		printf("buyCard():  FAIL when attempting to buy adventurer card with insufficient funds (%d coins available).\n", coinsBeforePurchase);
		if (buysLeftAfterPurchase != buysLeftBeforePurchase) { printf("\t Buys remaining after failed purchase should be %d, and it is %d.\n", buysLeftBeforePurchase, buysLeftAfterPurchase); }
		if (supplyCountAfterPurchase != supplyCountBeforePurchase) { printf("\t Supply count after failed purchase should be %d, and it is %d.\n", supplyCountBeforePurchase, supplyCountAfterPurchase); }
		if (coinsAfterPurchase != coinsBeforePurchase) { printf("\t Coins remaining after failed purchase should be %d, and it is %d.\n", coinsBeforePurchase, coinsAfterPurchase); }
	}

	// Reset Game State
	memset(&state, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &state); // initialize a new game
	printf("Test 4: Test buying cards when there are no more buys left.\n");
	// Test buying cards when there are no more buys left
	supplyPos = 1; // estate
	state.supplyCount[supplyPos] = 10;
	state.numBuys = 0;
	state.coins = 10;
	coinsBeforePurchase = state.coins;
	buysLeftBeforePurchase = state.numBuys;
	supplyCountBeforePurchase = state.supplyCount[supplyPos];
	result = buyCard(supplyPos, &state);
	coinsAfterPurchase = state.coins;
	buysLeftAfterPurchase = state.numBuys;
	supplyCountAfterPurchase = state.supplyCount[supplyPos];

	// You should not be able to buy this card, you have no buys remaining
	if (result == -1) {
		printf("buyCard():  PASS when attempting to buy estate card with no buys remaining (%d buys remaining).\n", buysLeftBeforePurchase);
	}
	else {
		testsPassed = -1;
		printf("buyCard():  FAIL when attempting to buy estate card with no buys remaining (%d buys remaining).\n", buysLeftBeforePurchase);
	}
	printf("Test 5: Test buying card when there are no more of that card available.\n");
	// Test buying card when there are no more of that card available
	supplyPos = 1; // estate
	state.supplyCount[supplyPos] = 0;
	result = buyCard(supplyPos, &state);

	// You should not be able to buy this card, you have no more of this card remaining
	if (result == -1) {
		printf("buyCard():  PASS when attempting to buy estate card with no cards of that type remaining.\n");
	}
	else {
		testsPassed = -1;
		printf("buyCard():  FAIL when attempting to buy estate card with no cards of that type remaining.\n");
	}

	testsPassed == 0 ? printf("All tests passed!\n") : printf("All tests did not pass!  Please review the test output for more details.\n");
	return 0;
}