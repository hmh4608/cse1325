#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "options.h"
#include "ram.h"

//implementation of Options

//constructor and destructor
Options::Options(std::string name, double cost) : _name{name}, _cost{cost} {}
Options::Options(std::istream& ist)
{
	ist >> _name >> _cost;
}
Options::~Options() {}

//methods
void Options::save(std::ostream& ost)
{
	ost << "other" << std::endl;	
	ost << _name << std::endl;
	ost << _cost << std::endl;
}
double Options::cost() const
{
	return _cost;
}

std::string Options::to_string() const
{
	return _name;
}

//copies current obj to the heap and returns pointer to it
Options* Options::clone()
{
	return new Options{*this};
}

std::ostream& operator<<(std::ostream& ost, const Options& option)
{
	if(option.cost() < 0) throw std::runtime_error("Cost is negative");	
	ost << option.to_string() + " ($" <<  std::fixed << std::setprecision(2) << option.cost() << ")";
	return ost;
}
