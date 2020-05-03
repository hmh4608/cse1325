#include <iostream>
#include <vector>
#include <string>
#include "cart.h"

int main() {
    Cart cart{"Rice"};

    //read in new items from std::cin using item's operator>> until end of 
    std::cout << "Enter product names and price (e.g., \"English peas 0.79\")";
    
    Item item{"", 0};
    
    while(std::cin >> item)
    {
        try{
            cart.add_item(item);
        }catch(std::exception& e){
            std::cerr << e.what() << std::endl;
        }
    }
    
    //output
    std::cout << "Register Receipt\n" << std::endl; 
    //using iteration capability
    for(iterator i = cart.begin(); i!=cart.end(); ++i)
    {
        std::cout << *i << std::endl;
    }
    std::cout << std::string(20, '-') << std::endl;
    std::cout << "$\t" + std::to_string(cart.cost()) + " Total Cost" << std::endl;
    
    return 0;
}
