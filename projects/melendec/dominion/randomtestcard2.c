#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkPlayCutpurse(struct gameState *state, int handPos,int currentPlayer)
{
  int r;

  
  r = playCutpurse(state, handPos,currentPlayer);

  assert(r == 0);
}

int main () {

  int i,j,l,m, n, r, deckCount, discardCount, handCount,testHandCount,cutPursePosition, randomPlayer;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState H,G;

  printf ("Testing playSmithy.\n");

  printf ("RUNNING RANDOM TESTS....\n");

  SelectStream(2);
  PutSeed(3);

  for (n = 0; n < 3000; n++) {
    for (i = 0; i < sizeof(struct gameState); i++) {
      ((char*)&G)[i] = floor(Random() * 256);
	  //copy what has been assigned to G to H as well.
    }
	//printf("TEST # %d\n",n);
	G.numPlayers =  ( ( (int)(floor(Random() * 4)) ) + 1) %4;
	//randomize the number of players between 0 and 4
	
	testHandCount = floor(Random() * MAX_HAND);
	//randomize the handcount to give our players, between 0 and MAX_HAND
	
	cutPursePosition = floor(Random() * testHandCount);
	//randomize the position of where smithy will be between 0 and the random number between 0 and MAX_HAND
		
	randomPlayer = floor(Random() * G.numPlayers);
	//pick random player to test on
	
	G.handCount[randomPlayer] = testHandCount;
	G.hand[randomPlayer][cutPursePosition] = smithy;
	//give the player a smithy card and randomize the number of cards in their hand
	
    G.deckCount[randomPlayer] = floor(Random() * MAX_DECK);
    G.discardCount[randomPlayer] = floor(Random() * MAX_DECK -1);
	G.playedCardCount = floor(Random() * MAX_DECK);

	
	//printf("G.numPlayers: %d | testHandCount: %d | cutPursePosition: %d \n", G.numPlayers,testHandCount, smithyPosition);
	//printf("randomPlayer: %d \n",randomPlayer);
	//printf("G.deckCount[%d]:%d | G.discardCount[%d]: %d \n",randomPlayer,G.deckCount[randomPlayer],randomPlayer, G.discardCount[randomPlayer]);
	
	for(j = 0; j < G.numPlayers; j++)
	{
		for(l = 0; l < MAX_DECK; l++)
		{
			int randDiscardIndex = floor(Random() * 13);
			G.discard[j][l] = k[randDiscardIndex];	
			//fill discard pile of players with cards from k[]
		}
		G.handCount[j] = testHandCount;
		for(m = 0; m < testHandCount; m++)
		{
			int randCardIndex = floor(Random() * 13);
			G.hand[j][m] = k[randCardIndex];
			//fill hand of players with cards from k[]
		}
		
	}
	checkPlayCutpurse(&G,cutPursePosition,randomPlayer);

}

  printf ("ALL TESTS OK\n");

  exit(0);
}
