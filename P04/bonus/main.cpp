#include <iostream>
#include <string>
#include <climits>
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
			std::cout << "===================\nCSE1325 COINS\n===================\n"
			<< "(A)dd a coin\n"
			<< "(L)ist all coins\n"
			<< "(D)elete a coin\n\n"
			<< "(Q)uit\n\n"
			<< std::to_string(pouch.size()) + " coins >> ";
		
			std::cin >> choice;

			//run based on selection
			switch(choice)
			{
				case 'A' : case 'a' : addCoin(pouch); break;
				case 'L' : case 'l' : listCoins(pouch); break;
				case 'D' : case 'd' : delCoin(pouch); break;
				case 'Q' : case 'q' : std::cout << "Thank you for using my Coin System!\n"; if(choice == 'Q') choice = 'q'; break;
				default : throw std::runtime_error{"Invalid input"}; break;
			}
		}while(choice != 'q');
	}
	catch(std::runtime_error e)
	{
		std::cerr << e.what() << std::endl;
		return -1;
	}
	return 0;
}

//functions to do menu things
/*
*uses Coin's operator>>, asks user for input, and pushes it back to the vector
*/
void addCoin(std::vector<Coin>& coins)
{
	Coin coin;
	std::cout << "Coin (year size \\n notes): ";
	std::cin >> coin;
	coins.push_back(coin);
	std::cout << std::endl;
}
/*
*lists each coin's vector [index] and output the coin's operator<<
*notes may be multiline
*/
void listCoins(const std::vector<Coin>& coins)
{
	if(coins.size() == 0)
	{	
		std::cout << "\nThere are no coins in the pouch." << std::endl;
	}	
	else
	{
		std::cout << "\n\nooooooooooooooooooo\nC O I N  P O U C H\nooooooooooooooooooo" << std::endl;
		//loop to print out all the coins
		for(int i=0; i<coins.size(); ++i)
		{
			//.at(i) will throw out of range exception if index isn't right'		
			std::cout << "[" << i << "] " << coins.at(i) << "\n" << std::endl;
		}
	}
}
/*
*asks for the index number of the coin to delete and erases it
*/
void delCoin(std::vector<Coin>& coins)
{
	if(coins.size() == 0)
	{	
		std::cout << "\nThere are no coins in the pouch." << std::endl;
		return;
	}	

	int target;	
	std::cout << "Enter the index number of the coin you would like to delete: ";
	std::cin >> target;
	//check if its an integer
	if(!(target>=INT_MIN) && !(target<=INT_MAX))
		throw std::out_of_range{"Not within bounds"};
	else
		coins.erase(coins.begin() + target); //delete coin at specified index
	std::cout << "Coin at index [" << target << "] deleted!" << std::endl;
}
