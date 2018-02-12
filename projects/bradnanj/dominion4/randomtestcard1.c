#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

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
	array_shuffle(k, 10);
	return k;
}
int gameStateValidator(struct gameState *state, struct gameState *testState) {
	//compare hand

	//compare discard pile

	return 0;
}

int setPlayedGameState() {
	return 0;
}

//inclusive range
int randRange(int begin, int end) {
	return begin + (rand() % (end - begin + 1));
}

int getGameState(struct gameState *state, struct gameState *testState)
{
	int numPlayers = 4;
	int oldCardCount, addedCards;
	int i, pos = 0;

	int coins;
	int coinValue;
	int seed = rand() % 1000;
	//int currentPlayer = rand() % numPlayers;
	int* k = getKingdomCards(10, adventurer);
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, state);

	//state->whoseTurn = currentPlayer;

	// add more cards to hand from supply 
	oldCardCount = state->handCount[0];
	addedCards = randRange(0, 4); //you can add up to 5 more cards to the hand
	state->handCount[0] = oldCardCount + addedCards;
	for (i = oldCardCount; i < state->handCount[0]; i++) {
		pos = randRange(0, 25);
		while (state->supplyCount[pos] == -1) {
			pos = randRange(0, 25);
		}
		state->hand[0][i] = pos;
		state->supplyCount[pos]--;
	}

	// mutate the deck for player 0
	oldCardCount = state->deckCount[0];
	addedCards = randRange(oldCardCount, 30); //you can have up to 500 cards in hand, but there won't be enough supply

											  //mutate the kinds and numbers of coins in the deck for player 0
	coins = rand() % 5;
	for (i = 0; i < coins; i++) {
		coinValue = randRange(4, 6);
		state->hand[0][pos] = coinValue;
		pos++;
	}

	state->deckCount[0] = oldCardCount + addedCards;
	for (i = oldCardCount; i < state->deckCount[0]; i++) {
		pos = randRange(0, 25);
		while (state->supplyCount[pos] == -1) {
			pos = randRange(0, 25);
		}
		state->deck[0][i] = pos;
		state->supplyCount[pos]--;
	}

	array_shuffle(state->hand, state->handCount[0]);  //shuffles hand in player 0 position
	array_shuffle(state->deck, state->deckCount[0]);  //shuffles deck in player 0 position
													  // copy the game state to a test case
	memcpy(testState, state, sizeof(struct gameState));
	return 0;
}

int discardedCount(struct gameState *state, int p) {
	int count = 0;
	int drawnTreasure = 0;
	int lastCard = state->handCount[p] - 1;

	while (drawnTreasure < 2 && lastCard >= 0) {
		if (state->hand[lastCard] == copper || state->hand[lastCard] == silver || state->hand[lastCard] == gold) {
			drawnTreasure++;
		}
		else {
			count++;
		}
		lastCard--;
	}
	return count;
}

//int randomTestcard1(struct gameState *state, int cardDrawn, int temphand[MAX_HAND], int currentPlayer, int drawntreasure) {
int randomTestcard1() {
	int testsPassed = 0;
	int i, j, m;
	time_t t;
	int coins;
	int oldHandCount, expectedDiscardCount;
	int currentPlayer = 0;
	int cardDrawn = 0;
	int temphand[MAX_HAND];
	int drawntreasure = 0;
	int returnVal = -1;
	srand((unsigned)time(&t));

	struct gameState state, testState;

	for (i = 0; i < 1000; i++) {
		getGameState(&state, &testState);

		oldHandCount = state.handCount[currentPlayer];
		expectedDiscardCount = discardedCount(&testState, currentPlayer);
		//returnVal = randomTestcard1(&state, cardDrawn, temphand, currentPlayer, drawntreasure);
		returnVal = adverturerCard(&state, cardDrawn, temphand, currentPlayer, drawntreasure);

		if (returnVal == 0 && state.handCount[currentPlayer] == oldHandCount + 2 && expectedDiscardCount == state.discardCount[currentPlayer] ) {
			printf("Test PASS\n");
		}
		else {
			printf("Test FAIL\n");
		}

		
	}
	//adverturerCard(state, cardDrawn, temphand, currentPlayer, drawntreasure);
	return 0;
}


