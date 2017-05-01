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
    int i,j,m,l;
    int seed = 1000;
    int numPlayer = 4;
    int maxBonus = 10;
    int p, r,s,handCount;
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

    printf ("TESTING playSteward():\n");
    
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	memset(&H, 23, sizeof(struct gameState));
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	s = initializeGame(numPlayer, k, seed, &H); //setup identical game
	G.numPlayers = numPlayer;
	H.numPlayers = numPlayer;

	//choice1 ==1 
	for(i = 0; i < 5; i++)
	{

		for(m = 0; m < 5; m++)
		{

			for(l = 0; l < 5; l++)
			{

				for(j = 0; j < 4; j++)
				{

					drawCard(j,&H);
					drawCard(j,&H);
					discardCard(l,j,&H,0);
					playSteward(1,i,m,l,&G,j);
					assert(G.handCount[j] == H.handCount[j]);
					
				}
			}
		}
	}
	
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	memset(&H, 23, sizeof(struct gameState));
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	s = initializeGame(numPlayer, k, seed, &H); //setup identical game
	G.numPlayers = numPlayer;
	H.numPlayers = numPlayer;
	//choice1 == 2
	for(i = 0; i < 5; i++)
	{
		for(m = 0; m < 5; m++)
		{
			for(l = 0; l < 5; l++)
			{
				for(j = 0; j < 4; j++)
				{
					H.coins += 2;
					discardCard(l,j,&H,0);
					playSteward(1,i,m,l,&G,j);
					playSteward(1,i,m,l,&G,j);
					assert(G.handCount[j] == H.handCount[j]);
					assert(G.coins == H.coins);
					
				}
			}
		}
	}
	
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	memset(&H, 23, sizeof(struct gameState));
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	s = initializeGame(numPlayer, k, seed, &H); //setup identical game
	G.numPlayers = numPlayer;
	H.numPlayers = numPlayer;
	//choice1 == other
	for(i = 0; i < 5; i++)
	{
		for(m = 0; m < 5; m++)
		{
			for(l = 0; l < 5; l++)
			{
				for(j = 0; j < 4; j++)
				{
					discardCard(i,j,&H,1);
					discardCard(m,j,&H,1);
					discardCard(l,j,&H,0);
					playSteward(1,i,m,l,&G,j);
					assert(G.handCount[j] == H.handCount[j]);
					
				}
			}
		}
	}
	
    printf("All tests passed!\n");

    return 0;
}