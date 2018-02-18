#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define TESTCARD "adventurer"

int main() {
	time_t t;
	srand((unsigned)time(&t));
	int testsPassed = 0;
	int i, j, m;
	int coins;
	int oldHandCount, expectedDiscardCount;
	int currentPlayer = 0;
	int cardDrawn = 0;
	int temphand[MAX_HAND];
	int drawntreasure = 0;
	int returnVal;

	struct gameState state, testState;

	for (i = 0; i < 500; i++) {
		returnVal = -1;
		getGameState(&state, &testState);

		oldHandCount = state.handCount[currentPlayer];
		expectedDiscardCount = discardedCount(&testState, currentPlayer);
		returnVal = adverturerCard(&state, cardDrawn, temphand, currentPlayer, drawntreasure);

		if (returnVal == 0 && state.handCount[currentPlayer] == oldHandCount + 2 && expectedDiscardCount == state.discardCount[currentPlayer] ) {
			printf("Test PASS\n");
		}
		else {
			printf("Test FAIL\n");
			if (returnVal != 0) {
				printf("\t Call to cardEffect for adventurer returned failure.\n");
			}
			if (state.handCount[currentPlayer] != oldHandCount + 2) {
				printf("\t Incorrect hand count after play.   Hand count expected to be %d and it was %d.\n", oldHandCount + 2, state.handCount[currentPlayer]);
			}
			if (expectedDiscardCount != state.discardCount[currentPlayer]) {
				printf("\t Incorrect discard count after play.   Discard count expected to be %d and it was %d.\n", expectedDiscardCount, state.discardCount[currentPlayer]);
			}
		}	
	}
	return 0;
}


int discardedCount(struct gameState *state, int p) {
	int count = 0;
	int drawnTreasure = 0;
	int lastCard = state->deckCount[p] - 1;

	while (drawnTreasure < 2 && lastCard >= 0) {
		if (state->deck[p][lastCard] == copper || state->deck[p][lastCard] == silver || state->deck[p][lastCard] == gold) {
			drawnTreasure++;
		}
		else {
			count++;
		}
		lastCard--;
	}
	return count;
}

