#include <vector>
#include <string>
#include <iostream>
#include "store.h"

//implementation of Store
//customer
//push customer to customers vector
void Store::add_customer(Customer& customer)
{
	customers.push_back(customer);
}
//return size() method of the vector
int Store::num_customers()
{
	return customers.size();
}
//returns a reference to the object in the vector at the index provided as a parameter
Customer& Store::customer(int index)
{
	return customers.at(index);
}

//options
void Store::add_option(Options& option)
{
	options.push_back(&option);
}
int Store::num_options()
{
	return options.size();
}
Options& Store::option(int index)
{
	return *(options.at(index));
}

//desktop
//pushes new object into vector and returns its index
int Store::new_desktop()
{
	desktops.push_back(Desktop{});
	return num_desktops()-1;
}
//given index of the option to add to the desktop at the provided index
void Store::add_option(int option, int desktop)
{
	(this->desktop(desktop)).add_option(this->option(option));
}
int Store::num_desktops()
{
	return desktops.size();
}
Desktop& Store::desktop(int index)
{
	return desktops.at(index);
}

//orders
int Store::new_order(int customer)
{
	orders.push_back(Order{this->customer(customer)});
	return num_orders()-1;
}
void Store::add_desktop(int desktop, int order)
{
	(this->order(order)).add_product(this->desktop(desktop));
}
int Store::num_orders()
{
	return orders.size();
}
Order& Store::order(int index)
{
	return orders.at(index);
}
