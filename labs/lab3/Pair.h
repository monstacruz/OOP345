//
//  Pair.h
//  lab3
//
//  Created by mon sta cruz on 2018-09-19.
//  Copyright © 2018 mon. All rights reserved.
//

#ifndef PAIR_H
#define PAIR_H

template <typename A, typename B>
class Pair {
    A key;
    B value;
public:
    Pair(){
    }
    
    Pair(const A& Ainput, const B& Binput) : key {Ainput} , value {Binput}
    {
        
    }
    
    const A& getKey() const{
        return key;
    }
    
    const B& getValue() const{
        return value;
    }
};

#endif
