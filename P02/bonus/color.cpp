#include "color.h"

//implementation of class Color

//constructor initializer list
Color::Color(int red, int green, int blue) : _red{red}, _green{green}, _blue{blue} {}

/*
method returns string representation of the RGB color
*/
std::string Color::to_string()
{
	//std::to_string(int n) turns n into a string and returns it; necessary for concatenation	
	return '(' + std::to_string(_red) + ',' + std::to_string(_green) + ',' + std::to_string(_blue) + ':' + std::to_string(magnitude()) + ')';
}

/*
method returns parameter preceded by ANSI escape code for "set foreground color" to the _red, _green, _blue:magnitude, and ends with ANSI escape code for "reset"
*/
std::string Color::colorize(std::string text)
{
	return "\033[38;2;" + std::to_string(_red) + ";" + std::to_string(_green) + ";" + std::to_string(_blue) + "m" + text + "\033[0m";
}

/*
*method returns the "subjective brightness" or magnitude (0-255) of the color
*calculated by returning 21% of red, 72% of green, and 7% of blue
*/
int Color::magnitude() const
{
	return (0.21 * _red) + (0.72 * _green) + (0.07 * _blue);
}

/*
method compares magnitude of current object to magnitude of rhs object provided as constant reference parameter
*/
int Color::compare(const Color& rhs)
{
	int rhsMag = rhs.magnitude();
	int thisMag = magnitude();

	if(thisMag > rhsMag)
		return 1;
	else if(thisMag < rhsMag)
		return -1;
	else
		return 0;
}
