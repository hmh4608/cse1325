#include <iostream>
#include <fstream> //for file reading and defines ofstream ifstream and fstream data types
#include <string>
#include <climits>
#include <vector>
#include "coin.h"

//function prototypes for menu
void addCoin(std::vector<Coin>& coins);
void listCoins(const std::vector<Coin>& coins);
void delCoin(std::vector<Coin>& coins);
void saveCoins(std::vector<Coin>& coins, std::string& file_name);
void openCoins(std::vector<Coin>& coins, std::string& file_name);

int main()
{
	try
	{
		char choice; //user's menu selection
		std::vector<Coin> pouch;
		std::string file_name = ""; //for storing most recently opened/saved file name

		do
		{	
			//menu outputs
			std::cout << "===================\nCSE1325 COINS\n===================\n"
			<< "(A)dd a coin\n"
			<< "(L)ist all coins\n"
			<< "(D)elete a coin\n\n"
			<< "(Q)uit\n\n"
			<< "(S)ave all coins\n"
			<< "(O)pen coin file\n\n"
			<< std::to_string(pouch.size()) + " coins >> ";
		
			std::cin >> choice;

			//run based on selection
			switch(choice)
			{
				case 'A' : case 'a' : addCoin(pouch); break;
				case 'L' : case 'l' : listCoins(pouch); break;
				case 'D' : case 'd' : delCoin(pouch); break;
				case 'S' : case 's' : saveCoins(pouch, file_name); break;
				case 'O' : case 'o' : openCoins(pouch, file_name); break;
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
/*
*asks the user for the file name to save coins, if user only presses enter then use most recently opened or saved file name (or untitled.coins if first save)
*/
void saveCoins(std::vector<Coin>& coins, std::string& file_name)
{
	std::ofstream out_file; //represents output file stream for creating files and writing info to files

	std::string new_file;
	//ask the user for file name
	std::cout << "Enter a name for the .coin file: ";
	std::cin.ignore();	
	std::getline(std::cin, new_file);
	//checks if user just hits enter
	if(file_name == "" && new_file == "") //if this is the first save
	{
		file_name = new_file = "untitled.coin";
	}
	else if(file_name != "" && new_file == "") //if there is already a recently saved file and user only presses enter
	{
		new_file = file_name;
	}
	else //checks if user already typed in .coin at the end
	{
		//npos tells if find() found anything
		if(new_file.find(".coin") == std::string::npos) //if not found
			new_file += ".coin";
	}
	
	//open the file for writing
	out_file.open(new_file);
	//check if file was opened/created successfully
	if(!out_file)
	{
		throw std::runtime_error{"Failed to create file"};
		return;
	}

	//write to the file
	for(int i=0; i<coins.size(); ++i)
	{
		out_file << coins.at(i) << std::endl;
	}

	out_file.close(); //close file

	file_name = new_file; //updates the most recently saved file
}
/*
*Asks user for the filename to open. if user just hits enter, abort open
*otherwise open specified filename, clear coins vector, stream coins from file into vector
*/
void openCoins(std::vector<Coin>& coins, std::string& file_name)
{
	std::ifstream infile; //represents input file stream for reading info in from files
	std::string open_file = "";
	
	//asks user for filename to open
	std::cout << "Enter the name for the .coin file to open: ";
	std::cin.ignore();
	std::getline(std::cin,open_file);

	//checks if the user just hits enter
	if(open_file == "")
	{
		return; //abort the open
	}
	else
	{
		//checks if user already typed .coin at the end
		if(open_file.find(".coin") == std::string::npos) //if not found
			open_file += ".coin";
	}

	//open the file
	infile.open(open_file);
	//check if successful
	if(!infile)
	{
		throw std::runtime_error("Failed to open file");
		return;
	}

	//clear the coins vector
	coins.clear();

	//stream coins from file into vector
	Coin coin;
	while(infile >> coin)
	{
		coins.push_back(coin);
	}

	infile.close();

	//copy open_file to file_name to set the new recently opened file
	file_name = open_file;
}
