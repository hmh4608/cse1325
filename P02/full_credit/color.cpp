#include "color.h"

//implementation of class Color

//constructor initializer list
Color::Color(int red, int green, int blue) : _red{red}, _green{green}, _blue{blue} {}

std::string Color::to_string()
{
	//std::to_string(int n) turns n into a string and returns it; necessary for concatenation	
	return '(' + std::to_string(_red) + ',' + std::to_string(_green) + ',' + std::to_string(_blue) + ')';
}

std::string Color::colorize(std::string text)
{
	return "\033[38;2;" + std::to_string(_red) + ";" + std::to_string(_green) + ";" + std::to_string(_blue) + "m" + text + "\033[0m";
}
