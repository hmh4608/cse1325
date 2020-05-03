#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <iomanip>

class Item
{
public:
    Item(std::string name, double price);
    Item(const Item& rhs);
    double cost() const;
    friend std::ostream& operator<<(std::ostream& ost, const Item& item);
    friend std::istream& operator>>(std::istream& ist, Item& item);
private:
    std::string _name;
    double _price;
};

#endif /* ITEM_H */
