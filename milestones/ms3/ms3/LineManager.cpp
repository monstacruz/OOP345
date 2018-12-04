// Name: Mon Clarence Santa Cruz
// Seneca Student ID: 031608144
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: December 3, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <fstream>

#include "LineManager.h"
#include "Utilities.h"

#include <iostream>
using namespace std;


LineManager::LineManager(const std::string& input, std::vector<Task*>& tasks, std::vector<CustomerOrder>& orders){
    
    
    std::vector<std::string> taskSequence;
    std::ifstream ifs(input);
    
    do {
        std::string tmp;
        getline(ifs, tmp);
        taskSequence.push_back(tmp);
    } while (!ifs.eof());
    
    for (size_t i = 0; i < tasks.size(); i++){
        for (size_t j = 0; j < taskSequence.size(); j++){
            Utilities obj;
            bool more;
            size_t pos = 0;
            std::string firstHalf = obj.extractToken(taskSequence[j], pos, more);
            if (tasks[i]->getName() == firstHalf){
                std::string secondHalf;
				if (more) {
					secondHalf = obj.extractToken(taskSequence[j], pos, more);
					secondHalf.pop_back();
				}
                for (size_t k = 0; k < tasks.size(); k++){
                    if (tasks[k]->getName() == secondHalf){
                        tasks[i]->setNextTask(*tasks[k]);
                    }
                }
            }
        }
    }
    
    for (size_t i = 0; i < tasks.size(); i++)
        AssemblyLine.push_back(tasks[i]);
    
    for (size_t i = 0; i < orders.size(); i++){
        ToBeFilled.push_back(std::move(orders[i]));
    }
    
    m_cntCustomerOrder = ToBeFilled.size();
    
}

bool LineManager::run(std::ostream& os){
    bool result = false;
    if (ToBeFilled.size() == m_cntCustomerOrder){
        for (size_t i = 0; i < m_cntCustomerOrder; ++i){
            *AssemblyLine.back() +=(std::move(ToBeFilled.front()));
            ToBeFilled.pop_front();
        }
    }
    
    for (size_t i = 0; i < AssemblyLine.size(); i++){
        AssemblyLine[i]->runProcess(os);
    }
    
    for (size_t i = 0; i < AssemblyLine.size(); i++){
        if (i != 3)
            AssemblyLine[i]->moveTask();
    }

	CustomerOrder tmp;
	if (AssemblyLine[3]->getCompleted(tmp))
		Completed.push_back(std::move(tmp));
	if (Completed.size() == m_cntCustomerOrder)
		result = true;
    return result;
}

void LineManager::displayCompleted(std::ostream& os) const{
	for (size_t i = 0; i < Completed.size(); i++) {
		Completed[i].display(os);
	}
}
void LineManager::validateTasks() const{
    for (size_t i = 0; i < AssemblyLine.size(); i++)
        AssemblyLine[i]->validate(std::cout);
}


//dear future mon: go fuck yourself lol
//                 you made stupid life decisions now youre here panicking
