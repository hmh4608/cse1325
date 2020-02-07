#include <iostream>
#include "color.h"

//implementation of class Color

//constructors
Color::Color() : _red{0}, _green{0}, _blue{0}, _reset{true} {}
Color::Color(int red, int green, int blue) : _red{red}, _green{green}, _blue{blue}, _reset{false} {}

/*
method returns string representation of the RGB color
*/
std::string Color::to_string()
{
	//std::to_string(int n) turns n into a string and returns it; necessary for concatenation	
	return '(' + std::to_string(_red) + ',' + std::to_string(_green) + ',' + std::to_string(_blue) + ':' + std::to_string(magnitude()) + ')';
}

/*
*method returns the "subjective brightness" or magnitude (0-255) of the color
*calculated by returning 21% of red, 72% of green, and 7% of blue
*
*const promises the compiler that the const Color will not be modified
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

/*
stream out ANSI escape codes and colorizes
overloads << operator
*/
std::ostream& operator<<(std::ostream& ost, const Color& color)
{
	if(color._reset)
		ost << "\033[0m]";
	else	
		ost << "\033[38;2;" + std::to_string(_red) + ";" + std::to_string(_green) + ";" + std::to_string(_blue) + "m";

	return ost;
}

/*
read the color using (red, green, blue) format
overloads >> operator
*/
std::istream& operator>>(std::istream& ist, Color& color)
{
	int r, g, b;
	if(ist >> r >> g >> b)
		color = Color{r,g,b};
	return ist;
}
