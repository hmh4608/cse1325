#ifndef __TAXFREE_H
#define __TAXFREE_H

#include "product.h"

//derived class declaration of Taxfree which is a Product
class Taxfree : public Product
{
	public:
	//constructor and destructor
	Taxfree(std::string name, double cost);
	virtual ~Taxfree();

	//overridden method
	double price() const override;
	Product* clone() const override;
};

#endif
