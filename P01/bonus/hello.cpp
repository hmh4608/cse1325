#include <string>
#include <iostream>

int main()
{
	//declare string var
	std::string name;
	
	//ask user for input	
	std::cout << "Please enter your name (including spaces): ";
	//cin reads whitespace-separated word
		
	std::cin >> name;
	
	std::cout << "Hello, " << name << std::endl;

	return 0;
}
