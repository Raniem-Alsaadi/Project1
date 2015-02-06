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
	printf("                                                                        ,,\n");
	printf("`7MMF'                                                                `7MM\n");
	printf("  MM                                                                    MM\n");
	printf("  MM         .gP\"Ya `7MMpMMMb.pMMMb.  ,pW\"Wq.`7MMpMMMb.   ,6\"Yb.   ,M\"\"bMM  .gP\"Ya\n");
	printf("  MM        ,M'   Yb  MM    MM    MM 6W'   `Wb MM    MM  8)   MM ,AP    MM ,M'   Yb\n");
	printf("  MM      , 8M\"\"\"\"\"\"  MM    MM    MM 8M     M8 MM    MM   ,pm9MM 8MI    MM 8M\"\"\"\"\"\"\n");
	printf("  MM     ,M YM.    ,  MM    MM    MM YA.   ,A9 MM    MM  8M   MM `Mb    MM YM.    ,\n");
	printf(".JMMmmmmMMM  `Mbmmd'.JMML  JMML  JMML.`Ybmd9'.JMML  JMML.`Moo9^Yo.`Wbmd\"MML.`Mbmmd' \n\n");
	printf("MMP\"\"MM\"\"YMM\n");
	printf("P'   MM   `7\n");
	printf("     MM `7M'   `MF',p6\"bo   ,pW\"Wq.   ,pW\"Wq.`7MMpMMMb.\n");
	printf("     MM   VA   ,V 6M'  OO  6W'   `Wb 6W'   `Wb MM    MM\n");
	printf("     MM    VA ,V  8M       8M     M8 8M     M8 MM    MM\n");
	printf("     MM     VVV   YM.    , YA.   ,A9 YA.   ,A9 MM    MM\n");
	printf("   .JMML.   ,V     YMbmd'   `Ybmd9'   `Ybmd9'.JMML  JMML.\n");
	printf("           ,V\n");
	printf("        OOb\"    \n\n");
}

int displayStatus(float money, int water, int sugar, int lemons){
	int result;
	printf("\n  ___                _ _\n");
	printf(" / __|_  _ _ __ _ __| (_)___ ___\n");
	printf(" \\__ \\ || | '_ \\ '_ \\ | / -_|_-<\n");
	printf(" |___/\\_,_| .__/ .__/_|_\\___/__/\n");
	printf("          |_|  |_|\n\n");
	printf("You have $%.2f in your pocket...\nYou currently have:\n%d Water\n%d Sugar\n%d Lemons\n\n", money, water, sugar, lemons);
	printf("What would you like to do? (enter only a number to proceed)\n1. Purchase supplies\n2. Start selling lemonade\n");

	fscanf(stdin, "%d", &result);

	return result;
}

void purchase(float *money, int *water, int *sugar, int *lemons){

	for(;;){
		printf("\nEnter the respective number to purchase water, sugar, lemons (-1 to exit) \n\nPRICES\n1. Water: $%.2f\n2. Sugar: $%.2f\n3. Lemons: $%.2f\nYour Money: $%.2f\n", WATER_PRICE, SUGAR_PRICE, LEMON_PRICE, *money);
		printf("\nCURRENT STOCK:\n%d Water\n%d Sugar\n%d Lemons\n\n", *water, *sugar, *lemons);

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
			printf("Enter the amount of sugar: ");
			fscanf(stdin, "%d", &result);
			*sugar += result;

			*money -= (result * SUGAR_PRICE);

		}
		else if (choice == 3){
			printf("Enter the amount of lemons: ");
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

// We need some way of preventing people from selling lemonade if they have 0 supplies because otherwise is segfaults!

void sellLemonade(int *days, float *money, int *water, int *sugar, int *lemons){
	srand(time(NULL));
	int rndWater = rand() % *water;
	int rndSugar = rand() % *sugar;
	int rndLemons = rand() % *lemons;

	*water -= rndWater;
	*sugar -= rndSugar;
	*lemons -= rndLemons;

	int rndSales = rand() % 20;
	
	printf(" ___       _ _        ___                   _\n");
	printf("|   \\ __ _(_) |_  _  | _ \\___ _ __  ___ _ _| |_\n");
	printf("| |) / _` | | | || | |   / -_) '_ \\/ _ \\ '_|  _|\n");
	printf("|___/\\__,_|_|_|\\_, | |_|_\\___| .__/\\___/_|  \\__|\n");
	printf("               |__/          |_|\n\n");
	
	printf("DAY %d: You made %d sales today!\n", *days, rndSales);
	int rndMoney = rand() % 50;
	*money += rndMoney;
	*days += 1;
}


