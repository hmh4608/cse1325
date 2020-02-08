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
	Color operator+(int n);
	Color operator-(int n);
	Color& operator++(); //pre-increment
	Color operator++(int); //post-increment
	Color& operator--();
	Color operator--(int);

	//functions since the operator will be called on std::ostream and not the class
	friend std::ostream& operator<<(std::ostream& ost, const Color& color);
	friend std::istream& operator>>(std::istream& ist, Color& color);

	//predefined colors :O - static for accessibility and const so we don't want someone accidentally changing them
	static const Color RESET;
	static const Color BLACK;
	static const Color BLUE;
	static const Color GREEN;
	static const Color CYAN;
	static const Color RED;
	static const Color MAGENTA;
	static const Color YELLOW;
	static const Color GRAY;
	static const Color WHITE;

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
Color operator+(int n, Color& rhs);
Color operator-(int n, Color& rhs);

#endif
