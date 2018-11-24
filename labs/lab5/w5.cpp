// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22


// Name: Mon Clarence Santa Cruz
// Seneca Student ID: 031608144
// Seneca email: mcsantacruz1@myseneca.ca
// Date of completion: October 8, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#include <iostream>
#include "Grades.h"
#include "Letter.h"

using namespace sict;
using namespace std;

int main(int argc, char* argv[]) {

	std::cout << "Command Line: ";
	for (int i = 0; i < argc; i++)
		std::cout << argv[i] << ' ';
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}

	//TODO: Update the main functions as per the specifications here

	auto letter = [](double grade) -> Letter {
		Letter result;
		if (grade >= 90)
			result = Letter::AP;
		else if (grade >= 80)
			result = Letter::A;
		else if (grade >= 75)
			result = Letter::BP;
		else if (grade >= 70)
			result = Letter::B;
		else if (grade >= 65)
			result = Letter::CP;
		else if (grade >= 60)
			result = Letter::C;
		else if (grade >= 55)
			result = Letter::DP;
		else if (grade >= 50)
			result = Letter::D;
		else
			result = Letter::F;

		return result;
	};


	try {
		Grades grades(argv[1]);
		grades.displayGrades(std::cout, letter);
	}
	catch (const char * output) {
		cout << output << endl;
	}
  
    return 0;
}
