//
//  List.h
//  lab3
//
//  Created by mon sta cruz on 2018-09-19.
//  Copyright © 2018 mon. All rights reserved.
//

#ifndef LIST_H
#define LIST_H
#include <iostream>

template <class T, int N>
class List{
    T arr[N];
    size_t aSize = 0;
public:
    List() {
    }
    
    size_t size() const {
        return aSize;
    }
    
    const T& operator[](int index) const {
        return arr[index];
    }
    
    List& operator+=(const T& value){
        if (aSize < N){
            arr[aSize] = value;
            aSize++;
        }
        return *this;
    }
};

#endif /* List_h */
