#include "cart.h"

//constructors and destructors
Cart::Cart(std::string customer) : _customer{customer} {}
Cart::Cart(const Cart& cart) : _customer{cart._customer}
{
    //deep copy
    for(auto& item : cart._items)
    {
        _items.push_back(new Item{*item});
    }
}
Cart::~Cart()
{
    for(auto& item : _items)
    {
        delete item;
    }
    _items.clear();
}

//copy assignment operator
Cart& Cart::operator=(const Cart& cart)
{
    if(this != &cart)
    {
        _customer = cart._customer;
        for(auto& item : cart._items)
        {
            _items.push_back(new Item{*item});
        }
    }
    return *this;
}

//methods
void Cart::add_item(Item& item)
{
    _items.push_back(new Item{item});
}

//totals up the cost of each item in _items and returns the total
double Cart::cost()
{
    double total = 0;
    for(auto& item : _items)
    {
        total += item->cost();
    }
    return total;
}

//iterators
iterator Cart::begin()
{
    return _items.begin();
}
iterator Cart::end()
{
    return _items.end();
}

