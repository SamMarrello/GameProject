#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;


//setting up game, giving orders

void refresh_gamestate(int& acres, int& population, int& year, int& bushels) {
	acres = 1000;
	population = 100;
	year = 1;
	bushels = 2800;
}

void current_gamestate(int& acres, int& population, int& year, int& bushels, string& st){

	if (year == 1)
	{
		st = "st";
	}
	else if (year == 2)
	{
		st = "nd";
	}
	else if (year == 3)
	{
		st = "rd";
	}
	else
	{
		st = "th";
	}
	
	cout << "It is the " << year << st << " year of your reign, noble king!\n"
		 << "Our city currently has " << acres << " acres available for cultivation \n"
		 << "We count " << population << " citizens \n"
		 << "Our granaries hold " << bushels << " bushels of grain";
}

void orders(int& planted_acres, int& food, int& bushels, string& user_input, int& land_purchase) {
	cout << "Do you want to restart the game? If so, type 'restart'" << endl;
	cin >> user_input;
	cout << "How many acres shall we plant this year?" << endl;
	cin >> planted_acres;
	cout << "How many bushels shall we budget to feed our people?" << endl;
	cin >> food;
	cout << "Should we purchase more fields to grow our city? Put the number of acres you want to buy below" << endl;
	cin >> land_purchase;
}
//population functions

int migration(int migrants) {
	migrants = rand() % 100;
	return migrants;
}

int pop_growth(int population, int migrants) {
	population = population * 1.05;
	migrants = migration(migrants);
	population = migrants + population;
	return population;
}

//food and starvation

int starvation(int population, int food) {
	if (food / population < 20) {
		while (food / population < 20)
			population = population =- ;
		cout << "Your population has starved, my lord!";
}

float year_end(int population, int food, int bushels, int land_purchase, int planted_acres, int year); {
	year = year += ;
}


	int main();
	{
		/*my take on the popular game Hammurabi. Basically, you play for 10 years, each turn being a year.
		* Each citizen eats 20 bushels of grain a year
		* A bushel can be used either as food, to plant a field for the next year, or to buy and sell land
		* land can be bought at year start. You don't have to plant or use all your food, but still
		* Random events can negatively or positively add to your harvest
		* If all your citizens die, you lose. If more than 25% of your citizens starve, they'll kick you out
		*/

		//housekeeping, init variables 
		int acres, population, year, bushels, food, planted_acres, land_purchase, migrants;
		string user_input, st;

		//beginning values & functions

		refresh_gamestate(acres, population, year, bushels);

		// begining of main game

		cout << "Welcome to Sam's Hammurabi! \n";

		while (year <= 10)
		{
			current_gamestate(acres, population, year, bushels, st);
			orders(planted_acres, food, bushels, user_input, land_purchase);



			if (user_input == "restart")
			{
				refresh_gamestate(acres, population, year, bushels);
				orders(planted_acres, food, bushels, user_input, land_purchase);
			}
		}
	}