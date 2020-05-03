
#ifndef __CART_H
#define __CART_H

#include <vector>
#include <iostream>
#include <string>
#include "item.h"

typedef std::vector<Item*> Items;
typedef Items::iterator iterator;
typedef Items::const_iterator const_iterator;

class Cart
{
public:
    Cart(std::string customer);
    Cart(const Cart& cart); //copy constructor
    ~Cart();
    Cart& operator=(const Cart& cart); //copy assignment operator
    void add_item(Item& item);
    double cost();
    //iterators
    iterator begin();
    iterator end();
    
private:
    std::string _customer;
    Items _items;
};


#endif /* CART_H */

