#include <iostream>
#include <string>
#include "options.h"

//implementation of Options

//constructor and destructor
Options::Options(std::string name, double cost) : _name{name}, _cost{cost} {}
Options::~Options() {}

//methods
double Options::cost() const
{
	return _cost;
}

std::string Options::to_string() const
{
	return _name;
}

std::ostream& operator<<(std::ostream& ost, const Options& option)
{
	if(option.cost() < 0) throw std::runtime_error("Cost is negative");	
	ost << option.to_string() + " $" << option.cost();
	return ost;
}
