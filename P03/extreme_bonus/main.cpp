#include <iostream> //for cin, cout, string
#include <algorithm> //for sort
#include <vector> //for vector and methods push_back, begin, end
#include "color.h"

int main()
{
	Color red{255,0,0};
	Color bg_blue{0,0,255,true};

	std::cout << red << bg_blue << "Hi!" << std::endl;
	
	Color blue{0,0,255};

	std::cout << Color{};
	
	Color purple = red + blue;
	
	std::cout << red << red.to_string() + "\n" << blue << blue.to_string() + "\n" << purple << purple.to_string() << std::endl;

	//reset the terminal color
	std::cout << Color{};

	return 0;
}
