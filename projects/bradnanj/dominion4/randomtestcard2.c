#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define TESTCARD "steward"

int randomTestcard2() {
	int testsPassed = 0;
	int i, j, m;			//counters
	int choice1, choice2, choice3, bonus, handpos, deckpos = 0;
	//time_t t;
	int card1, card2;
	//int oldHandCount, expectedDiscardCount;
	int currentPlayer = 0;
	int cardDrawn = 0;
	//int temphand[MAX_HAND];
	//int drawntreasure = 0;
	int returnVal;
	int oldDeckCount, oldHandCount, oldDiscardCount, oldPlayedCardCount, oldCoinCount = 0;
	//srand((unsigned)time(&t));
	int choices[5] = { -1, 0, 1, 2, 3 };

	struct gameState state, testState;
	for (i = 0; i < 1000; i++) {
		returnVal = -1;
		getGameState(&state, &testState);
		oldDeckCount = state.deckCount[currentPlayer];
		oldHandCount = state.handCount[currentPlayer];
		oldDiscardCount = state.discardCount[currentPlayer];
		oldPlayedCardCount = state.playedCardCount;
		oldCoinCount = state.coins;
		handpos = randRange(0, state.handCount[currentPlayer]-1);
		choice1 = choices[randRange(0, 4)];
		choice2 = handpos;  //need to pick other than handpos
		choice3 = handpos;
		while (choice2 == handpos) {
			choice2 = randRange(0, state.handCount[currentPlayer] - 1);
		}
		while (choice3 == handpos || choice3 == choice2) {
			choice3 = randRange(0, state.handCount[currentPlayer] - 1);
		}	

		returnVal = cardEffect(steward, choice1, choice2, choice3, &state, handpos, &bonus);

		if (choice1 == 1) {
			if ((returnVal == 0) && (oldDeckCount - 2 == state.deckCount[currentPlayer]) && 
				(oldHandCount + 1 == state.handCount[currentPlayer])) {
				printf("Test PASS steward with choice1 = 1.\n");
			}
			else {
				printf("Test FAIL steward with choice1 = 1.\n");
				if (returnVal != 0) {
					printf("\t cardEffect returned failure.\n");
				}
				if (state.deckCount[currentPlayer] != oldDeckCount - 2) {
					printf("\t Incorrect deck count after play.   Deck count expected to be %d and it was %d.\n", oldDeckCount - 2, state.deckCount[currentPlayer]);
				}
				if (state.handCount[currentPlayer] != oldHandCount + 1) {
					printf("\t Incorrect hand count after play.   Hand count expected to be %d and it was %d.\n", oldHandCount + 1, state.handCount[currentPlayer]);
				}
			}
		}
		else if (choice1 == 2) {
			if ((returnVal == 0) && (oldCoinCount + 2 == state.coins) &&
				(oldHandCount - 1 == state.handCount[currentPlayer])) {
				printf("Test PASS steward with choice1 = 2.\n");
			}
			else {
				printf("Test FAIL steward with choice1 = 2.\n");
				if (returnVal != 0) {
					printf("\t cardEffect returned failure.\n");
				}
				if (oldCoinCount + 2 != state.coins) {
					printf("\t Incorrect coin count after play.   Coin count expected to be %d and it was %d.\n", oldCoinCount + 2, state.coins);
				}
				if (state.handCount[currentPlayer] != oldHandCount - 1) {
					printf("\t Incorrect hand count after play.   Hand count expected to be %d and it was %d.\n", oldHandCount + 1, state.handCount[currentPlayer]);
				}
			}
		}
		else {
			if ((returnVal == 0) && (oldDiscardCount + 2 == state.discardCount[currentPlayer]) &&
				(oldHandCount - 1 == state.handCount[currentPlayer]) && (oldPlayedCardCount + 1 == state.playedCardCount)) {
				printf("Test PASS steward with choice1 = 2.\n");
			}
			else {
				printf("Test FAIL steward with choice1 = %d.\n", choice1);
				if (returnVal != 0) {
					printf("\t cardEffect returned failure.\n");
				}
				if (oldPlayedCardCount + 1 != state.playedCardCount) {
					printf("\t Incorrect played count after play.   Played count expected to be %d and it was %d.\n", oldPlayedCardCount + 1, state.playedCardCount);
				}
				if (oldDiscardCount + 2 != state.discardCount[currentPlayer]) {
					printf("\t Incorrect discard count after play.   Discard count expected to be %d and it was %d.\n", oldDiscardCount + 2, state.discardCount[currentPlayer]);
				}
				if (state.handCount[currentPlayer] != oldHandCount - 1) {
					printf("\t Incorrect hand count after play.   Hand count expected to be %d and it was %d.\n", oldHandCount + 1, state.handCount[currentPlayer]);
				}
			}
		}
	}
	
	return 0;
}


