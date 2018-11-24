//
//  Notifications.cpp
//  lab4
//
//  Created by mon sta cruz on 2018-09-26.
//  Copyright © 2018 mon. All rights reserved.
//

#include <iostream>
#include "Notifications.h"
#include "Message.h"

using namespace std;

namespace w4{
    const int MAX = 10;
    
    Notifications::Notifications(){
        
        msg = new Message[MAX];
        msgCnt = 0;
    }
    
    Notifications::Notifications(Notifications& input){
        cout << "copy constructor" << endl;
        *this = input;
    }
    
    Notifications::Notifications(Notifications&& input){
        cout << "inside move constructor" << endl;
        *this = std::move(input);
    }
    
    Notifications& Notifications::operator=(Notifications& input){
        cout << "inside copy assignment" << endl;
        if(this != &input){
            msgCnt = input.msgCnt;
            delete [] msg;
            msg = nullptr;
            msg = new Message[MAX];
            for(int i = 0; i < input.msgCnt; i++)
                msg[i] = input.msg[i];
        }
        return *this;
    }
    
    Notifications& Notifications::operator=(Notifications&& input){
        cout << "inside move assignment" << endl;
        if(this != &input){
            delete [] msg;
            msgCnt = input.msgCnt;
            msg = input.msg;
           // delete [] input.msg;
            input.msg = nullptr;
            input.msgCnt = 0;
        }
        return *this;
    }
    
    Notifications::~Notifications(){
        delete [] msg;
        msg = nullptr;
    }
    
    void Notifications::operator+=(const Message& _msg){
        if (msgCnt < MAX){
            msg[msgCnt] = _msg;
            msgCnt++;
        }
    }
    
    void Notifications::display(std::ostream& os) const {
        for (int i = 0; i < msgCnt; i++){
            msg[i].display(os);
        }
    }
}
