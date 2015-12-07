#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH(x) (sizeof(x)/sizeof(*(x)))
#define MAX 1000000

int main(int argc, char const *argv[])
{
	char *gameList[] = {"Mass Effect", "FFX", "Tales of Symphonia"};
	int gameCounter[] = {0,0,0,0,0,0,};
	int gamePick[] = {0,0,0,0,0,0,};
	int tieArray[6];
	int value, index, max, flag, counter, tie;

	flag = 0;
	srand(time(NULL));

	while(flag == 0){

		value = index = max = 0;

		for (int i = 0; i < LENGTH(gamePick); ++i){
			if(gamePick[i] == 10){
				printf("Game to play is %s\n",gameList[i]);
				flag = 1;
				break;
			}
		}

		if (flag == 1)
			continue;

		for (int i = 0; i < 200; ++i){
			for (int j = 0; j < MAX; ++j){
				value = rand() % LENGTH(gameList);
			}

			gameCounter[value]++;
		}

		for (int i = 0; i < LENGTH(gameCounter); ++i){
			if(gameCounter[i] == max){
				tie = 1;
				counter++;
				tieArray[counter] = i;
			}
			else if(gameCounter[i] > max){
				counter = tie = 0;
				max = gameCounter[i];
				tieArray[counter] = i;
				index = i;
			}
		}

		if(tie == 1){
			for (int i = 0; i < MAX; ++i){
				value = rand() % (counter + 1);
			}
			index = tieArray[value];
			gamePick[index]++;
		}
		else
			gamePick[index]++;

		for (int i = 0; i < LENGTH(gameList); ++i){
			printf("%s %d/10\n",gameList[i], gamePick[i]);
		}

		for (int i = 0; i < LENGTH(gameCounter); ++i){
			gameCounter[i] = 0;
		}

		printf("--------------------------------\n");
	}
	
	return 0;
}