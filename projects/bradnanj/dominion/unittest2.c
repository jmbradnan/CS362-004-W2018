/* -----------------------------------------------------------------------
* Unit tests for dominion-base game --> dominion.c
*
* This set of tests validates the discardCard method.
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

int unittest2() {
	int i;
	int seed = 1000;
	int numPlayer = 2;
	int handPos;
	int p, r, trashFlag;
	int testsPassed = 0;
	int oldPlayedCardCount, newPlayedCardCount, oldPlayedCardValue, newPlayedCardValue, oldHandCount, newHandCount;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState state;
	int maxHandCount = 5;
	int hand[5] = { 0, 0, 0, 0, 0};
	int handsMatch = 0;

	memset(&state, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &state); // initialize a new game

	printf("----------------- Results for running discardCard() tests: ----------------\n");

	for (p = 0; p < numPlayer; p++)
	{
		handPos = 4; //last card in the hand array has been played, number of card in hand is reduced
		trashFlag = 0;
		oldHandCount = state.handCount[p];  // store handCount before discardCard is called
		discardCard(handPos, p, &state, trashFlag);
		newHandCount = state.handCount[p];
		printf("Test 1: discard last card in hand.\n");
		if (newHandCount + 1 == oldHandCount) {
			printf("discardCard():  PASS when discarding last card in the hand for player %d\n", p);
		}
		else {
			testsPassed = 1;
			printf("discardCard():  FAIL when discarding last card in the hand for player %d\n", p);
			printf("\t Card hand count should be %d, and it is %d.\n", oldHandCount - 1, newHandCount);
		}

		handPos = 2; //non boundary case - card in hand
		trashFlag = 0;
		for (i = 0; i < 5; i++) {
			hand[i] = state.hand[p][i];
		}
		oldHandCount = state.handCount[p];  // store handCount before discardCard is called
		hand[handPos] = state.hand[p][oldHandCount - 1]; //replace discarded card with last card in hand
		hand[oldHandCount - 1] = -1; //set last card to -1
		discardCard(handPos, p, &state, trashFlag);
		newHandCount = state.handCount[p];
		//compare hand to state.hand for player and make sure they match
		for (i = 0; i < 5; i++) {
			if (hand[i] != state.hand[p][i]) {
				handsMatch = -1;
			}
		}
		printf("Test 2: discard card in hand (non-terminal).\n");
		if (handsMatch == 0 && newHandCount + 1 == oldHandCount) {
			printf("discardCard():  PASS when discarding non-terminal card in the hand for player %d\n", p);
		}
		else {
			printf("discardCard():  FAIL when discarding non-terminal card in the hand for player %d\n", p);
			if (handsMatch != 0) {
				printf("\t Hand for player %d is not correct.\n", p);
			}
			if (newHandCount + 1 != oldHandCount) {
				printf("\t Card hand count should be %d, and it is %d.\n", oldHandCount - 1, newHandCount);
			}
		}
	}

	testsPassed == 0 ? printf("All tests passed!\n") : printf("All tests did not pass!  Please review the test output for more details.\n");
	return 0;
}