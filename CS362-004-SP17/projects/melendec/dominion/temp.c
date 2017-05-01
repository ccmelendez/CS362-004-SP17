
					
					
					
					
					
					
					
					
for(a = 0; a < 6; a++)
				{
					for(b = 0; b < 6; b++)
					{
						for(c = 0; c < 6; c++)
						{
							for(x = 0; x < handCount ; x++)
							{
								G->hand[p][x] = scoreCards[scoreCardCounter+c];
							}
							d++;
							for(y = 0; y < discardCount; y++)
							{
								G->discard[p][y] = scoreCards[scoreCardCounter+b];
							}
							e++;
							for(z = 0; z < discardCount; z++)
							{	
								G->deck[p][z] = scoreCards[scoreCardCounter+a];
							}
							f++;
						}
					}
				}
				
			}
		}
    }
	int a = 0; 
	int b = 0; 
	int c = 0; 
	int d = 0; 
	int e = 0; 
	int f = 0;
	int increase;
	while( a < 6 && b < 6 && c < 6 && d < 6 && e < 6 && f < 6)
	{
		for(x = 0; x < handCount ; x++)
		{
			G->hand[p][x] = scoreCards[scoreCardCounter+a];
		}
		for(y = 0; y < discardCount; y++)
		{
			G->discard[p][y] = scoreCards[scoreCardCounter+b];
		}
		for(z = 0; z < discardCount; z++)
		{	
			G->deck[p][z] = scoreCards[scoreCardCounter+c];
		}
		
	}
	
	
	
	
	
	
/*********************************************/
	
for(i = 0; i < maxHandCount; i++)
	{
		//setup player hand cards
		G.hand[0][i] = scoreCards[i%6];
		scoreCardsValues[5] = fullDeckCount(0,0,&G)/10;
		printf("fullDeckCount: %d\n", scoreCardsValues[5]);
	}
	
	for(i = 0; i < maxHandCount; i++)
	{
		testScore += scoreCardsValues[i%6];
		scoreCardsValues[5] = fullDeckCount(0,0,&G)/10;
		printf("fullDeckCount: %d\n", scoreCardsValues[5]);
	}
	scoreForValue = scoreFor(0,&G);
	printf("testScore: %d | score: %d\n", testScore, scoreForValue);
	assert(testScore == scoreForValue);
	

	for(i = 0; i < maxDiscardCount; i++)
	{
		//setup player discard cards
		G.discard[0][i] = scoreCards[i%6];
	}
	scoreCardsValues[5] = fullDeckCount(0,0,&G);
	for(i = 0; i < maxDiscardCount; i++)
	{
		testScore += scoreCardsValues[i%6];
	}
	scoreForValue += scoreFor(0,&G);
	printf("testScore: %d | score: %d\n", testScore, scoreForValue);
	assert(testScore == scoreForValue);

	
	
	for(i = 0; i < maxDeckCount; i++)
	{
		//setup player deck cards
		G.deck[0][i] = scoreCards[i%6];
	}
	scoreCardsValues[5] = fullDeckCount(0,0,&G);
	for(i = 0; i < maxDeckCount; i++)
	{
		testScore += scoreCardsValues[i%6];
	}
	scoreForValue += scoreFor(0,&G);
	printf("testScore: %d | score: %d\n", testScore, scoreForValue);
	assert(testScore == scoreForValue);
	