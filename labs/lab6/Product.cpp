// Name: Mon Clarence Santa Cruz
// Seneca Student ID: 031608144
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: October 31, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
// Product.cpp

#include "Product.h"
#include <iomanip>

namespace w6{
    Product::Product(int pNum, double pCost){
        prodNum = pNum;
        cost = pCost;
    }
    
    double Product::getPrice() const{
        return cost;
    }
    
    void Product::display(std::ostream& os) const{
        os << "           " << std::setw(5) << std::setfill('0') << prodNum << std::setw(16) << std::setfill(' ') << cost;
    }
}
