/* -----------------------------------------------------------------------
 * Unit tests for dominion-base game --> dominion.c
 *
 * This is the main unit test runner.
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

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

int getGameState(struct gameState *state, struct gameState *testState)
{
	int numPlayers = 3;
	int seed = 1000;
	int* k = getKingdomCards(10, adventurer);
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, state);
	// copy the game state to a test case
	memcpy(testState, state, sizeof(struct gameState));
	return 0;
}

int main() {
	//int testsPassed = 0;
	int i, j, m;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	//int seed = 1000;
	
	int currentPlayer = 0;
	int cardDrawn = 0;
	int temphand[MAX_HAND];
	int drawntreasure = 0;

	struct gameState state, testState;
	
	//int* k = getKingdomCards(10, adventurer);
	// initialize a game state and player cards
	//initializeGame(numPlayers, k, seed, &state);
	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	//printf("Test 1: pick up two treasure cards (coppers), discard one card.\n");

	// copy the game state to a test case
	//memcpy(&testState, &state, sizeof(struct gameState));

	for (i = 0; i < 1000; i++) {
		//currentPlayer = whoseTurn(state);
		getGameState(&state, &testState);
		randomTestcard1(&testState, cardDrawn, temphand, currentPlayer, drawntreasure);
	}
	
}
