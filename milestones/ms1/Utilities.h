// Name: Mon Clarence Santa Cruz
// Seneca Student ID: 031608144
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: November 10, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef UTILITIES_H
#define UTILITIES_H
#include <iostream>

class Utilities{
    size_t m_widthField;
    static char m_delimiter;
public:
    Utilities(){m_widthField = 1;}
    void setFieldWidth(size_t);
    size_t getFieldWidth() const;
    const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
    static void setDelimiter(const char);
    const char getDelimiter() const;
    
};

#endif /* Utilities_h */
