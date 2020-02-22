#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "product.h"
#include "taxed.h"
#include "taxfree.h"

int main()
{
	//predefined tax and taxfree goods in a vector of Product*
	const Taxed ICE_CREAM{"Ice Cream", 4.95};
	const Taxed YOGURT{"Yogurt", 3.99};
	const Taxed CANDY{"Candy", 0.95};
	const Taxfree BREAD{"Bread", 5.75};
	const Taxfree EGGS{"Eggs", 6.85};
	const Taxfree COFFEE{"Coffee", 7.49};

	std::vector<Product*> order;
	Taxed::set_tax_rate(0.0825); //sets tax rate
	int product = 0;//product choice
	int quantity = 0; //quantity of product
	double total = 0; //total price
	int i = 0;

	//raw string
	const std::string menu = R"(
=====================
Welcome to the Store!
=====================
0) Ice Cream ($4.95)
1) Yogurt ($3.99)
2) Candy ($0.99)
3) Bread ($5.75)
4) Eggs ($6.85)
5) Coffee ($7.49)

)";

	std::cout << menu;

	//loop menu
	do{
		std::cout << "Enter a quantity (0 to exit) and product index: ";
		std::cin >> quantity >> product;
		try{
			if(quantity != 0)
			{
				switch(product)
				{
					case 0 : order.push_back(ICE_CREAM.clone()); break;
					case 1 : order.push_back(YOGURT.clone()); break;
					case 2 : order.push_back(CANDY.clone()); break;
					case 3 : order.push_back(BREAD.clone()); break;
					case 4 : order.push_back(EGGS.clone()); break;
					case 5 : order.push_back(COFFEE.clone()); break;
					default : throw std::runtime_error("Not a product index"); break;
				}
				order[i]->set_quantity(quantity);
				i++;
				total = 0;
				//loop and print out all orders
				std::cout << menu << "Current Order\n-------------\n";
				for(auto& item : order)
				{
					std::cout << *item << std::endl;
					total += item->price();
				}

				std::cout << "\nTotal price: $" << std::setprecision(2) << std::fixed << total << "\n" << std::endl;
			}
		}catch(std::exception& e){
			std::cerr << "### Invalid input: " << e.what() << std::endl;
		}

	}while(quantity != 0);

	//lets clear the heap
	for(auto& item : order)
	{
		delete item;
	}
	order.clear();

	return 0;
}
