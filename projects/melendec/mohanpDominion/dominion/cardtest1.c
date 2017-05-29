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
#define NOISY_TEST 0

int main() {
    int i,j;
    int seed = 1000;
    int numPlayer = 4;
    int maxBonus = 10;
    int p, r,s, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G,H;
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

    printf ("TESTING playSmithy():\n");
    
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	s = initializeGame(numPlayer, k, seed, &H); //setup identical game
	G.numPlayers = numPlayer;
	H.numPlayers = numPlayer;
	
	

	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 4; j++)
		{
			drawCard(j,&H);
			drawCard(j,&H);
			drawCard(j,&H);
			discardCard(i,j,&H,0);
			smithyEffect(&G,j,i);
			printf("G.playedCardCount: %d || H.playedCardCount: %d\n",G.playedCardCount,H.playedCardCount );
			assert(G.handCount[j] == H.handCount[j]);
			assert(G.discardCount[j] == H.discardCount[j]);
			assert(G.deckCount[j] == H.deckCount[j]);
			assert(G.playedCardCount == H.playedCardCount);
			
		}
	}

    printf("All tests passed!\n");

    return 0;
}