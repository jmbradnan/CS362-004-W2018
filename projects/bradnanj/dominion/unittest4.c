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
	int supplyPos, coinsBeforePurchase, buysLeftBeforePurchase, supplyCountBeforePurchase, coinsAfterPurchase, buysLeftAfterPurchase, supplyCountAfterPurchase;
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
	coinsBeforePurchase = state.coins;
	buysLeftBeforePurchase = state.numBuys;
	supplyCountBeforePurchase = state.supplyCount[supplyPos];
	result = buyCard(supplyPos, &state);
	coinsAfterPurchase = state.coins;
	buysLeftAfterPurchase = state.numBuys;
	supplyCountAfterPurchase = state.supplyCount[supplyPos];

	if ( (result == 0) && (buysLeftAfterPurchase == buysLeftBeforePurchase-1) && (supplyCountAfterPurchase == supplyCountBeforePurchase - 1) && (coinsAfterPurchase == coinsBeforePurchase - getCost(supplyPos)) ) {
		printf("buyCard():  PASS when buying estate card with %d coins and %d buys remaining.\n", p);
	}
	else {
		printf("buyCard():  FAIL when buying estate card with %d coins and %d buys remaining.\n", p);
		if (buysLeftAfterPurchase != buysLeftBeforePurchase + 1) { printf("\t Buys remaining after purchase should be %d, and it is %d.\n", buysLeftBeforePurchase + 1, buysLeftAfterPurchase); }
		if (supplyCountAfterPurchase != supplyCountBeforePurchase + 1) { printf("\t Supply count after purchase should be %d, and it is %d.\n", supplyCountBeforePurchase + 1, supplyCountAfterPurchase); }
		if (coinsAfterPurchase != coinsBeforePurchase + getCost(supplyPos)) { printf("\t Coins remaining after purchase should be %d, and it is %d.\n", coinsBeforePurchase + getCost(supplyPos), coinsAfterPurchase); }
	}

	supplyPos = 3; // province
	coinsBeforePurchase = state.coins;
	buysLeftBeforePurchase = state.numBuys;
	supplyCountBeforePurchase = state.supplyCount[supplyPos];
	result = buyCard(supplyPos, &state);
	coinsAfterPurchase = state.coins;
	buysLeftAfterPurchase = state.numBuys;
	supplyCountAfterPurchase = state.supplyCount[supplyPos];

	if ((result == 0) && (buysLeftAfterPurchase == buysLeftBeforePurchase - 1) && (supplyCountAfterPurchase == supplyCountBeforePurchase - 1) && (coinsAfterPurchase == coinsBeforePurchase - getCost(supplyPos))) {
		printf("buyCard():  PASS when buying province card with %d coins and %d buys remaining.\n", p);
	}
	else {
		printf("buyCard():  FAIL when buying province card with %d coins and %d buys remaining.\n", p);
		if (buysLeftAfterPurchase != buysLeftBeforePurchase + 1) { printf("\t Buys remaining after purchase should be %d, and it is %d.\n", buysLeftBeforePurchase + 1, buysLeftAfterPurchase); }
		if (supplyCountAfterPurchase != supplyCountBeforePurchase + 1) { printf("\t Supply count after purchase should be %d, and it is %d.\n", supplyCountBeforePurchase + 1, supplyCountAfterPurchase); }
		if (coinsAfterPurchase != coinsBeforePurchase + getCost(supplyPos)) { printf("\t Coins remaining after purchase should be %d, and it is %d.\n", coinsBeforePurchase + getCost(supplyPos), coinsAfterPurchase); }
	}

	supplyPos = 7; // adventurer
	coinsBeforePurchase = state.coins;
	buysLeftBeforePurchase = state.numBuys;
	supplyCountBeforePurchase = state.supplyCount[supplyPos];
	result = buyCard(supplyPos, &state);
	coinsAfterPurchase = state.coins;
	buysLeftAfterPurchase = state.numBuys;
	supplyCountAfterPurchase = state.supplyCount[supplyPos];

	if (result == -1) {
		printf("buyCard():  PASS when attempting to buy adventurer card with insufficient funds (%d coins and %d buys remaining).\n", p);
	}
	else {
		printf("buyCard():  FAIL when attempting to buy adventurer card with insufficient funds (%d coins and %d buys remaining).\n", p);
		if (buysLeftAfterPurchase != buysLeftBeforePurchase) { printf("\t Buys remaining after failed purchase should be %d, and it is %d.\n", buysLeftBeforePurchase, buysLeftAfterPurchase); }
		if (supplyCountAfterPurchase != supplyCountBeforePurchase) { printf("\t Supply count after failed purchase should be %d, and it is %d.\n", supplyCountBeforePurchase, supplyCountAfterPurchase); }
		if (coinsAfterPurchase != coinsBeforePurchase) { printf("\t Coins remaining after failed purchase should be %d, and it is %d.\n", coinsBeforePurchase, coinsAfterPurchase); }
	}

	// Test buying cards when there are no more of that card left

	// Test buying cards when there are no more buys left


	testsPassed == 0 ? printf("All tests passed!\n") : printf("All tests did not pass!  Please review the test output for more details.\n");
	return 0;
}