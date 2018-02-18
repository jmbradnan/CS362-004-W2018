#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define TESTCARD "village"

int main() {
	time_t t;
	srand((unsigned)time(&t));
	int i;
	int choice1, choice2, choice3, bonus, handpos = 0;

	int oldHandCount, oldDiscardCount, oldNumActions;
	int currentPlayer = 0;
	int returnVal;

	struct gameState state, testState;
	for (i = 0; i < 500; i++) {
		returnVal = -1;
		getGameState(&state, &testState);
		handpos = randRange(0, state.handCount[currentPlayer] - 1);
		oldHandCount = state.handCount[currentPlayer];
		oldDiscardCount = state.discardCount[currentPlayer];
		oldNumActions = state.numActions;

		returnVal = cardEffect(village, 0, 0, 0, &state, handpos, &bonus);

		if (returnVal == 0 && state.handCount[currentPlayer] == oldHandCount &&
			oldDiscardCount + 1 == state.discardCount[currentPlayer] && oldNumActions + 2 == state.numActions) {
			printf("Test PASS with villace card and hand position %d\n", handpos);
		}
		else {
			printf("Test FAIL with villace card and hand position %d\n", handpos);
			if (returnVal != 0) {
				printf("\t cardEffect returned failure.\n");
			}
			if (state.handCount[currentPlayer] != oldHandCount) {
				printf("\t Incorrect hand count after play.   Hand count expected to be %d and it was %d.\n", oldHandCount, state.handCount[currentPlayer]);
			}
			if (oldDiscardCount + 1 != state.discardCount[currentPlayer]) {
				printf("\t Incorrect discard count after play.   Discard count expected to be %d and it was %d.\n", oldDiscardCount + 1, state.discardCount[currentPlayer]);
			}
			if (oldNumActions + 2 != state.numActions) {
				printf("\t Incorrect numActions count after play.   numActions count expected to be %d and it was %d.\n", oldNumActions + 2, state.numActions);
			}
		}
	}

	return 0;
}


