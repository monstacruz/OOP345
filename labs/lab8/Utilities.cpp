// Name: Mon Clarence Santa Cruz
// Seneca Student ID: 031608144
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: November 12, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"


using namespace std;

namespace w8
{
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
        
		// TODO: Add your code here to build a list of products
		//         using raw pointers
        cout << "desc.size: " << desc.size() << " price.size(): " << price.size() << endl;
        for (size_t i = 0; i < desc.size(); ++i){
            for (size_t j = 0; j < price.size(); ++j){
                if (desc[i].code == price[j].code){
                    Product * ptr = new Product(desc[i].desc, price[j].price);
                    ptr->validate();
                    priceList += ptr;
                    delete ptr;
                }
            }
        }
        
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
        for (size_t i = 0; i < desc.size(); ++i){
            for (size_t j = 0; j < price.size(); ++j){
                if (desc[i].code == price[j].code){
                    std::unique_ptr<Product> ptr(new Product(desc[i].desc, price[j].price));
                    ptr->validate();
                    priceList += move(ptr);
                }
            }
        }
		return priceList;
	}
}
