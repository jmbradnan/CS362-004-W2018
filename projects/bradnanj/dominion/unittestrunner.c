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

int main() {
	unittest1();
	unittest2();
	unittest3();
	unittest4();
	cardtest1();
	cardtest2();
	cardtest3();
	cardtest4();
}
