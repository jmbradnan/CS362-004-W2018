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
	int oldPlayedCardCount, newPlayedCardCount;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState state;
	int maxHandCount = 5;

	printf("Results for running discardCard() tests:\n");
	for (p = 0; p < numPlayer; p++)
	{
		for (handPos = 0; handPos <= maxHandCount; handPos++)
		{
			memset(&state, 23, sizeof(struct gameState));   // clear the game state
			r = initializeGame(numPlayer, k, seed, &state); // initialize a new game

			// trash discarded card
			trashFlag = 1;

			// don't trash discarded card
			trashFlag = 0;
			oldPlayedCardCount = state.playedCardCount;
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

		}
	}

	testsPassed == 0 ? printf("All tests passed!\n") : printf("All tests did not pass!  Please review the test output for more details.\n");
	return 0;
}