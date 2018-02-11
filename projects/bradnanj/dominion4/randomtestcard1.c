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

int randomTestcard1(struct gameState *state, int cardDrawn, int temphand[MAX_HAND], int currentPlayer, int drawntreasure) {

	adverturerCard(state, cardDrawn, temphand, currentPlayer, drawntreasure);
	return 0;
}


