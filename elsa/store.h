#ifndef __STORE_H
#define __STORE_H

#include <iostream>
#include <string>
#include <vector>

class Store
{
	public:
	void add_customer(Customer& customer);
	int num_customers();
	Customer& customer(int index);
	void add_option(Options& option);
	int num_desktops();
	Desktop& desktop(int index);
	int new_order(int customer);
	void add_desktop(int desktop, int order);
	int num_orders();
	Order& order(int index);
	
	private:
	std::vector<Customer> customers;
	std::vector<Options*> options;
	std::vector<Desktop> desktops;
	std::vector<Order> orders;
};

#endif
