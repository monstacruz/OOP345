// Name: Mon Clarence Santa Cruz
// Seneca Student ID: 031608144
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: October 31, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
// ProdUtil.h

#ifndef W6_PRODUTIL_H
#define W6_PRODUTIL_H

#include <iostream>
#include <fstream>
#include "iProduct.h"

namespace w6
{
    std::ostream& operator<<(std::ostream&, const iProduct&);
    iProduct* readProduct(std::ifstream&);
}
#endif
