#include <iostream>
#include <string>
#include "color.h"

int main()
{
	//instantiate 3 Color objects
	Color red{255, 0, 0};
	Color pink{255, 167, 167};
	Color lime{211, 255, 167};

	//prints the three colors in their representative color
	std::cout << red.colorize("Red") + " " + pink.colorize("Blush Pink") + " " + lime.colorize("Lime Green") << '\n' << std::endl;

	//asks user for 3 integers representing red, green, and blue
	int r, g, b;

	std::cout << "Enter the RGB values separated by a space: ";
	std::cin >> r;
	std::cin >> g;
	std::cin >> b;
	
	//instantiate user-entered RGB color
	Color color{r, g, b};

	//prints the user-entered color's string representation in its representative color
	std::cout << color.colorize(color.to_string()) << std::endl;

	return 0;
}
