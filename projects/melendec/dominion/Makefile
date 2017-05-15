CFLAGS = -Wall -fpic -coverage -lm -std=c99.

randomtestresults.out: randomtestadventurer.c randomtestcard1.c randomtestcard2.c dominion.c rngs.c	
	echo "results from random tests:" > randomtestresults.out
	
	echo "randomtestadventurer.c: " >> randomtestresults.out
	gcc -o randomtestadventurer randomtestadventurer.c dominion.c rngs.c  -Wall -fpic -coverage -lm -std=c99
	randomtestadventurer >> randomtestresults.out
	gcov -b -f dominion.c >> randomtestresults.out
	
	
	echo "randomtestcard1.c: " >> randomtestresults.out
	gcc -o randomtestcard1 randomtestcard1.c dominion.c rngs.c -Wall -fpic -coverage -lm -std=c99
	randomtestcard1 >> randomtestresults.out
	gcov -b -f dominion.c >> randomtestresults.out
	
	echo "randomtestcard2.c: " >> randomtestresults.out
	gcc -o randomtestcard2 randomtestcard2.c dominion.c rngs.c -Wall -fpic -coverage -lm -std=c99
	randomtestcard2 >> randomtestresults.out
	gcov -b -f dominion.c >> randomtestresults.out