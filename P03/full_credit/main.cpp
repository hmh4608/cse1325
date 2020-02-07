#include <iostream>
#include <string>
#include "color.h"

int main()
{
	//instantiate 3 Color objects
	Color red{255, 0, 0};
	Color pink{255, 167, 167};
	Color lime{211, 255, 167};

	//prints the three colors in their representative color using << operator we overloaded
	std::cout << red << "Basic Red" << pink << " Blush Pink" << lime << " Lime Green" << Color{} << std::endl;
	//woah it's so short now

	//asks user for 3 integers representing red, green, and blue
	Color color;
	std::cout << "Enter the color as (red, green, blue): ";
	std::cin >> color;
	//prints the user-entered color's string representation in its representative color
	std::cout << color << color.to_string() << Color{} << std::endl;

	return 0;
}
