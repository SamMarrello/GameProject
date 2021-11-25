#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;


//setting up game, giving orders

void refresh_gamestate(int& acres, int& population, int& year, int& bushels, int& land_cost) {
	acres = 1000;
	population = 100;
	year = 1;
	bushels = 2800;
	land_cost = 1;
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
		 << "Our granaries hold " << bushels << " bushels of grain \n";
}

void orders(int& planted_acres, int& food, int& bushels, string& user_input,int& land_cost, int& land_purchase) {
	cout << "Do you want to restart the game? If so, type 'restart'" << endl;
	cin >> user_input;
	cout << "How many acres shall we plant this year?" << endl;
	cin >> planted_acres;
	cout << "How many bushels shall we budget to feed our people?" << endl;
	cin >> food;
	cout << "The Dinar per acre for this year is " << land_cost << endl;
	cout << "Should we purchase more fields to grow our city? Put the number of acres you want to buy below" << endl;
	cin >> land_purchase;
}
//pop growth and under the hood functions

float pop_growth(int population, int food, int migrants) {
	if (food / population < 20) {
		return food / 20.0;
	}
	population = population * 1.05;
	migrants = rand() % 100;
	population = migrants + population;
	return population;
}

float planting(int food, int planted_acres, int bushels) {
	bushels = bushels - planted_acres;
	bushels = planted_acres * 3;
	return bushels;
}

void end_turn(int& year, int& population, int& bushels, int food, int migrants, int planted_acres, int acres, string st, int land_cost, int land_purchase) {
	cout << "entering the year " << year << endl;
	year++;
	bushels = bushels - food;
	population = pop_growth(population, food, migrants);
	bushels = planting(bushels, planted_acres, bushels);
	land_cost = rand() % 5;
	acres += land_purchase;
	current_gamestate(acres, population, year, bushels, st);
}

//main game turn, calculating everything you did over the year

int main() {
	/*my take on the popular game Hammurabi. Basically, you play for 10 years, each turn being a year.
	* Each citizen eats 20 bushels of grain a year
	* A bushel can be used either as food, to plant a field for the next year, or to buy and sell land
	* land can be bought at year start. You don't have to plant or use all your food, but still
	* Random events can negatively or positively add to your harvest
	* If all your citizens die, you lose. If more than 25% of your citizens starve, they'll kick you out
	*/

	//housekeeping, init variables 
	int acres, population, year = 0, bushels, food, planted_acres, land_purchase, migrants = 0, pop_increase, pop_decline, land_cost, win = 0, loss = 0;
	string user_input, st;

	//beginning values & functions

	refresh_gamestate(acres, population, year, bushels, land_cost);

	// begining of main game

	cout << "Welcome to Sam's Hammurabi! \n";

	while (year <= 10)
	{
		current_gamestate(acres, population, year, bushels, st);
		orders(planted_acres, food, bushels, user_input, land_cost, land_purchase);
		end_turn(year, population, bushels, food, migrants, planted_acres, acres, st, land_cost, land_purchase);
	
		if (user_input == "restart" || user_input == "Restart")
		{
			refresh_gamestate(acres, population, year, bushels, land_cost);
			current_gamestate(acres, population, year, bushels, st);
			orders(planted_acres, food, bushels, user_input, land_cost, land_purchase);
		}

		if (population <= 50)
		{
			break;
		}
	}
	
	if (year == 10 && population != 0)
	{
		cout << "Success! You have finished your governorship without incident" << endl;
		win++;
	}
	else if (population == 50)
	{
		cout << "Failure! Your people have thrown you out due to your sheer incompetence" << endl;
		loss++;
	}
	else if (population == 0)
	{
		cout << "Failure! Your name will go down in history as the biggest goof of Mesopotamia!" << endl;
		loss++;
	}

}