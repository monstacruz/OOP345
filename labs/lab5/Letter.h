// Name: Mon Clarence Santa Cruz
// Seneca Student ID: 031608144
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: October 8, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef SICT_LETTER_H
#define SICT_LETTER_H

#include <cstring>

namespace sict{

    enum class Letter {A, AP, B, BP, C, CP, D, DP, E, F};

    template<typename T>
    char * convert(const T & input){
        char * result;
        switch (input) {
            case Letter::A:
                result = new char[2];
                strcpy(result, "A");
                break;
            case Letter::AP:
                result = new char[3];
                strcpy(result, "A+");
                break;
            case Letter::B:
                result = new char[2];
                strcpy(result, "B");
                break;
            case Letter::BP:
                result = new char[3];
                strcpy(result, "B+");
                break;
            case Letter::C:
                result = new char[2];
                strcpy(result, "C");
                break;
            case Letter::CP:
                result = new char[3];
                strcpy(result, "C+");
                break;
            case Letter::D:
                result = new char[2];
                strcpy(result, "D");
                break;
            case Letter::DP:
                result = new char[3];
                strcpy(result, "D+");
                break;
            case Letter::E:
                result = new char[2];
                strcpy(result, "E");
                break;
            case Letter::F:
                result = new char[2];
                strcpy(result, "F");
                break;
        }
        return result;
    }
}
#endif
