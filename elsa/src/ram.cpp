#include "ram.h"

//constructor and destructor
Ram::Ram(std::string name, double cost, int gb) : Options(name, cost), _gb{gb} {}
Ram::Ram(std::istream& ist) : Options(ist) { ist >> _gb; }
Ram::~Ram() {}

std::string Ram::to_string() const
{	
	return Options::to_string() + " " + std::to_string(_gb) + " gb RAM";
}

void Ram::save(std::ostream& ost)
{
	ost << "ram" << std::endl;	
	Options::save(ost);
	ost << _gb << std::endl;
}

Ram* Ram::clone()
{
	return new Ram{*this};
}
