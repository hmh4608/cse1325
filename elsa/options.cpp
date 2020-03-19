#include <iostream>
#include <string>
#include "options.h"

//implementation of Options

//constructor and destructor
Options::Options(std::string name, double cost) : _name{name}, _cost{cost} {}
Options::~Options() {}

//methods
double Options::cost()
{
	return _cost;
}

std::string Options::to_string()
{
	return _name;
}

std::ostream& operator<<(std::ostream& ost, const Options& option)
{
	ost << to_string() + " $" << cost();
	return ost;
}
