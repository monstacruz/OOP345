// Name: Mon Clarence Santa Cruz
// Seneca Student ID: 031608144
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: November 21, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "CustomerOrder.h"

size_t CustomerOrder::m_widthField = 1;

CustomerOrder::CustomerOrder(){
    m_name = "";
    m_product = "";
    m_cntItm = 0;
    m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(std::string input) : CustomerOrder() {
    Utilities util;
    bool more;
    size_t currPos = 0;
    m_cntItm = 0;
    m_lstItem = nullptr;
    try {
        m_name = util.extractToken(input, currPos, more);
        if (more)
            m_product = util.extractToken(input, currPos, more);
        
        size_t tempPos = currPos;
        while(more) {
            std::string dummy = util.extractToken(input, currPos, more);
            m_cntItm++;
        }
        
        m_lstItem = new ItemInfo* [m_cntItm];
        currPos = tempPos;
        more = true;
        
        for (size_t i = 0; i < m_cntItm; i++){
            std::string dummy = util.extractToken(input, currPos, more);
            if (dummy[dummy.length() - 1] == '\r' || dummy[dummy.length() - 1] == '\n' ){
                dummy = dummy.substr(0, dummy.length() - 1);
            }
            m_lstItem[i] = new ItemInfo(dummy);
        }
        
        if (CustomerOrder::m_widthField < util.getFieldWidth())
            CustomerOrder::m_widthField = util.getFieldWidth();
        
    } catch(...){
        std::cout << ":)" << std::endl;
    }
        
}

CustomerOrder::CustomerOrder(CustomerOrder&& input) noexcept : CustomerOrder(){
    *this = std::move(input);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& input){
    if (this != &input){
        
        for (size_t i = 0; i < m_cntItm; i++)
            delete m_lstItem[i];
        
        
        delete[] m_lstItem;
        
        m_lstItem = input.m_lstItem;
        m_name = input.m_name;
        m_product = input.m_product;
        m_cntItm = input.m_cntItm;
        
        input.m_name = "";
        input.m_product = "";
        input.m_cntItm = 0;
        input.m_lstItem = nullptr;
    }
    
    return *this;
}

CustomerOrder::~CustomerOrder(){
    for (size_t i = 0; i < m_cntItm; i++){
        delete m_lstItem[i];
        m_lstItem[i] = nullptr;
    }
    
    delete[] m_lstItem;
    m_lstItem = nullptr;
}

bool CustomerOrder::getItemFillState(std::string input) const{
    bool result = true;
    for (size_t i = 0; i < m_cntItm; i++)
        if (input == m_lstItem[i]->m_itemName)
            result = m_lstItem[i]->m_fillState;
    return result;
}

bool CustomerOrder::getOrderFillState() const{
    bool result = true;
     for (size_t i = 0; i < m_cntItm; i++)
         if (!m_lstItem[i]->m_fillState)
             return false;
    return result;
}

void CustomerOrder::fillItem(Item& item, std::ostream& os){
    for (size_t i = 0; i < m_cntItm; i++){
        if (item.getName() == m_lstItem[i]->m_itemName){
            if (item.getQuantity() > 0){
                item.updateQuantity();
                m_lstItem[i]->m_serialNumber = item.getSerialNumber();
                m_lstItem[i]->m_fillState = true;
                os << "Filled " << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]" << std::endl;
            } else {
                os << "Unable to fill " << m_name << ", " << m_product <<  std::endl;
            }
                
        }
    }
}

void CustomerOrder::display(std::ostream& os) const{
    os << m_name << " - " << m_product << std::endl;
	for (size_t i = 0; i < m_cntItm; i++) {
		os << "[" << std::setfill('0') << std::setw(6) << std::right << m_lstItem[i]->m_serialNumber
			<< std::setfill(' ') << "] " << std::left << std::setw(CustomerOrder::m_widthField) << m_lstItem[i]->m_itemName
			<< " - " << ((m_lstItem[i]->m_fillState) ? "FILLED" : "MISSING");
		os << std::endl;
	}
    //os << "fWidth: " << m_widthField << std::endl;
    }
