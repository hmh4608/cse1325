#include <iostream> //for cin, cout, string
#include <algorithm> //for sort
#include <vector> //for vector and methods push_back, begin, end
#include "color.h"

int main()
{
	std::vector<Color> colors = { Color::BLACK, Color::RED, Color::GREEN, Color::BLUE, Color::CYAN, Color::MAGENTA, Color::YELLOW, Color::GRAY, Color::WHITE };
	Color bg_blue{0,0,255,true}; //blue background color
	
	//testing operator+ and -
	Color pink = colors[1] + 128;
	Color dark_red = colors[1] - 128;

	colors.push_back(dark_red);
	colors.push_back(pink);


	//reset the terminal color
	std::cout << Color::RESET << std::endl;

	return 0;
}
