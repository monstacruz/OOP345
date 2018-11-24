// Name: Mon Clarence Santa Cruz
// Seneca Student ID: 031608144
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: November 21, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

#include <string>
#include <iomanip>
#include "Item.h"
#include "Utilities.h"

struct ItemInfo
{
    std::string m_itemName;
    unsigned int m_serialNumber = 0;
    bool m_fillState = false;
    
    ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder{
    std::string m_name;
    std::string m_product;
    unsigned int m_cntItm;
    ItemInfo** m_lstItem;
    static size_t m_widthField;
    
public:
    CustomerOrder();
    CustomerOrder(std::string);
    
    //restrict copy assignment and constructor
    CustomerOrder(const CustomerOrder&) {throw ":)"; }
    CustomerOrder& operator = (CustomerOrder&) = delete;
    
    CustomerOrder(CustomerOrder&&) noexcept;
    CustomerOrder& operator = (CustomerOrder&&);
    
    ~CustomerOrder();
    
    bool getItemFillState(std::string) const;
    bool getOrderFillState() const;
    void fillItem(Item& item, std::ostream& os);
    void display(std::ostream& os) const;
};




#endif /* CustomerOrder_h */
