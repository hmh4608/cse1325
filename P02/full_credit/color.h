#ifndef __COLOR_H
#define __COLOR_H

#include <string>

//class Color interface

class Color
{
	//private instance variables
	private:
	int _red;
	int _green;
	int _blue;

	//public constructor and methods
	public:
	Color(int red, int green, int blue);
	std::string to_string();
	std::string colorize(std::string text);
};

#endif
