/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int sizeOfSupplyCount();

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
	int maxToFlag = 3;
	int toFlag;
	int supplyPos=0;
    int p, r, handCount;
	int testsPassed = 0;
	int previousSupplyCount, previousDiscardCount, postSupplyCount, postDiscardCount, previousHandCount, postHandCount, previousDeckCount, postDeckCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;

    printf ("Result for running gainCard() tests:\n");
    for (p = 0; p < numPlayer; p++)
    {
            for (toFlag = 0; toFlag <= maxToFlag; toFlag++)	
            {
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

				// Get state property counts prior to gainCard call
				previousSupplyCount = G.supplyCount[supplyPos];
				previousDiscardCount = G.discardCount[p];
				previousHandCount = G.handCount[p];
				previousDeckCount = G.deckCount[p];

				gainCard(supplyPos, &G, toFlag, p);

				// Get state property counts after to gainCard call
				postSupplyCount = G.supplyCount[supplyPos];
				postDiscardCount = G.discardCount[p];
				postHandCount = G.handCount[p];
				postDeckCount = G.deckCount[p];
				supplyPos++;

				// Check all post counts to ensure they are correct
				// toFlag = 0 : add to discard
				if (toFlag == 0) {
					if ((postDiscardCount == previousDiscardCount + 1) && (postSupplyCount == previousSupplyCount - 1)) {
						printf("gainCard():  PASS when add to discard performed with player %d\n", p);
					}
					else {
						testsPassed = 1;
						printf("gainCard():  FAIL when add to discard performed\n");
						if (postDiscardCount != previousDiscardCount + 1) { printf("\t Discard Count should be %d, and it is %d.\n", previousDiscardCount + 1, postDiscardCount); }
						if (postSupplyCount != previousSupplyCount - 1) { printf("\t Supply Count should be %d, and it is %d.\n", previousSupplyCount - 1, postSupplyCount); }
					}
				}
				// toFlag = 1 : add to deck
				if (toFlag == 1) {
					if ((postDeckCount == previousDeckCount + 1) && (previousDiscardCount == postDiscardCount) && (postSupplyCount == previousSupplyCount - 1)) {
						printf("gainCard():  PASS when add to deck performed with player %d\n", p);
					}
					else {
						testsPassed = 1;
						printf("gainCard():  FAIL when add to deck performed\n");
						if (postDeckCount != previousDeckCount + 1) { printf("\t Deck Count should be %d, and it is %d.\n", previousDeckCount + 1, postDeckCount); }
						if (postDiscardCount != previousDiscardCount) { printf("\t Discard Count should be %d, and it is %d.\n", previousDiscardCount, postDiscardCount); }
						if (postSupplyCount != previousSupplyCount - 1) { printf("\t Supply Count should be %d, and it is %d.\n", previousSupplyCount - 1, postSupplyCount); }
					}
				}
				// toFlag = 2 : add to hand
				if (toFlag == 2) {
					if ((postHandCount == previousHandCount + 1) && (previousDiscardCount == postDiscardCount) && (postSupplyCount == previousSupplyCount - 1)) {
						printf("gainCard():  PASS when add to hand performed with player %d\n", p);
					}
					else {
						testsPassed = 1;
						printf("gainCard():  FAIL when add to hand performed\n");
						if (postHandCount != previousHandCount + 1) { printf("\t Hand Count should be %d, and it is %d.\n", previousHandCount + 1, postHandCount); }
						if (postDiscardCount != previousDiscardCount) { printf("\t Discard Count should be %d, and it is %d.\n", previousDiscardCount, postDiscardCount); }
						if (postSupplyCount != previousSupplyCount - 1) { printf("\t Supply Count should be %d, and it is %d.\n", previousSupplyCount - 1, postSupplyCount); }
					}
				}
				//this is not a supported toFlag and should fail gracefully - without changing anything
				if (toFlag == 3) {
					if ((postHandCount == previousHandCount) && (postDiscardCount == previousDiscardCount) && (postSupplyCount == previousSupplyCount) && (postDeckCount == previousDeckCount)) {
						printf("gainCard():  PASS when invalid param passed to gainCard() for player %d\n", p);
					}
					else {
						testsPassed = 1;
						printf("gainCard():  FAIL when invalid param (toFlag = 3) passed to gainCard() for player %d\n", p);
						if (postHandCount != previousHandCount) { printf("\t Hand Count should be %d, and it is %d.\n", previousHandCount, postHandCount); }
						if (postDiscardCount != previousDiscardCount) { printf("\t Discard Count should be %d, and it is %d.\n", previousDiscardCount, postDiscardCount); }
						if (postSupplyCount != previousSupplyCount) { printf("\t Supply Count should be %d, and it is %d.\n", previousSupplyCount, postSupplyCount); }
						if (postDeckCount != previousDeckCount) { printf("\t Deck Count should be %d, and it is %d.\n", previousDeckCount, postDeckCount); }
					}
				}
			}
	}
	testsPassed == 0 ? printf("All tests passed!\n") : printf("All tests did not pass!  Please review the test output for more details.\n");
		return 0;
}

int sizeOfSupplyCount(struct gameState *state) {
	int size = 0;
	int i = 0;

	while (i < 27) {
		printf("value at position %d is %d.\n", i, state->supplyCount[i]);
		if (state->supplyCount[i] == -1) {
			break;
		}
		else {
			size++;
		}
		i++;
	}
	return size;
}
