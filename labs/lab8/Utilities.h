// Name: Mon Clarence Santa Cruz
// Seneca Student ID: 031608144
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: November 12, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W8_UTILITIES_H
#define W8_UTILITIES_H
#include "List.h"
#include "Element.h"

namespace w8 {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif
