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

//int sizeOfSupplyCount();

int main() {
	int i;
	int seed = 1000;
	int numPlayer = 2;
	int handPos;
	int p, r, trashFlag;
	int testsPassed = 0;
	int oldPlayedCardCount, newPlayedCardCount, oldPlayedCardValue, newPlayedCardValue, oldHandCount, newHandCount;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState state;
	int maxHandCount = 3;

	memset(&state, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &state); // initialize a new game

	printf("Results for running discardCard() tests:\n");
	for (p = 0; p < numPlayer; p++)
	{
		handPos = 4; //last card in the hand array has been played, number of card in hand is reduced
		trashFlag = 0;
		oldHandCount = state.handCount[p];  // store handCount before discardCard is called
		discardCard(handPos, p, &state, trashFlag);
		newHandCount = state.handCount[p];

		if (newHandCount + 1 == oldHandCount) {
			printf("discardCard():  PASS when discarding last card in the hand for player %d\n", p);
		}
		else {
			testsPassed = 1;
			printf("discardCard():  FAIL when discarding last card in the hand for player %d\n", p);
			printf("\t Card hand count should be %d, and it is %d.\n", oldHandCount - 1, newHandCount);
		}

		handPos = 2; //non boundary case - card in hand
		discardCard(handPos, p, &state, trashFlag);
		//test stuff
		
		//delete some stuff so we are on one card in the hand
		state.handCount[p] = 1;
		handPos = 0; //only one card in hand
		discardCard(handPos, p, &state, trashFlag);

		//test more stuff when on last card in hand


			/*
			// trash discarded card
			// trashFlag = 1;

			// don't trash discarded card, check that playedCardCount increases by 1
			trashFlag = 0;
			oldPlayedCardCount = state.playedCardCount;
			oldPlayedCardValue = state.hand[p][handPos];
			discardCard(handPos, p, &state, trashFlag);
			newPlayedCardCount = state.playedCardCount;
			if (newPlayedCardCount == oldPlayedCardCount + 1) {
				printf("discardCard():  PASS when discarding card without trashing it (increase played cards count) -> player %d\n", p);
			}
			else {
				testsPassed = 1;
				printf("discardCard():  FAIL when discarding card without trashing it (increase played cards count) -> player %d\n", p);
				printf("\t Played card count should be %d, and it is %d.\n", oldPlayedCardCount + 1, newPlayedCardCount);
			}
			// check that the played card was invalidated (set to -1)
			newPlayedCardValue = state.hand[p][handPos];
			if (oldPlayedCardValue != -1 && newPlayedCardValue == -1) {
				printf("discardCard():  PASS: played card set to -1 for player %d\n", p);
			}
			else {
				testsPassed = 1;
				printf("discardCard():  FAIL: played card set to -1 for player %d\n", p);
				printf("\t Played card should be %d, and it is %d.\n", -1, newPlayedCardValue);
			}
			*/

		
	}

	testsPassed == 0 ? printf("All tests passed!\n") : printf("All tests did not pass!  Please review the test output for more details.\n");
	return 0;
}