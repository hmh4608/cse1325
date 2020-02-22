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
	std::vector<Product*> goods = {new Taxed{"Ice Cream", 4.95}, new Taxed{"Yogurt", 3.99}, new Taxed{"Candy", 0.95}, new Taxfree{"Bread", 5.75}, new Taxfree{"Eggs", 6.85}, new Taxfree{"Coffee", 7.49}};

	Taxed::set_tax_rate(0.0825); //sets tax rate
	int product = 0;//product choice
	int quantity = 0; //quantity of product
	double total = 0; //total price

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
			if(product < 0 || product >= goods.size())
			{
				throw std::runtime_error("Product index input is invalid");
			}
			else if(quantity != 0)
			{
				goods[product]->set_quantity(goods[product]->get_quantity() + quantity);
				total = 0;
				std::cout << menu << "Current Order\n-------------\n";
				//loop and print out all orders
				for(auto& item : goods)
				{
					if(item->get_quantity() != 0)
					{
						std::cout << *item << std::endl;
						total += item->price();
					}
				}

				std::cout << "\nTotal price: $" << std::setprecision(2) << std::fixed << total << "\n" << std::endl;
			}
		}catch(std::exception& e){
			std::cerr << "### Invalid input: " << e.what() << std::endl;
		}

	}while(quantity != 0);

	return 0;
}
