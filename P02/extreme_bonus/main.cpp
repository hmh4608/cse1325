#include <iostream>
#include <string>
#include "color.h"
#include <vector>

int main()
{
	//instance a vector of Color objects
	std::vector<Color> colors;

	//asks user for 3 integers representing red, green, and blue
	int r, g, b;
	//amount to Color objects to create
	int num;

	std::cout << "How many Color objects would you like to create? ";
	std::cin >> num;

	for(int i=0; i<num; ++i)
	{
		std::cout << "Enter the RGB values separated by a space for Color #" << i+1 << ": ";
		std::cin >> r;
		std::cin >> g;
		std::cin >> b;

		//instantiate user-entered RGB color
		Color color{r, g, b};
		colors.push_back(color);
	}

	Color temp{0,0,0};
	//sorts the vector using compare and bubble sort
	for(int i=0; i<colors.size()-1; ++i)
	{	
		for(int j=0; j<colors.size()-1-i; ++j)
		{
			if(colors[j].compare(colors[j+1]) > 0)
			{
				temp = colors[j+1];
				colors[j+1] = colors[j];
				colors[j] = temp;
			}
		}
	}

	//prints the user-entered color's string representation in its representative color
	for(auto c : colors)
	{
		std::cout << c.colorize(c.to_string()) << std::endl;
	}	

	return 0;
}
