#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


void refresh_gamestate(int& acres, int& population, int& year, int& bushels) {
	acres = 1000;
	population = 100;
	year = 1;
	bushels = 2800;
}

void current_gamestate(int& acres, int& population, int& year, int& bushels){
	cout << "It is the " << year << "st year of your reign, noble king!\n"
		<< "Our city currently has " << acres << " acres available for cultivation \n"
		<< "We count " << population << " citizens \n"
		<< "Our granaries hold " << bushels << " bushels of grain";
}

int orders(int acres, int planted_acres, int food, int bushels) {
	cout << "How many acres shall we plant this year?" << endl;
	cin >> planted_acres;
	cout << "How many bushels shall we budget to feed our people?" << endl;
	cin >> food;

}

int main()
{
	/*my take on the popular game Hammurabi.Basically, you play for 10 years, each turn being a year.
	* Each citizen eats 20 bushels of grain a year 
	* A bushel can be used either as food, to plant a field for the next year, or to buy and sell land
	* land can be bought at year start. You don't have to plant or use all your food, but still
	* Random events can negatively or positively add to your harvest
	* If all your citizens die, 
	*/

	//housekeeping, init variables 

	int acres, population, year, bushels, planted_acres;
	string user_input;
	//beginning values & functions

	refresh_gamestate(acres, population, year, bushels);
	
	// begining of main game



	cout << "Welcome to Kanad's Hammurabi! \n";
	current_gamestate(acres, population, year, bushels);


	if (planted_acres >= acres)
	{
		cout << "Cannot plant more acres than we own!";
		orders();
	}



	if (user_input == "restart")
	{
		refresh_gamestate(acres, population, year, bushels);
	}
		
}