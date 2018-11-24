// Name: Mon Clarence Santa Cruz
// Seneca Student ID: 031608144
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: October 8, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#include <iostream>
#include <fstream>
#include "Grades.h"

using namespace std;

namespace sict  {
    
    Grades::Grades(const char * input){
        ifstream f(input);
        string dummy;
        
		if (f.is_open()) {
			while (!f.eof()) {
				size++;
				getline(f, dummy);
			}
		} else {
			throw "Cannot open the file";
		}

		f.close();
		f.open(input);

        row = new string[size];
        
        for (size_t i = 0; i < size; i++){
            getline (f, row[i]);
        }

        f.close();
        }
    
    Grades::~Grades(){
        delete [] row;
        row = nullptr;
    }
        
}

