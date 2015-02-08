#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define START_MONEY 10
#define WATER_PRICE 0.25
#define SUGAR_PRICE 0.50
#define LEMON_PRICE 0.75
#define CUP_PRICE 0.10

void displayTitle();
int getDays();
int displayStatus(float m, int w, int s, int l, int c, float p);
void purchase(float *money, int *w, int *s, int *l, int *c, float *p);
void sellLemonade(int *days, float *money, int *w, int *s, int *l, int *c, float *p);
int pickPersonality();


int main(void){
	int days = 1;
	int water = 0;
	int sugar = 0;
	int lemons = 0;
	int cups = 0;
	float price = 0;
	float money = START_MONEY;
	
	int character = pickPersonality();

	int daysToPlay = getDays();

	while (days <= daysToPlay){
		int result = displayStatus(money, water, sugar, lemons, cups, price);

		if (result == 1)
			purchase(&money, &water, &sugar, &lemons, &cups, &price);
		else if (result == 2)
			sellLemonade(&days, &money, &water, &sugar, &lemons, &cups, &price);

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

int getDays() {
	
	int result;
	
	printf("Before you start buying supplies and selling lemonade... How many days are left in your summer? ");

	fscanf(stdin, "%d", &result);

	return result;	
}

int displayStatus(float money, int water, int sugar, int lemons, int cups, float price){
	int result;
	printf("\n  ___                _ _\n");
	printf(" / __|_  _ _ __ _ __| (_)___ ___\n");
	printf(" \\__ \\ || | '_ \\ '_ \\ | / -_|_-<\n");
	printf(" |___/\\_,_| .__/ .__/_|_\\___/__/\n");
	printf("          |_|  |_|\n\n");
	printf("You have $%.2f in your pocket...\nYou currently have:\n%d Water\n%d Sugar\n%d Lemons\n%d Cups\n\n", money, water, sugar, lemons, cups);
	printf("What would you like to do? (enter only a number to proceed)\n1. Purchase supplies\n2. Start selling lemonade\n");

	fscanf(stdin, "%d", &result);

	return result;
}

void purchase(float *money, int *water, int *sugar, int *lemons, int *cups, float *price){

	for(;;){
		printf("\nEnter the respective number to purchase water, sugar, lemons (-1 to exit the store) \n\nPRICES\n1. Water: $%.2f\n2. Sugar: $%.2f\n3. Lemons: $%.2f\n4. Cups: $%.2f\nYour Money: $%.2f\n", WATER_PRICE, SUGAR_PRICE, LEMON_PRICE, CUP_PRICE, *money);
		printf("\nCURRENT STOCK:\n%d Water\n%d Sugar\n%d Lemons\n%d Cups\n\n", *water, *sugar, *lemons, *cups);

		int choice;
		fscanf(stdin, "%d", &choice);

		int result;

		if (choice == 1){
			printf("Enter the amount of water you would like to buy: ");
			fscanf(stdin, "%d", &result);
			*water += result;

			*money -= (result * WATER_PRICE);

		}
		else if (choice == 2){
			printf("Enter the amount of sugar you would like to buy: ");
			fscanf(stdin, "%d", &result);
			*sugar += result;

			*money -= (result * SUGAR_PRICE);

		}
		else if (choice == 3){
			printf("Enter the amount of lemons you would like to buy: ");
			fscanf(stdin, "%d", &result);
			*lemons += result;

			*money -= (result * LEMON_PRICE);

		}
		else if (choice == 4){
			printf("Enter the amount of cups you would like to buy: ");
			fscanf(stdin, "%d", &result);
			*cups += result;

			*money -= (result * CUP_PRICE);
		}
		else if (choice == -1){
			break;
		}

		if (*money < 0)
			*money = 0;
	}

	printf("\nYou are done purchasing stock\n");
	
		float price;
	
	printf("Would you like to change your prices?\n1. Yes\n2. No\n");
	fscanf(stdin, "%d", &result);
	
	if(result == 1){
		price = setPrice();
	}
}

float setPrice(){
	float result;	
	printf("How much will each cup cost?\n");
	fscanf(stdin, "%f", &result);
	
	while(result <= 0){
		printf("You need to set your price to a positive number.");
		printf("How much will each cup cost?\n");
		fscanf(stdin, "%f", &result);
	}
	
	return result;
}

void sellLemonade(int *days, float *money, int *water, int *sugar, int *lemons, int *cups, float *price){
	srand(time(NULL));
	int rndWater = rand() % *water;
	int rndSugar = rand() % *sugar;
	int rndLemons = rand() % *lemons;
	int rndCups = rand() % *cups;


	*water -= rndWater;
	*sugar -= rndSugar;
	*lemons -= rndLemons;
	*cups -= rndCups;

	int rndSales = rand() % 20;
	
	printf(" ___       _ _        ___                   _\n");
	printf("|   \\ __ _(_) |_  _  | _ \\___ _ __  ___ _ _| |_\n");
	printf("| |) / _` | | | || | |   / -_) '_ \\/ _ \\ '_|  _|\n");
	printf("|___/\\__,_|_|_|\\_, | |_|_\\___| .__/\\___/_|  \\__|\n");
	printf("               |__/          |_|\n\n");
	
	if(rndSales < 7){
		printf("DAY %d: Today you had a slow day with only %d sales.\n", *days, rndSales);
	}
	else if(rndSales < 14){
		printf("DAY %d: Today was an average day with %d sales.\n", *days, rndSales);
	}
	else{
		printf("DAY %d: Today was a busy day with %d sales!\n", *days, rndSales);
	}
	
	int rndMoney = rand() % 50;
	*money += rndMoney;
	*days += 1;
}

void disaster (int *person, int *days, float *money, int *water, int *sugar, int *lemons, int *cups){
	int chance = rand % 100;
	if (chance < floor(*days/2))
		int event = (rand % 6) + 1
	
	if (event == 0){
		// Very Good Event
	elif (event == 1){
		// Good Event
	elif (event == 2){
		// Ok Event
	elif (event == 3){
		// Neutral
	elif (event == 4){
		// Bad Event
	elif (event == 5){
		// Really Bad Event
	elif (event == 6){
		// Oh Lord :(
}

int pickPersonality() {

	printf("BEEP BEEP BEEP\n\n");
	sleep(1);
	printf("BEEP BEEP BEEP\n\n");
	sleep(1);
	printf("BEEP BEEP BEEP\n\n");
	sleep(1);
	printf("BEEP BEEP BEEP\n\n");
	sleep(1);
	printf("** SMASH **\n\n");
	sleep(2);
	printf("It's 7AM, and you just broke your alarm clock... Oops.\n\n");
	sleep(1);
	printf("Time to start the day!\n\n");
	sleep(1);
	printf("Wait... Who are you?\n\n");
	sleep(2);
	printf("************ Character Select ************\n");
	printf("1: Bobby\n ~ He's a great guy.\n ~ Most would say he's the strong silent type.\n ~ Nothing bad ever happens when Bobby is around.\n\n");
	printf("2: Raniem\n ~ She's flawless.\n ~ Most would say she's a charmer.\n ~ Everyone loves buying Raniem's Lemonade.\n\n");
	printf("3: Alex\n ~ He can 'lick his elbow'... Not actually.\n ~ He has connections at the supermarket... If you know what I'm sayin'.\n\n");
	printf("4: Josh\n ~ He's Josh.\n ~ Nothing to see here.\n\n");
	printf("5: Rhys\n ~ Biggest beauty on campus.\n ~ Everyone loves Rhys.\n\n");
	printf("6: Zac\n ~ Likes to use his words.\n ~ Fights crimes on occasion.\n ~ Billionaire, philanthropist, playboy. He's Batman.\n\n");

	printf("Enter the number of the character that you would like to play as: ");

	int result;
	fscanf(stdin, "%d", &result);

	if (result == 4) {
		printf("\nYou picked Josh... Seriously?\nYou start with less money if you play as Josh.\nGood choice!\n\n");
		sleep(1);
		printf("Here we go...\n\n");
	}

	else if (result == 6) {
		printf("\nIt's summer break and you're looking to make some cash...\n\n");
		sleep(1);
		printf("You've noticed that your mother has left her purse out... Again.\n\n");
		sleep(1);
		printf("There's a 20 dollar bill sitting there with your name on it.\n\n");
		sleep(1);	
		printf("You swipe it up and thus... A business was born...\n\n");
		sleep(1);
		printf("A man was born...\n\n");
		sleep(1);
		printf("He's the lemonade guy that Queen's deserves, but not the one it needs right now.\n");
		printf("So we'll buy from him.\nBecause he can take it.\nBecause he's not our lemonade guy.\n");
		printf("He's a citrus fruit guardian, a watchful mixer.\nA lemonade guy.\n\n");
		sleep(5);
		printf("...\n\n");
	}
	else {
		printf("\nIt's summer break and you're looking to make some cash...\n\n");
		sleep(1);
		printf("You've noticed that your mother has left her purse out... Again.\n\n");
		sleep(1);
		printf("There's a 10 dollar bill sitting there with your name on it.\n\n");
		sleep(1);	
		printf("You swipe it up and thus... A business was born...\n\n");
		sleep(1);
		printf("...\n\n");
	}

	sleep(3);
	displayTitle();
	sleep(3);

	return result;
}
