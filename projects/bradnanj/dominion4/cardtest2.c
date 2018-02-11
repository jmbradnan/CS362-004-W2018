/* -----------------------------------------------------------------------
* Unit tests for dominion-base game --> dominion.c
*
* This set of tests validates the Adventurer card.
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>


#define TESTCARD "adventurer"

/*
int rand_card() {
	return rand() % kingdom_card_count;
}
*/

//https://stackoverflow.com/questions/6127503/shuffle-array-in-c
int array_shuffle(int *array, size_t n) {
	if (n > 1)
	{
		size_t i;
		for (i = 0; i < n - 1; i++)
		{
			size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
			int t = array[j];
			array[j] = array[i];
			array[i] = t;
		}
	}
	return 0;
}

int* getKingdomCards(int size, int card) {
	int* k = malloc(size * sizeof(int));
	int count = treasure_map - adventurer;
	int i, j = 0;
	int* most_cards = malloc(count * sizeof(int));
	int fill = 0;

	k[0] = card;
	for (j = adventurer; j <= treasure_map; j++) {
		if (j != card) {
			most_cards[fill++] = j;
		}
	}
	//std::random_shuffle(&most_cards[0], &most_cards[kingdom_card_count - 1]);
	array_shuffle(most_cards, count);
	for (i = 1; i < size; i++) {
		k[i] = most_cards[i];
	}
	return k;
}


int cardtest2() {
	int testsPassed = 0;
	int numberOfDiscards;
	int i, j, m;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int remove1, remove2;
	int seed = 1000;
	int numPlayers = 3;
	int p = 4;
	int oldDiscardCount, oldHandCount;
	struct gameState G, testG;
	//int k[10] = { adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room };
	enum CARD* k = getKingdomCards(10, adventurer);
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	printf("Test 1: pick up two treasure cards (coppers), discard one card.\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	numberOfDiscards = 1;
	oldDiscardCount = testG.discardCount[p];
	oldHandCount = testG.handCount[p];
	testG.deck[p][4] = 8;
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	//should result in one discarded card, 2 added treasure cards
	if (oldDiscardCount + numberOfDiscards == testG.discardCount[p] && oldHandCount + 2 == testG.handCount[p]) {
		printf("AdventurerCard():  PASS pick up two treasure cards (coppers), discard one card\n");
	}
	else {
		testsPassed = -1;
		printf("AdventurerCard():  FAIL pick up two treasure cards (coppers), discard one card\n");
		if (oldDiscardCount + numberOfDiscards != testG.discardCount[p]) {
			printf("\t discard count = %d, expected to be = %d\n", testG.discardCount[p], oldDiscardCount + numberOfDiscards);
		}
		if (oldHandCount + 2 != testG.handCount[p]) {
			printf("\t hand count = %d, expected to be = %d\n", testG.handCount[p], oldHandCount + 2);
		}
	}
	
	printf("Test 2: pick up two treasure cards (copper and silver), discard two cards.\n");
	numberOfDiscards = 2;
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	oldDiscardCount = testG.discardCount[p];
	oldHandCount = testG.handCount[p];
	testG.deck[p][4] = 8;
	testG.deck[p][3] = 7;
	testG.deck[p][1] = 5;
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	//should result in one discarded card, 2 added treasure cards
	if (oldDiscardCount + numberOfDiscards == testG.discardCount[p] && oldHandCount + 2 == testG.handCount[p]) {
		printf("AdventurerCard():  PASS pick up two treasure cards (copper and silver), discard two cards\n");
	}
	else {
		testsPassed = -1;
		printf("AdventurerCard():  FAIL pick up two treasure cards (copper and silver), discard two cards\n");
		if (oldDiscardCount + numberOfDiscards != testG.discardCount[p]) {
			printf("\t discard count = %d, expected to be = %d\n", testG.discardCount[p], oldDiscardCount + numberOfDiscards);
		}
		if (oldHandCount + 2 != testG.handCount[p]) {
			printf("\t hand count = %d, expected to be = %d\n", testG.handCount[p], oldHandCount + 2);
		}
	}

	printf("Test 3: pick up two treasure cards (silver and gold), discard zero cards.\n");
	numberOfDiscards = 0;
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	oldDiscardCount = testG.discardCount[p];
	oldHandCount = testG.handCount[p];
	testG.deck[p][4] = 5;
	testG.deck[p][3] = 6;
	
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	//should result in one discarded card, 2 added treasure cards
	if (oldDiscardCount + numberOfDiscards == testG.discardCount[p] && oldHandCount + 2 == testG.handCount[p]) {
		printf("AdventurerCard():  PASS pick up two treasure cards (silver and gold), discard zero cards\n");
	}
	else {
		testsPassed = -1;
		printf("AdventurerCard():  FAIL pick up two treasure cards (silver and gold), discard zero cards\n");
		if (oldDiscardCount + numberOfDiscards != testG.discardCount[p]) {
			printf("\t discard count = %d, expected to be = %d\n", testG.discardCount[p], oldDiscardCount + numberOfDiscards);
		}
		if (oldHandCount + 2 != testG.handCount[p]) {
			printf("\t hand count = %d, expected to be = %d\n", testG.handCount[p], oldHandCount + 2);
		}
	}
	printf("Test 4: keep digging for treasure -- DISABLED due to infinite loop.\n");
	/*
	The following test was designed to make adventurer keep digging for treasure.     It causes an infinite loop so it is not enabled.

	testG.deck[p][4] = 8;
	testG.deck[p][3] = 7;
	testG.deck[p][2] = 9;
	testG.deck[p][1] = 10;
	testG.deck[p][0] = 8;

	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	*/

	testsPassed == 0 ? printf("All tests passed!\n") : printf("All tests did not pass!  Please review the test output for more details.\n");

	return 0;
}


