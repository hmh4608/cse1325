#ifndef __RAM_H
#define __RAM_H

#include "options.h"

class Ram : public Options
{
	public:
	Ram(std::string, double cost, int gb);
	Ram(std::istream& ist);
	virtual ~Ram();

	std::string to_string() const override;
	void save(std::ostream& ost) override;
	Ram* clone() override;

	protected:
	int _gb;
};

#endif
