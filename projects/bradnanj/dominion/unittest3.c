/* -----------------------------------------------------------------------
* Unit tests for dominion-base game --> dominion.c
*
* This set of tests validates the isGameOver method.
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

int unittest3() {
	int i, j;
	int seed = 1000;
	int numPlayer = 2;
	int p, r;
	int testsPassed = 0;
	int oldProvinceCardCount;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState state;
	int gameOver = -1;
	printf("----------------- Results for running isGameOver() tests: ----------------\n");

	memset(&state, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &state); // initialize a new game
	printf("Test 1: test isGameOver when it is not.\n");
	// test with initial state (game not over)
	gameOver = isGameOver(&state);

	if (gameOver == 0) {
		printf("isGameOver():  PASS when game currently not finished\n");
	}
	else {
		testsPassed = -1;
		printf("isGameOver():  FAIL when game currently not finished\n");
	}
	printf("Test 2: end game by running out of province cards.\n");
	// end game by running out of province cards
	oldProvinceCardCount = state.supplyCount[province];
	state.supplyCount[province] = 0;
	gameOver = isGameOver(&state);

	if (gameOver == 1) {
		printf("isGameOver():  PASS when game is finished due to empty stack of Province cards\n");
	}
	else {
		testsPassed = -1;
		printf("isGameOver():  FAIL when game is finished due to empty stack of Province cards\n");
	}
	// reset Province Card count
	state.supplyCount[province] = oldProvinceCardCount;
	printf("Test 3: one of supply piles empty - game not over.\n");
	// when three supply piles are at 0 the game ends.    on initialization, no supply piles will be 0.    uninitialized piles will be -1
	// test with 1, 2, and 3 supply piles at zero

	state.supplyCount[2] = 0;
	gameOver = isGameOver(&state);
	if (gameOver == 0) {
		printf("isGameOver():  PASS when game currently not finished (one supply pile empty)\n");
	}
	else {
		testsPassed = -1;
		printf("isGameOver():  FAIL when game currently not finished (one supply pile empty)\n");
	}
	printf("Test 4: two of supply piles empty - game not over.\n");
	state.supplyCount[4] = 0;
	gameOver = isGameOver(&state);
	if (gameOver == 0) {
		printf("isGameOver():  PASS when game currently not finished (two supply pile empty)\n");
	}
	else {
		testsPassed = -1;
		printf("isGameOver():  FAIL when game currently not finished (two supply pile empty)\n");
	}
	printf("Test 5: three supply piles empty - game over.\n");
	state.supplyCount[5] = 0;
	gameOver = isGameOver(&state);
	if (gameOver == 1) {
		printf("isGameOver():  PASS when game currently finished (three supply pile empty)\n");
	}
	else {
		testsPassed = -1;
		printf("isGameOver():  FAIL when game currently finished (three supply pile empty)\n");
	}

	testsPassed == 0 ? printf("All tests passed!\n") : printf("All tests did not pass!  Please review the test output for more details.\n");
	return 0;
}