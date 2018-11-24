// Name: Mon Clarence Santa Cruz
// Seneca Student ID: 031608144
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: October 31, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
// prodUtil.cpp

#include "ProdUtil.h"
#include "TaxableProduct.h"
#include <string>
using namespace std;

namespace w6{
    ostream& operator<<(ostream& os, const iProduct& input) {
        input.display(os);
        os << endl;
        return os;
    }
    
    iProduct* readProduct(std::ifstream& ifs){
        iProduct* result;
        string line, sProdNum, sPrice;
        getline(ifs, line);
        if(ifs.eof())
            throw "no such record! Reached the end of file!";
        sProdNum = line.substr(0, line.find(' '));
        sPrice = line.substr(line.find(' '));
        do {
            sPrice = sPrice.substr(1);
        } while (sPrice[0] == ' ');
        if (sPrice.find(' ') == string::npos){
            result = new Product(stoi(sProdNum), stod(sPrice));
        } else{
            char taxType = sPrice[sPrice.size()-1];
            if (taxType != 'H' && taxType != 'P'){
                result = nullptr;
                throw "Unrecognizable Tax Code!";
            } else
                result = new TaxableProduct(taxType, stoi(sProdNum), stod(sPrice.substr(0,sPrice.find(' '))));
        }
        return result;
    }
}
