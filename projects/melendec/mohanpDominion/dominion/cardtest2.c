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

// set PRINT_ON to 0 to remove printfs from output
#define PRINT_ON 0

int main() {
    int i,j;
    int seed = 1000;
    int numPlayer = 4;
    int maxBonus = 10;
	int drawntreasure = 0;
	int cardDrawn;
    int p, r,s, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState H,G;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
	int tempHand[MAX_HAND];
	int z = 0;
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf ("TESTING playAdventurer():\n");
   
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	memset(&H, 23, sizeof(struct gameState)); 
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	s = initializeGame(numPlayer, k, seed, &H); //setup identical game
	G.numPlayers = numPlayer;
	H.numPlayers = numPlayer;
	

	
	
	for(j = 0; j < numPlayer; j++)
	{
		int treasureCheck = 0;
		int noOfCardsBeforeTreasure = 0;
		int noOfTreasureCards = 0;
		if(PRINT_ON){printf("----------------------player %d----------------------\n",j);}
		for(i = 0; i < G.deckCount[j]; i++)
		{
				if(PRINT_ON){printf("hand[%d]: %d\n",i,G.deck[j][i]);}
				if( (G.deck[j][i] == 4) || (G.deck[j][i] == 5) || (G.deck[j][i] == 6) )
				{
					noOfTreasureCards +=1;
				}
				else
				{
					noOfCardsBeforeTreasure +=1;
					//if not a treasure card, increase count by one
				}
				
				
				if( noOfTreasureCards == 2)
				{
					treasureCheck = noOfCardsBeforeTreasure;
					break;
				}
				//simulate before calling playAdventurer how many cards should be drawn.

		}
	
		
		H.handCount[j] += 2; //put two treasure cards into hand
		H.deckCount[j] -=2; //subtract two the two treasure cards from deck
		H.discardCount[j] += noOfCardsBeforeTreasure; //add non treasure cards to discard pile
		H.deckCount[j] -= noOfCardsBeforeTreasure; //subtract the non treasure cards from deck
		
		
		if(PRINT_ON)
		{
			printf("number of cards drawn before two treasures: %d\n",noOfCardsBeforeTreasure);
			printf("hand count of player %d before adventurer card: %d\n",j,G.handCount[j]);
			printf("discard count of player %d before adventurer card: %d\n",j,G.discardCount[j]);
			printf("deck count of player %d before adventurer card: %d\n",j,G.deckCount[j]);
		}
		
		//playAdventurer(drawntreasure, &G,j,&cardDrawn,tempHand,z);
		
		adventurerEffect(&G,j,&drawntreasure,tempHand,z);
		
		if(PRINT_ON)
		{
			printf("hand count of player %d after adventurer card: %d\n",j,G.handCount[j]);
			printf("discard count of player %d after adventurer card: %d\n",j,G.discardCount[j]);
			printf("deck count of player %d after adventurer card: %d\n",j,G.deckCount[j]);
		}
	}
	
	for(j = 0; j < numPlayer; j++)
	{
		assert(H.handCount[j] == G.handCount[j]);
		printf("HANDCOUNT TEST PASSED\n");
	}
	

	
	/*for(j = 0; j < numPlayer; j++)
	{
		assert(H.deckCount[j] == G.deckCount[j]);
		printf("DECKCOUNT TEST PASSED\n");
	}*/
	
	
	

    printf("All tests passed!\n");

    return 0;
}