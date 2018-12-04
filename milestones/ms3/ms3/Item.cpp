// Name: Mon Clarence Santa Cruz
// Seneca Student ID: 031608144
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: November 10, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iomanip>
#include <string>
#include "Item.h"
#include "Utilities.h"


size_t Item::m_widthField = 1;

Item::Item(){
    m_name = "";
    m_description = "";
    m_serialNumber = 0;
    m_quantity = 0;
}

Item::Item(const std::string& input){
    Utilities util;
    size_t currPos = 0;
    bool more;
    m_name = util.extractToken(input, currPos, more);
    try {
        if (more)
            m_serialNumber = stoi(util.extractToken(input, currPos, more));
        if (more)
            m_quantity = stoi(util.extractToken(input, currPos, more));
        if (more)
            m_description = util.extractToken(input, currPos, more);
    } catch (...) {
        std::cout << ":)" << std::endl;
    }
    
    Item::m_widthField = util.getFieldWidth();
    
}

const std::string& Item::getName() const{
    return m_name;
}

const unsigned int Item::getSerialNumber(){
    return m_serialNumber++;
}

const unsigned int Item::getQuantity(){
    return m_quantity;
}

void Item::updateQuantity(){
    if (m_quantity >= 1)
        m_quantity--;
}

void Item::display(std::ostream& os, bool full) const{
    os << std::left << std::setw(Item::m_widthField) << m_name << " [" << std::right << std::setfill('0') << std::setw(6) <<  m_serialNumber << std::setfill(' ') << "]";
    if (full)
        os << " Quantity: " << std::left << std::setw(Item::m_widthField) << m_quantity << " Description: " << m_description;
    os << std::endl;
}
