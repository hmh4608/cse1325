#ifndef __OPTIONS_H
#define __OPTIONS_H

#include <iostream>
#include <string>

class Options
{
	public:
	//constructors and destructor
	Options(std::string name, double cost);
	Options(std::istream& ist);
	virtual ~Options();

	double cost() const;
	virtual void save(std::ostream& ost);
	virtual std::string to_string() const;
	virtual Options* clone();
	friend std::ostream& operator<<(std::ostream& ost, const Options& option);

	protected:
	std::string _name;
	double _cost;
};

#endif
