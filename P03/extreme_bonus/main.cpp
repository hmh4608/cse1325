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
	
	Color pink = 128 + colors[0]; //fix later

	std::cout << pink << pink.to_string() << std::endl;

	//reset the terminal color
	std::cout << Color{};

	return 0;
}
