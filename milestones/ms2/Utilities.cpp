// Name: Mon Clarence Santa Cruz
// Seneca Student ID: 031608144
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: November 10, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Utilities.h"

char Utilities::m_delimiter='\0';

void Utilities::setFieldWidth(size_t input){
    m_widthField = input;
}

size_t Utilities::getFieldWidth() const{
    return m_widthField;
}

const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more){
    std::string result;

    if (str[next_pos] == getDelimiter())
        throw "error, no token";
    size_t newPos = str.find(getDelimiter(), next_pos);
    if (newPos == std::string::npos){
        more = false;
        result = str.substr(next_pos);
    } else {
        result = str.substr(next_pos, newPos - next_pos);
        more = true;
        next_pos = newPos + 1;
        if (m_widthField < result.length()){
            m_widthField = result.length();
        }
    }

    return result;
}

void Utilities::setDelimiter(const char input){
    m_delimiter = input;
    
}

const char Utilities::getDelimiter() const{
    return m_delimiter;
}
