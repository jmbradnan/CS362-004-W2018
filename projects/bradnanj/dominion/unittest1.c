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
	int maxToFlag = 4;
	int toFlag;
	int supplyPos;
    int p, r, handCount;
	int testsPassed = 0;
	int supplyCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;

    printf ("TESTING gainCard():\n");
    for (p = 0; p < numPlayer; p++)
    {
            for (toFlag = 0; toFlag <= maxToFlag; toFlag++)	
            {
				printf("Test player %d with %d toFlag.\n", p, handCount, toFlag);
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				supplyCount = sizeOfSupplyCount(&G);
				printf("Supply count = %d.", supplyCount);
                G.handCount[p] = handCount;                 // set the number of cards on hand
				gainCard(supplyPos, &G, toFlag, p);
				if (toFlag == 0) {
					
				}
			}
	}
    printf("All tests passed!\n");
    //return 0;
	return testsPassed;
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
