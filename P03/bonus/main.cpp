#include <iostream> //for cin, cout, string
#include <algorithm> //for sort
#include <vector> //for vector and methods push_back, begin, end
#include "color.h"

int main()
{
	//instantiate 64 random color objects and place in the vector of colors
	//rand() returns a random number between 0 and RAND_MAX
	//rand() % max(inclusive by max - min + 1) + min = from min to max
	std::vector<Color> colors;
	int r, g, b;
	for(int i=0; i<64; ++i)
	{
		r = std::rand() % 256;
		g = std::rand() % 256;
		b = std::rand() % 256;
		colors.push_back(Color{r,g,b});
	}

	//sort the vector
	std::sort(colors.begin(), colors.end());

	//print out all colors
	for(auto c : colors)
	{
		std::cout << c << c.to_string() << std::endl;
	}

	//reset the terminal color
	std::cout << Color{};

	return 0;
}
