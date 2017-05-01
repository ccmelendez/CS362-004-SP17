/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf ("TESTING isGameOver():\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G);
	
	for(i = 0; i < treasure_map+1; i++)
	{
		G.supplyCount[i] = i+1;
		//game is not over, all supply cards have at least 1 i+1 cards.
	}
	assert(isGameOver(&G) !=1);
	
	G.supplyCount[5] = 0;
	//game is still not empty, province card still has more than i+1 cards
	assert(isGameOver(&G) !=1);
	
	G.supplyCount[6] = 0;
	//again, still not enough piles to warrant end of game.
	assert(isGameOver(&G) !=1);
	
	G.supplyCount[7] = 0; 
	//game should be over now, three supply stacks are empty.
	assert(isGameOver(&G) != 0);
	
	G.supplyCount[5] = 6; 
	G.supplyCount[6] = 7;
	G.supplyCount[7] = 8; 
	G.supplyCount[3] = 0; 
	//reset gold, silver, & copper card counts to what they were to the beg of the test and make the province stack have zero. Game should be over
	assert(isGameOver(&G) !=0);
	
	G.supplyCount[3] = 5;
	//reset province card count to original
	
	for(i = 0; i < treasure_map +1 -2; i++)
	{
		//insert values of 0 starting at beg of supplyCount[], then shift the zeros right
		int tempA,tempB,tempC;
		tempA = G.supplyCount[i]; 
		tempB = G.supplyCount[i+1];
		tempC = G.supplyCount[i+2];
		G.supplyCount[i] = 0;
		G.supplyCount[i+1] = 0; 
		G.supplyCount[i+2] = 0; 
		//all these tests should end the game since we have 3 cards whose counts are 0.
		assert(isGameOver(&G) != 0);
		G.supplyCount[i] = tempA;
		G.supplyCount[i+1] = tempB; 
		G.supplyCount[i+2] = tempC; 
		//reset values for next
	}

	
    printf("All tests passed!\n");

    return 0;
}