#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 10
#define START_MONEY 10
#define WATER_PRICE 0.25
#define SUGAR_PRICE 0.50
#define LEMON_PRICE 0.75

void displayTitle();
int displayStatus(float m, int w, int s, int l);
void purchase(float *money, int *w, int *s, int *l);
void sellLemonade(int *days, float *money, int *w, int *s, int *l);

int main(void){
	int days = 1;
	int water = 0;
	int sugar = 0;
	int lemons = 0;
	float money = START_MONEY;

	displayTitle();

	printf("It's summer break and you're looking to make some cash! ");

	while (days < 10){
		int result = displayStatus(money, water, sugar, lemons);

		if (result == 1)
			purchase(&money, &water, &sugar, &lemons);
		else if (result == 2)
			sellLemonade(&days, &money, &water, &sugar, &lemons);

	}

	printf("\nIT'S DAY %d and summer's over! You ended up with $%.2f!\n", days, money); 

	return 0;
}

void displayTitle(){
	printf("+--------------------------------------------------------------------------------------------------------+\n");
	printf("|         ___              ____                   ____    ____      ___   _____                  ____    |\n");
	printf("|  |     |     |\\      /| |    | |\\   |    /\\    |    \\  |         /        |      /\\    |\\   | |    \\   |\n");
	printf("|  |     |____ | \\    / | |    | | \\  |   /  \\   |     | |____     \\___     |     /  \\   | \\  | |     |  |\n");
	printf("|  |     |     |  \\  /  | |    | |  \\ |  /----\\  |     | |             \\    |    /----\\  |  \\ | |     |  |\n");
	printf("|  |____ |____ |   \\/   | |____| |   \\| /      \\ |____/  |____     ____/    |   /      \\ |   \\| |____/   |\n");
	printf("|                                                                                                        |\n");
	printf("+--------------------------------------------------------------------------------------------------------+\n\n");

}

int displayStatus(float money, int water, int sugar, int lemons){
	int result;
	printf("You have $%.2f in your pocket. You currently have:\n%d water\n%d sugar\n%d lemons.\n\n", money, water, sugar, lemons);
	printf("What would you like to do? (enter only a number to proceed)\n1. Purchase supplies\n2. Start selling lemonade\n");

	fscanf(stdin, "%d", &result);

	return result;
}

void purchase(float *money, int *water, int *sugar, int *lemons){

	for(;;){
		printf("Enter the respective number to purchase water, sugar, lemons (-1 to exit) \nPRICES\n1. Water: $%.2f\n2. Sugar: $%.2f\n3. Lemons: $%.2f\nYour Money: $%.2f\n", WATER_PRICE, SUGAR_PRICE, LEMON_PRICE, *money);
		printf("CURRENT STOCK:\n%d water\n%d sugar\n%d lemons.\n\n", *water, *sugar, *lemons);

		int choice;
		fscanf(stdin, "%d", &choice);

		int result;

		if (choice == 1){
			printf("Enter the amount of water: ");
			fscanf(stdin, "%d", &result);
			*water += result;

			*money -= (result * WATER_PRICE);

		}
		else if (choice == 2){
			printf("Enter the amount of water: ");
			fscanf(stdin, "%d", &result);
			*sugar += result;

			*money -= (result * SUGAR_PRICE);

		}
		else if (choice == 3){
			printf("Enter the amount of water: ");
			fscanf(stdin, "%d", &result);
			*lemons += result;

			*money -= (result * LEMON_PRICE);

		}
		else if (choice == -1){
			break;
		}

		if (*money < 0)
			*money = 0;
	}

	printf("\nYou are done purchasing stock\n");

}

void sellLemonade(int *days, float *money, int *water, int *sugar, int *lemons){
	srand(time(NULL));
	int rndWater = rand() % *water;
	int rndSugar = rand() % *sugar;
	int rndLemons = rand() % *lemons;

	*water -= rndWater;
	*sugar -= rndSugar;
	*lemons -= rndLemons;

	int rndSales = rand() % 20;

	printf("DAY %d: You made %d sales today!\n", *days, rndSales);
	int rndMoney = rand() % 50;
	*money += rndMoney;
	*days += 1;
}


