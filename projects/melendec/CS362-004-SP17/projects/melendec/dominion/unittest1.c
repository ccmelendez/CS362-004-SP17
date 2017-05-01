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
    //int numPlayer = 2;
	int numPlayer = 1;
    int maxBonus = 10;
	int testScore = 0; 
    int r, handCount, discardCount,scoreForValue;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
	int scoreCards[6] = {curse, estate, duchy, province, great_hall, gardens};
	
    struct gameState G;
    int maxHandCount = 5;
	int maxDiscardCount = 50;
	int maxDeckCount = 50;
	int maxTotalCount = maxHandCount + maxDeckCount + maxDiscardCount;
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

	
    printf ("TESTING scoreFor():\n");

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G);	// initialize a new game
	G.handCount[0] = maxHandCount;              // set the number of cards on hand, chose one player, since the function sums up the player score individually, and does not depend on another player's score
	G.discardCount[0] = maxDiscardCount;		
	G.deckCount[0] = maxDeckCount;
	int scoreCardsValues[6] = {-1,1,3,6,1,fullDeckCount(0,0,&G)/10};

	
	for(i = 0; i < maxHandCount; i++)
	{
		//setup player hand cards
		G.hand[0][i] = scoreCards[i%6];
	}
	scoreCardsValues[5] = fullDeckCount(0,0,&G)/10;
	for(i = 0; i < maxHandCount; i++)
	{
		testScore += scoreCardsValues[i%6];
	}
	scoreForValue = scoreFor(0,&G);
	printf("testScore: %d | score: %d\n", testScore, scoreForValue);
	assert(testScore == scoreForValue);
	
	
	for(i = 0; i < maxDiscardCount; i++)
	{
		//setup player discard cards
		G.discard[0][i] = scoreCards[i%6];
	}
	scoreCardsValues[5] = fullDeckCount(0,0,&G)/10;
	for(i = 0; i < maxDiscardCount; i++)
	{
		testScore += scoreCardsValues[i%6];
	}
	scoreForValue = scoreFor(0,&G);
	printf("testScore: %d | score: %d\n", testScore, scoreForValue);
	assert(testScore == scoreForValue);

	
	
	for(i = 0; i < maxDeckCount; i++)
	{
		//setup player deck cards
		G.deck[0][i] = scoreCards[i%6];
	}
	scoreCardsValues[5] = fullDeckCount(0,0,&G)/10;
	for(i = 0; i < maxDeckCount; i++)
	{
		testScore += scoreCardsValues[i%6];
	}
	scoreForValue = scoreFor(0,&G);
	printf("testScore: %d | score: %d\n", testScore, scoreForValue);
	assert(testScore == scoreForValue);
	
	
	
    printf("All tests passed!\n");

    return 0;
}
