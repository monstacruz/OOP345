// Name: Mon Clarence Santa Cruz
// Seneca Student ID: 031608144
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: December 3, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef TASK_H
#define TASK_H

#include <deque>

#include "Item.h"
#include "CustomerOrder.h"


class Task : public Item{
    std::deque<CustomerOrder> m_order;
    Task* m_pNextTask;
    
public:
    Task();
    Task(const std::string&);
    
    Task(const Task&) = delete;
    Task(Task&&) = delete;
    Task& operator= (const Task&) = delete;
    Task& operator= (Task&&) = delete;
    
    void runProcess(std::ostream&);
    bool moveTask();
    void setNextTask(Task&);
    bool getCompleted(CustomerOrder&);
    void validate(std::ostream&);
    
    Task& operator += (CustomerOrder&&);

};

#endif /* Task_h */



