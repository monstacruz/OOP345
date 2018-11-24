//
//  Notifications.h
//  lab4
//
//  Created by mon sta cruz on 2018-09-26.
//  Copyright © 2018 mon. All rights reserved.
//

#ifndef W4_NOTIFICATIONS_H
#define W4_NOTIFICATIONS_H

#include <iostream>

namespace w4{
    class Message;
    
    class Notifications{ // the Notifications class contains a pointer to a Message type (to be used to make an array of Messages of size 10)
        Message * msg;
        int msgCnt;
    public:
        Notifications();
        Notifications(Notifications &);
        Notifications(Notifications&&);
        
        Notifications& operator=(Notifications &);
        Notifications& operator=(Notifications &&);
        
        ~Notifications();
        
        void operator+=(const Message& _msg);
        void display(std::ostream& os) const;
    };
}


#endif /* Notifications_h */
