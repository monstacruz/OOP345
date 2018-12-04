// Name: Mon Clarence Santa Cruz
// Seneca Student ID: 031608144
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: December 3, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Task.h"
#include <iostream>
using namespace std;

Task::Task() : Item(){
    m_pNextTask = nullptr;
}

Task::Task(const std::string& input) : Item(input) {
    m_pNextTask = nullptr;
}

Task& Task::operator += (CustomerOrder&& input){
    m_order.push_front(std::move(input));
    return *this;
}

void Task::runProcess(std::ostream& os){
    if (m_order.size() > 0){
        if (!m_order.back().getItemFillState(getName())){
            m_order.back().fillItem(*this, os);
        }
    }
}

bool Task::moveTask(){
    bool result = true;
    if (m_order.size() > 0){
        if (m_order.back().getItemFillState(getName())){
            *m_pNextTask += (std::move(m_order.back()));
            m_order.pop_back();
        }
    } else {
        result = false;
    }
    return result;
}

void Task::setNextTask(Task& input){
    m_pNextTask = &input;
}

bool Task::getCompleted(CustomerOrder& input){
    bool result = true;
    if (m_order.size() > 0){
		if (m_order.back().getOrderFillState()) {
			input = std::move(m_order.back());
			m_order.pop_back();
		}
		else {
			result = false;
		}
    } else {
        result = false;
    }
    return result;
}

void Task::validate(std::ostream& os){
    if (m_pNextTask != nullptr)
        os << getName() << " --> " << m_pNextTask->getName() << std::endl;
    else
        os << getName() << " --> END OF LINE" << std::endl;
}

