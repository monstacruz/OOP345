// Name: Mon Clarence Santa Cruz
// Seneca Student ID: 031608144
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: October 31, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
// TaxableProduct.cpp

#include "TaxableProduct.h"

namespace w6{
    
    float TaxableProduct::tax[2] = {1.13, 1.08};
    
    TaxableProduct::TaxableProduct(char pTax, int pNum, double pCost) : Product(pNum, pCost){
        type = pTax;
    }
    
    double TaxableProduct::getPrice() const{
        double pTax = Product::getPrice();
        return type == 'H' ? pTax * tax[0] : pTax * tax[1];
    }
    
    void TaxableProduct::display(std::ostream& os) const{
        Product::display(os);
        os << (type == 'H' ? " HST" : " PST");
    }
}
