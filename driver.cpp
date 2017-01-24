#include <iostream>
#include "Student.h"

int main(int argc, char **argv){

	Student c("Joe Schmoe", 12345);
	std::cout << c.getNumber() << ": " << c.getName() << std::endl;
	int num_grades = c.getNumGrades();
	float * grades = c.getGrades();
	for(int i=0; i<num_grades; i++){
		std::cout << grades[i] << "\t";
	}
	std::cout << std::endl;

	c.addGrade(100);
	c.addGrade(71);
	c.addGrade(93);
	c.addGrade(85);
	c.addGrade(76);
	c.addGrade(92);
	c.addGrade(100);
	c.addGrade(87);
	c.addGrade(85);
	c.addGrade(101);
	c.addGrade(91);
	c.addGrade(77);

	std::cout << c.getNumber() << ": " << c.getName() << std::endl;
	num_grades = c.getNumGrades();
	grades = c.getGrades();
	for(int i=0; i<num_grades; i++){
		std::cout << grades[i] << "\t";
	}
}
