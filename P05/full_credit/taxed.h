#ifndef __TAXED_H
#define __TAXED_H

#include <string>
#include "product.h"

//class declaration of taxed which is a product

class Taxed : public Product
{
	//everything else inherited from Product
	public:
	Taxed(std::string name, double cost);
	virtual ~Taxed();

	//methods
	static void set_tax_rate(double sales_tax);
	double price() const override;

	private:
	static double _tax;
};

#endif
