//
//  Message.cpp
//  lab4
//
//  Created by mon sta cruz on 2018-09-26.
//  Copyright © 2018 mon. All rights reserved.
//

#include "Message.h"
#include <cstring>
#include <string.h>

using namespace std;

namespace w4 {
    Message::Message(){
        user = "";
        reply = "";
        message = "";
        atCheck = "";
    }
    
    Message::Message(ifstream& in, char c) : Message(){     //call default constructor to set to an empty state
        
        string tempString;
        getline(in, tempString);                         //store one line to a temporary string to be manipulated
        
        size_t initSpace = tempString.find(' ', 0);
        
        if (initSpace != string::npos){                    //if find() is unable to find the char, returns string::npos
            user = tempString.substr(0,initSpace);
            atCheck = tempString.substr(initSpace + 1, 1); //checks the next char after the space,
                                                           //this next char dictates if we have a reply or not (if its '@')
            
            if (atCheck == "@"){
                string replyMsg  = tempString.substr(initSpace + 1, string::npos); //replyMsg is another temporary string that is to be manipulated
                size_t replyMsgSpace = replyMsg.find(' ', 0);                      //finds the first space char to separate the reply from the message
                reply = replyMsg.substr(1, replyMsgSpace - 1);
                message = replyMsg.substr(replyMsgSpace + 1, string::npos);
            } else {                                       //if find fails to find '@', then set the remainder of the string to message
                message = tempString.substr(initSpace + 1, string::npos);
            }
        }
    }
    
    bool Message::empty() const{
        return user == ""  || message == "";
    }
    
    void Message::display(std::ostream& os) const{
        
        if (!empty()){
            os << "Message" << endl;
            os << " User  : " << user << endl;
            if (atCheck == "@")
                os << " Reply : " << reply << endl;
            os << " Tweet : " << message << endl << endl;
        }
    }
}
