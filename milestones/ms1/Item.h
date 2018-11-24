// Name: Mon Clarence Santa Cruz
// Seneca Student ID: 031608144
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: November 10, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef ITEM_H
#define ITEM_H

#include <iostream>

class Item{
    std::string m_name;
    std::string m_description;
    unsigned int m_serialNumber;
    unsigned int m_quantity;
    static size_t m_widthField;
public:
    Item(const std::string&);
    const std::string& getName() const;
    const unsigned int getSerialNumber();
    const unsigned int getQuantity();
    void updateQuantity();
    void display(std::ostream& os, bool full) const;
};

#endif /* Item_h */
