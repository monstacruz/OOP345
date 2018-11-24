// Name: Mon Clarence Santa Cruz
// Seneca Student ID: 031608144
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: October 31, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
// TaxableProduct.h

#ifndef W6_TAXABLEPRODUCT_H
#define W6_TAXABLEPRODUCT_H

#include <iostream>
#include "Product.h"
namespace w6 {
    class TaxableProduct : public Product {
        char type;
        static float tax[2];
    public:
        TaxableProduct(char, int, double);
        double getPrice() const;
        void display(std::ostream&) const;
    };
}
#endif /* TaxableProduct_h */
