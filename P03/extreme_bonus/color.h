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
	Color(int red, int green, int blue, bool bg);
	std::string to_string();
	int magnitude() const;
	
	//overloading comparison operators
	inline bool operator==(const Color& rhs){ return (compare(rhs) == 0); }
	inline bool operator!=(const Color& rhs){ return (compare(rhs) != 0); }
	inline bool operator<(const Color& rhs){ return (compare(rhs) < 0); }
	inline bool operator<=(const Color& rhs){ return (compare(rhs) <= 0); }
	inline bool operator>(const Color& rhs){ return (compare(rhs) > 0); }
	inline bool operator>=(const Color& rhs){ return (compare(rhs) >= 0); }

	//overloading other operators
	Color operator+(const Color& rhs);
	Color operator-(const Color& rhs);

	//functions
	friend std::ostream& operator<<(std::ostream& ost, const Color& color);
	friend std::istream& operator>>(std::istream& ist, Color& color);

	//private stuff
	private:
	int compare(const Color& rhs);
	int _red;
	int _green;
	int _blue;
	bool _reset;
	bool _background;
};

//operator symmetry
Color operator+(const Color& rhs, Color& color);
Color operator-(const Color& rhs, Color& color);

#endif
