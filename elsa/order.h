#ifndef __ORDER_H
#define __ORDER_H

#include <iostream>
#include <vector>

class Order
{
	public:
	Order(Customer& customer);
	~Order();
	int add_product(Desktop& desktop);
	double price();

	private:
	Customer& _customer;
	std::vector<Desktop*> _products;
};

#endif
