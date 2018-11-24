// Name: Mon Clarence Santa Cruz
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: November 7, 2018

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>
#include <functional>
#include <iomanip>
#include <algorithm>

#ifndef W7_DATATABLE_H
#define W7_DATATABLE_H


namespace w7 {
    template <typename T>
    class DataTable {
        std::vector<T> xVal;
        std::vector<T> yVal;
        int width, decs;
    public:
        DataTable();
        DataTable(std::ifstream&, int, int);
        T mean() const;
        T sigma() const;
        T median() const;
        void regression(T& slope, T& y_intercept) const;
        void display(std::ostream&) const;
        size_t getSize() const;
        };

    template <typename T>
    DataTable<T>::DataTable(){
        
    }
    
    template <typename T>
    DataTable<T>::DataTable(std::ifstream& is, int w, int d){
        std::string line;
        width = w;
        decs = d;
        if (is.is_open()){
            while (!is.eof()){
                getline(is, line);
                if (!is.eof()){
                    xVal.push_back(stod(line.substr(0, line.find(' '))));
                    yVal.push_back(stod(line.substr(line.find(' '))));
                }
            }
        }
    }
    
    template <typename T>
    T DataTable<T>::mean() const{
        return std::accumulate(yVal.begin(), yVal.end(), (T)0, [=] (T init, T total){return init + total / yVal.size();});
    }
    
    template <typename T>
    T DataTable<T>::sigma() const{
        T yMean = mean();
        std::vector<T> meanVector(xVal.size()); // a vector that holds the yvector with every element subtracted by the mean, and squared
	std::transform(yVal.begin(), yVal.end(), meanVector.begin(), [=] (T x) {return (x - yMean) * (x - yMean);});
        return std::sqrt(std::accumulate(meanVector.begin(), meanVector.end(), (T)0, [=] (T initial, T total) {return initial + total / (meanVector.size()-1);}));
    }
    
    template <typename T>
    T DataTable<T>::median() const{
        std::vector<T> tmp;
        tmp = yVal;
        
        std::sort(tmp.begin(), tmp.end(), [](T x, T y){ return x < y;});
        
        return (tmp.size() % 2 ?  tmp[(tmp.size()/2) + 1] : tmp[tmp.size()/2]) ;
    }
    
    template <typename T>
    void DataTable<T>::regression(T& slope, T& y_intercept) const{
        // to get the slope, the inner product of xVal and yVal (we call this p0) multiplied by the size (n) is subtracted by the sum of xVal multiplied by
        // the sum of yVal (we call this p1). p0 - p1 is then divided by the squared sum of xVal multiplied by size (we call this p2).
        // subtracted by the sum of xVal squared (we call this p3)
        // the formula for slope is: ((p0 * n) - p1) / (p2 - p3)
        
        T p0, p1, p2, p3;
        size_t n = xVal.size();
        std::vector<T> squaredVec(xVal.size()); // this is going to be the squared vector of xVal to be accumulated for getting p2
        p0 = n * (std::inner_product(xVal.begin(), xVal.end(), yVal.begin(), (T)0));
        p1 = (std::accumulate(xVal.begin(), xVal.end(), (T)0))*(std::accumulate(yVal.begin(), yVal.end(), (T)0));
        std::transform(xVal.begin(), xVal.end(), squaredVec.begin(), [] (T x) { return x*x;});
        p2 = n * std::accumulate(squaredVec.begin(), squaredVec.end(), (T)0);
        p3 = std::accumulate(xVal.begin(), xVal.end(), (T)0) * std::accumulate(xVal.begin(), xVal.end(), (T)0);
        
        slope = ((p0 - p1) / (p2 - p3));
        
        // the y intercept is calculated by subtracting the sum of yVal (p4) by the slope multiplied by the sum of xVal (p5)
        // all divided by the size (n)
        T p4, p5;
        
        p4 = std::accumulate(yVal.begin(), yVal.end(), (T)0);
        p5 = std::accumulate(xVal.begin(), xVal.end(), (T)0);
        
        y_intercept = (p4 - (slope * p5)) / n;
    }
    
    template <typename T>
    void DataTable<T>::display(std::ostream& os) const{
        os << std::setw(width) << std::setprecision(decs) << "x" << std::setw(width) << std::setprecision(decs) << "y" << std::endl;
        for (size_t a = 0 ;a < xVal.size(); a++) {
            os << std::setw(width) << std::setprecision(decs) << std::fixed << xVal[a] << std::setw(width) << yVal[a] << std::endl;
        }
    }
    
    template <typename T>
    size_t DataTable<T>::getSize() const {
        return xVal.size();
    }
    
    template <typename T>
    std::ostream& operator<<(std::ostream& os, const DataTable<T>& src) {
        src.display(os);
        return os;
    }

}

#endif
