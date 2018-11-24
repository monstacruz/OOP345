// Name: Mon Clarence Santa Cruz
// Seneca Student ID: 031608144
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: October 31, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
// Product.h

#ifndef W6_PRODUCT_H
#define W6_PRODUCT_H

#include <iostream>
#include "iProduct.h"

namespace w6 {
    class Product : public iProduct {
        int prodNum;
        double cost;
    public:
        Product(int, double);
        double getPrice() const;
        void display(std::ostream&) const;
        
    };
}

#endif /* Product_hpp */
