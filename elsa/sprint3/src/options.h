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
	~Options();

	double cost() const;
	void save(std::ostream& ost);
	virtual std::string to_string() const;
	friend std::ostream& operator<<(std::ostream& ost, const Options& option);

	protected:
	std::string _name;
	double _cost;
};

#endif
