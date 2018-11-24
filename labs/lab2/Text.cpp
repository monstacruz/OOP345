// Name: Mon Clarence Santa Cruz
// Seneca Student ID: 031608144
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: September 13, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#include <fstream>
#include <string>
#include <utility>

#include "Text.h"
using namespace std;

namespace w2 {
    Text::Text() : str{nullptr}{};
    
    Text::Text(const string & name){
        
        ifstream f(name);
        if (f.is_open()){
            string line;
            size_t lines = 0;
            
            while (!f.eof()){
                lines++;
                getline(f, line);
            }
            
            str = new string[lines];
            lineNum = lines;
            
            for(size_t i = 0; i < lines; i ++)
                getline(f, str[i]);
            
        }
        else {
            str = new string[0];
            lineNum = 0;
        }
    }
    
    Text::Text(const Text& input){
        
        lineNum = input.lineNum;
        str = new string[lineNum];
        for (int i = 0; i < lineNum; i ++)
            str[i] = input.str[i];
         
        
       // *this = input;
    }
    
    Text& Text::operator=(const Text& input){
        if (this != &input){
            lineNum = input.lineNum;
            str = new string[lineNum];
            for (int i = 0; i < lineNum; i++)
                str[i] = input.str[i];
        }
        
        return *this;
    }
    
    Text::Text(Text&& input){
        *this = move(input);
    }
    
    Text& Text::operator=(Text && input){
        if (this != &input){
            //delete [] str;
            str = input.str;
            lineNum = input.lineNum;
            input.str = nullptr;
            input.lineNum = 0;
    
        }
        return *this;
    }
    
    Text::~Text(){
        delete [] str;
        str = nullptr;
    }
    
    size_t Text::size() const {
        return lineNum;
    }
}
