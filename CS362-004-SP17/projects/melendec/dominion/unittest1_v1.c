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

struct playerDecks
{
	int handCard[5];
	int discardCard[100];
	int deckCard[100];
};

int main() {
    int i;
    int seed = 1000;
    //int numPlayer = 2;
	int numPlayer = 1;
    int maxBonus = 10;
    int r, handCount, discardCount,testScore;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
	int scoreCards[6] = {curse, estate, duchy, province, great_hall, gardens};
	int scoreCards2[6] = {1,2,3,4,5,6};
    struct gameState G;
    int maxHandCount = 5;
	int maxDiscardCount = 100;
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
	int w,x,y,z,scoreCardCounter;
	int a = 0; 
	int b = 0; 
	int c = 0; 
	int d = 0; 
	int e = 0; 
	int f = 0;
	
	struct playerDecks combinations;
	int l,m,n,o,p,q;
	
	for(o = 0; o < 5; o++)
	{
		for(p = 0; p < 100; p++)
		{
			for(q = 0; q < 100; q++)
			{
				for(l = 0; l < 6; l++)
				{
					for(m = 0; m < 6; m++)
					{
						for(n = 0; n < 6; n++)
						{
							combinations.handCard[o] = scoreCards[l];
							combinations.discardCard[p] = scoreCards[m];
							combinations.deckCard[q] = scoreCards[n];
							printf("combinations.handCard[%d]: %d\n",o,combinations.handCard[o]);
							printf("combinations.discardCard[%d]: %d\n",p,combinations.discardCard[p]);
							printf("combinations.deckCard[%d]: %d\n",q,combinations.deckCard[q]);
						}
					}
				}
			}
		}
	}
	
    printf ("TESTING updateCoins():\n");

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	G.handCount[p] = maxHandCount;              // set the number of cards on hand
	G.discardCount[p] = maxDiscardCount;
	
	for(handCount = 1; handCount <= maxHandCount; handCount++)
	{
		for(discardCount = 0; discardCount <=maxDiscardCount; discardCount++)
		{
			
					 	
			 
			
		}
	}
	
    /*for (p = 0; p < numPlayer; p++)
    {
		for(handCount = 1; handCount <= maxHandCount; handCount++)
		{
			for(discardCount = 0; discardCount <=maxDiscardCount; discardCount++)
			{
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[p] = maxHandCount;                 // set the number of cards on hand
				G.discardCount[p] = maxDiscardCount;
							
				for(x = 0; x < handCount ; x++)
				{
					for(y = 0; y < maxDiscardCount; y++)
					{
						for(z = 0; z < maxDiscardCount; z++)
						{	
							G->hand[p][x] = scoreCards[scoreCardCounter];
							G->discard[p][y] = scoreCards[scoreCardCounter];
							G->deck[p][z] = scoreCards[scoreCardCounter];
						}
					}
				}
				
			}
		}
	}*/
	
	
    printf("All tests passed!\n");

    return 0;
}
