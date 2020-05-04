#include "item.h"

//data bag class
Item::Item(std::string name, double price) : _name{name}, _price{price} {}
Item::Item(const Item& item) : Item{item._name, item._price} {}


double Item::cost() const { return _price; }

//streaming out/in
std::ostream& operator<<(std::ostream& ost, const Item& item)
{
    ost << std::setprecision(2) << std::fixed << "$\t" << item.cost() << " " + item._name;
    return ost;
}
std::istream& operator>>(std::istream& ist, Item& item)
{

    std::string line;
    std::getline(ist, line);

    //find the last white-space separated word
    auto pos = line.find_last_of(" ");
    //split into name and price
    item._name = std::string{line, 0, pos};
    
    std::string word = std::string{line, pos+1};
    
    try{
        item._price = std::stod(word);
    }catch(std::exception& e){
        std::cerr << "Invalid price:  '" + item._name + "' ==> " + word << std::endl;
    }
    
    return ist;
}
