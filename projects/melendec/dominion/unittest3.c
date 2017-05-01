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

    printf ("TESTING getCost():\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	
	int allCards[27] = 
	{
		curse, //0
		estate, //1
		duchy, //2
		province, //3
		copper, //4
		silver, //5 
		gold, //6
		adventurer, //7
		council_room, //8
		feast, //9
		gardens, //10
		mine, //11
		remodel, //12
		smithy, //13
		village, //14
		baron, //15
		great_hall, //16 
		minion, //17
		steward, //18
		tribute, //19
		ambassador, //20
		cutpurse, //21
		embargo, //22
		outpost, //23
		salvager, //24
		sea_hag, //25
		treasure_map //26
	};
	
	assert(getCost(allCards[0]) == 0); //curse
	assert(getCost(allCards[1]) == 2); //estate
	assert(getCost(allCards[2]) == 5); //duchy
	assert(getCost(allCards[3]) == 8); //province
	assert(getCost(allCards[4]) == 0); //copper
	assert(getCost(allCards[5]) == 3); //silver
	assert(getCost(allCards[6]) == 6); //gold
	assert(getCost(allCards[7]) == 6); //adventurer
	assert(getCost(allCards[8]) == 5); //council_room
	assert(getCost(allCards[9]) == 4); //feast
	assert(getCost(allCards[10]) == 4); //gardens
	assert(getCost(allCards[11]) == 5); //mine
	assert(getCost(allCards[12]) == 4); //remodel
	assert(getCost(allCards[13]) == 4); //smithy
	assert(getCost(allCards[14]) == 3); //village
	assert(getCost(allCards[15]) == 4); //baron
	assert(getCost(allCards[16]) == 3); //great_hall
	assert(getCost(allCards[17]) == 5); //minion
	assert(getCost(allCards[18]) == 3); //steward
	assert(getCost(allCards[19]) == 5); //tribute
	assert(getCost(allCards[20]) == 3); //ambassador
	assert(getCost(allCards[21]) == 4); //cutpurse
	assert(getCost(allCards[22]) == 2); //embargo
	assert(getCost(allCards[23]) == 5); //outpost
	assert(getCost(allCards[24]) == 4); //salvager
	assert(getCost(allCards[25]) == 4); //sea_hag
	assert(getCost(allCards[26]) == 4); //treasure_map


	
	

    printf("All tests passed!\n");

    return 0;
}