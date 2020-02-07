#ifndef __COLOR_H
#define __COLOR_H

#include <iostream>
#include <string>

//class Color interface

class Color
{
	//public constructor and methods
	public:
	Color();
	Color(int red, int green, int blue);
	std::string to_string();
	int magnitude() const;
	int compare(const Color& rhs);
	friend std::ostream& operator<<(std::ostream& ost, const Color& color);
	friend std::istream& operator>>(std::istream& ist, Color& color);

	//private instance variables
	private:
	int _red;
	int _green;
	int _blue;
	bool _reset;
};

#endif
