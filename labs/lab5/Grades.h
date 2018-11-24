// Name: Mon Clarence Santa Cruz
// Seneca Student ID: 031608144
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: October 8, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.



#ifndef SICT_GRADES_H
#define SICT_GRADES_H

#include <string>
#include "Letter.h"
#include <iostream>
#include <iomanip>

namespace sict{
    class Grades{
        std::string * row;
        size_t size = 0;
    public:
        Grades(const char *);
        
		Grades(Grades&) = delete;
		Grades(Grades&&) = delete;

		Grades& operator = (Grades&) = delete;
		Grades& operator = (Grades&&) = delete;
        
        ~Grades();

        template<typename F>
        void displayGrades(std::ostream& os, F func) const{
            for(size_t i = 0; i < size; i++){
                std::string studNum = row[i].substr(0, row[i].find(' '));
                double dGrade;

                if (i < size - 1)
                    dGrade = stod(row[i].substr(row[i].find(' '), std::string::npos));
                else
                    break;
                
                os  << std::right << std::setw(10) << studNum << " "
                    << std::setprecision(2) << std::fixed << std::setw(5) << dGrade << " "
                    << std:: left << std::setw(4) << convert<Letter>(func(dGrade))
                    << std::endl;
                }
        }
    };
}

#endif /* Grades_h */
