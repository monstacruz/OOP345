// Name: Mon Clarence Santa Cruz
// Seneca Student ID: 031608144
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: September 13, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W2_TEXT_H
#define W2_TEXT_H

namespace w2 {
    class Text {
	    std::string * str;
        size_t lineNum;
    public:
        Text();
        Text(const std::string & name);
        
        Text(const Text&);
        Text& operator=(const Text &);
        
        Text(Text&&);
        Text & operator=(Text&&);
        
        ~Text();
        size_t size() const;
    };
}

#endif 
