#include <iostream> //for cin, cout, string
#include <algorithm> //for sort
#include <vector> //for vector and methods push_back, begin, end
#include "color.h"

int main()
{
	/*
	*colors[0] = red
	*colors[1] = green
	*colors[2] = blue
	*colors[3] = white
	*/	
	std::vector<Color> colors = { Color{255,0,0}, Color{0,255,0}, Color{0,0,255}, Color{255,255,255} };
	Color bg_blue{0,0,255,true}; //blue background color
	
	//testing operator+ and -
	Color pink = colors[0] + 128;
	Color dark_red = colors[0] - 128;

	colors.push_back(dark_red);
	colors.push_back(pink);


	//reset the terminal color
	std::cout << Color{};

	return 0;
}
