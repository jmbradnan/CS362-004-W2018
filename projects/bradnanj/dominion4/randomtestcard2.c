#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define TESTCARD "mine"

int randomTestcard2() {
	int testsPassed = 0;
	int i, j, m;			//counters
	int choice1, choice3, bonus, handpos, deckpos = 0;
	//time_t t;
	int card1, card2;
	//int oldHandCount, expectedDiscardCount;
	int currentPlayer = 0;
	int cardDrawn = 0;
	//int temphand[MAX_HAND];
	//int drawntreasure = 0;
	int returnVal;
	int treasure, affordable;  //booleans
	//srand((unsigned)time(&t));

	struct gameState state, testState;
	for (i = 0; i < 1000; i++) {
		returnVal = -1;
		getGameState(&state, &testState);
		handpos = randRange(0, state.handCount[currentPlayer]-1);
		treasure = isTreasure(&state, currentPlayer, handpos);
		card1 = state.hand[currentPlayer][handpos];
		deckpos = randRange(0, state.deckCount[currentPlayer] - 1);
		card2 = state.deck[currentPlayer][deckpos];

		affordable = !(getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2);

		returnVal = cardEffect(mine, choice1, deckpos, choice3, &testState, handpos, &bonus);
		if (returnVal == -1 && treasure == 0) {
			printf("Test PASS with non treasure card drawn.\n");
		}
		else if (returnVal == -1 && affordable == 0) {
			printf("Test PASS with treasure card drawn and attempting to acquire card more than 3 coins higher.\n");
		}
		else if (returnVal == 0 && treasure == 1) {
			printf("Test PASS with treasure card drawn.\n");
		}
		else {
			printf("Test FAIL\n");
			if (returnVal != 0) {
				printf("\t Call to cardEffect for mine returned failure.\n");
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


