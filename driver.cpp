#include <iostream>
#include "Student.h"

std::ostream & operator<<(std::ostream & os, const Student & s){
	os << "+++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	os << s.getNumber() << " : " << s.getName() << " has " << s.getNumGrades() << " grades." << std::endl;
	os << "*====================Grades=====================*" << std::endl;
	float * grades = s.getGrades();
	int c = 0;
	for(int i=0; i<s.getNumGrades(); i++){
		os << grades[i] << "\t";
		c++;
		if(c % 5 == 0)
			os << std::endl;
	}
	os << std::endl;
	os << "+++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	return os;
}

int main(int argc, char **argv){

	// Create a new Student with the
	// "Normal" Constructor
	std::cout << "Create a new student using the \"Normal\" constructor." << std::endl;
	Student c("Joe Schmoe", 12345);
	// Output the Student info
	std::cout << c << std::endl;

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

	std::cout << "Now we will add grades to show the memory changes dynamically." << std::endl;
	std::cout << c << std::endl;

	// Now let's try out the Big Five!
	// First up: Copy Constructor.
	
	std::cout << "Now we will create a new student by the copy constructor." << std::endl;
	std::cout << "We do this by declaring a new Student with the first Student's" << std::endl;
	std::cout << "name in the constructor.  For instance, if we have Student c," << std::endl;
	std::cout << "we can create Student d with the line Student d(c)." << std::endl;
	Student d(c);
	d.addGrade(109);
	std::cout << d << std::endl;
	
	std::cout << "Move constructor will be called whenever we set up a Student" << std::endl;
	std::cout << "with a temporary object as the parameter to a new Student's" << std::endl;
	std::cout << "constructor." << std::endl;
	Student e( std::move(c.getStudent()));
	std::cout << e << std::endl;

	std::cout << "Copy assignment is called whenever we use the '='" << std::endl;
	std::cout << "operator to set an existing object equal to another object." << std::endl;
	std::cout << "If we had Student a and Student b we could say a = b to" << std::endl;
	std::cout << "invoke it." << std::endl;
	c = e;
	std::cout << c << std::endl;

	std::cout << "Similarly, if we want to set an already existing object" << std::endl;
	std::cout << "equal to an rvalue we would use the move operator.  It" << std::endl;
	std::cout << "would be invoked automatically when we say a = b if b were" << std::endl;
	std::cout << "an rvalue." << std::endl;
	c = d.getStudent();
	std::cout << c << std::endl;
}
