#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH(x) (sizeof(x)/sizeof(*(x)))
#define MAX 1000000

int main(int argc, char const *argv[])
{
	char *List[] = {"Mass Effect", "FFX", "Tales of Symphonia"};

	/***make sure array matches the number of items in list***/
	int counter[] = {0,0,0,0,0,0}; 
	int pick[] = {0,0,0,0,0,0};
	int tieArray[6];
	/*******************************************************/

	int value, index, max, flag, counter, tie;

	flag = 0;
	srand(time(NULL));

	while(flag == 0){

		value = index = max = 0;

		for (int i = 0; i < LENGTH(pick); ++i){
			if(pick[i] == 10){
				printf("Game to play is %s\n",List[i]);
				flag = 1;
				break;
			}
		}

		if (flag == 1)
			continue;

		for (int i = 0; i < 200; ++i){
			for (int j = 0; j < MAX; ++j){
				value = rand() % LENGTH(List);
			}

			counter[value]++;
		}

		for (int i = 0; i < LENGTH(counter); ++i){
			if(counter[i] == max){
				tie = 1;
				counter++;
				tieArray[counter] = i;
			}
			else if(counter[i] > max){
				counter = tie = 0;
				max = counter[i];
				tieArray[counter] = i;
				index = i;
			}
		}

		if(tie == 1){
			for (int i = 0; i < MAX; ++i){
				value = rand() % (counter + 1);
			}
			index = tieArray[value];
			pick[index]++;
		}
		else
			pick[index]++;

		for (int i = 0; i < LENGTH(List); ++i){
			printf("%s %d/10\n",List[i], pick[i]);
		}

		for (int i = 0; i < LENGTH(counter); ++i){
			counter[i] = 0;
		}

		printf("--------------------------------\n");
	}
	
	return 0;
}