//
//  Message.h
//  lab4
//
//  Created by mon sta cruz on 2018-09-26.
//  Copyright © 2018 mon. All rights reserved.
//

#ifndef W4_MESSAGE_H
#define W4_MESSAGE_H

#include <iostream>
#include <fstream>
#include <string>

namespace w4{
    
    class Message{ //the Message class contains strings that hold different components of a record of the tweets.dat file
        std::string user;
        std::string reply;
        std::string message;
        std::string atCheck;
        
    public:
        Message();
        Message(std::ifstream&, char);
        bool empty() const;
        void display(std::ostream&) const;
    };
}

#endif /* Message_h*/
