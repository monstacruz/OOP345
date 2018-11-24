// Name: Mon Clarence Santa Cruz
// Seneca Student ID: 031608144
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: October 31, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
// iProduct.h

#ifndef W6_IPRODUCT_H
#define W6_IPRODUCT_H
#include <fstream>

namespace w6
{
    class iProduct
    {
    public:
        virtual double getPrice() const = 0;
        virtual void display(std::ostream&) const = 0;
    };
}
#endif
