#include <iostream>
#include "Student.h"

std::ostream & operator<<(std::ostream & os, const Student & s){
	os << s.getNumber() << " : " << s.getName() << " has " << s.getNumGrades() << " grades." << std::endl;
	return os;
}

int main(int argc, char **argv){

	// Create a new Student with the
	// "Normal" Constructor
	Student c("Joe Schmoe", 12345);
	// Output the Student info
	
	std::cout << c << std::endl;

	// Print each of the grades separated by a tab
	// Should all be '-1' at this point, meaning no
	// entry.
	int num_grades = c.getNumGrades();
	float * grades = c.getGrades();
	for(int i=0; i<num_grades; i++){
		std::cout << grades[i] << "\t";
	}
	std::cout << std::endl;

	// Add grades to show how memory allocation
	// changes.  After we add more than 10
	// grades the array grows itself.  Grows
	// by an additional 10 each time limit is
	// reached.
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

	std::cout << c << std::endl;
	num_grades = c.getNumGrades();
	grades = c.getGrades();
	for(int i=0; i<num_grades; i++){
		std::cout << grades[i] << "\t";
	}

	// Now let's try out the Big Five!
	// First up: Copy Constructor.
	Student d(c);
	std::cout << d << std::endl;
	d.addGrade(109);
	num_grades = d.getNumGrades();
	grades = d.getGrades();
	for(int i=0; i<num_grades; i++){
		std::cout << grades[i] << "\t";
	}
	std::cout << std::endl;
		
	// Now for the copy operator=
	Student e = c;
	std::cout << e << std::endl;
        num_grades = e.getNumGrades();
        grades = e.getGrades();
        for(int i=0; i<num_grades; i++){
                std::cout << grades[i] << "\t";
        }
        std::cout << std::endl;
	
	// Now the move constructor
	Student f = c.getStudent();
	std::cout << f << std::endl;
        num_grades = f.getNumGrades();
        grades = f.getGrades();
        for(int i=0; i<num_grades; i++){
               std::cout << grades[i] << "\t";
        }
        std::cout << std::endl;

	// Now the copy operator=
	Student g("Lost Student", 39192);
	g = e;
	std::cout << g << std::endl;
        num_grades = g.getNumGrades();
        grades = g.getGrades();
        for(int i=0; i<num_grades; i++){
               std::cout << grades[i] << "\t";
        }
        std::cout << std::endl;

	Student h("Move lost student", 29395);
	h = g.getStudent();
	std::cout << h << std::endl;
        num_grades = h.getNumGrades();
        grades = h.getGrades();
        for(int i=0; i<num_grades; i++){
               std::cout << grades[i] << "\t";
        }
        std::cout << std::endl;
	
}
