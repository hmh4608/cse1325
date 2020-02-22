#ifndef __PRODUCT_H
#define __PRODUCT_H

#include <iostream>
#include <string>

//abstract class declaration of Product

class Product
{
	public:
	//constructor and destructor	
	Product(std::string name, double cost);
	virtual ~Product();
	
	//methods
	void set_quantity(int quantity);
	virtual double price() const = 0; //pure virtual method, no implementation atm
	friend std::ostream& operator<<(std::ostream& ost, const Product& product);
	void validate(); //validates inputs

	protected:
	int _quantity; //the only mutable int, represents how many are to be purchased
	//immutable, cant be changed after construction	
	double _cost; //cost of product
	std::string _name; //name of product
};

#endif
