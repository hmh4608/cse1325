#include <iostream>
#include <string>
#include <vector>
#include "coin.h"

//function prototypes for menu
void addCoin(std::vector<Coin>& coins);
void listCoins(const std::vector<Coin>& coins);
void delCoin(std::vector<Coin>& coins);

int main()
{
	try
	{
		char choice; //user's menu selection
		std::vector<Coin> pouch;

		do
		{	
			//menu outputs
			std::cout << "====================\nCSE1325 COINS\n====================\n"
			+ "(A)dd a coin\n"
			+ "(L)ist all coins\n"
			+ "(D)elete a coin\n\n"
			+ "(Q)uit\n\n"
			+ std::to_string(pouch.size()) + " coins >> ";

		std::cin >> choice;

		//run based on selection
		switch(choice)
		{
			case 'A' : case 'a' : addCoin(pouch); break;
			case 'L' : case 'l' : listCoins(pouch); break;
			case 'D' : case 'd' : delCoin(pouch); break;
			case 'Q' : case 'q' : std::cout << "Thank you for using my Coin System!" << std::endl;
			default : throw std::runtime_error{"Invalid input"}; break;
		}

		
		}while(choice != 'Q' || choice != 'q')

		return 0;
	}
	catch(std::runtime_error e)
	{
		std::cerr << e.what() << std::endl;
		return -1;
	}
}

//functions to do menu things
/*
*uses Coin's operator>>, asks user for input, and pushes it back to the vector
*/
void addCoin(std::vector<Coin>& coins)
{
	Coin coin;
	std::cout << "Coin (year size \n notes): ";
	std::cin >> coin;
	coins.push_back(coin);
}
/*
*lists each coin's vector [index] and output the coin's operator<<
*notes may be multiline
*/
void listCoins(const std::vector<Coin>& coins)
{
}
/*
*asks for the index number of the coin to delete and erases it
*/
void delCoin(std::vector<Coin>& coins)
{
}
