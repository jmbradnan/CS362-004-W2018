#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define TESTCARD "village"



int randomTestcard3() {
	int testsPassed = 0;
	int i, j, m;
	int choice1, choice2, choice3, bonus, handpos = 0;
	//time_t t;
	int coins;
	int oldHandCount, expectedDiscardCount;
	int currentPlayer = 0;
	int cardDrawn = 0;
	int temphand[MAX_HAND];
	int drawntreasure = 0;
	int returnVal;
	//srand((unsigned)time(&t));

	struct gameState state, testState;
	for (i = 0; i < 1000; i++) {
		returnVal = -1;
		getGameState(&state, &testState);

		returnVal = cardEffect(village, 0, 0, 0, &testState, 0, &bonus);
	}

	if (returnVal == 0 && state.handCount[currentPlayer] == oldHandCount + 2 && expectedDiscardCount == state.discardCount[currentPlayer]) {
		printf("Test PASS\n");
	}
	else {
		printf("Test FAIL\n");
	}
}


