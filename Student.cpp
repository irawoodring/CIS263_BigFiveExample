#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

// "Normal" constructor.  Requires a string
// and an int.

Student::Student( std::string name, int number ){
	this->name = name;
	student_number = number;
	num_grades = 10;
	// Start with space for ten grades.
	// We will grow it as we need more space.
	grades = new float[num_grades];	
	// Initialize grades to -1
	for(int i=0; i< num_grades; i++){
		grades[i] = -1;
	}
}

/*
 * The "Big Five"
 * Needed because we are going to be using
 * dynamically allocated memory (since grades
 * is a dynamically sized array).
 * C++ provides these for us for all classes
 * but the default versions don't work when
 * we have dynamically allocated memory.
 */

// Copy Constructor.  Needed in order to
// create a new object with the same values
// as another object.
Student::Student( const Student & rhs ){
	std::cout << "***** COPY CONSTRUCTOR CALLED *****" << std::endl;
	name = rhs.name;
	student_number = rhs.student_number;
	num_grades = rhs.num_grades;

	// Here, the default constructor would have
	// copied grades = rhs.grades.  This would
	// have merely copied the pointer value,
	// causing this Student object to
	// point to the same memory as the prior
	// object's grades.  This would create what
	// is called a "shallow copy".  We want a
	// "deep copy", meaning we create copies of
	// the dynamic memory regions as well.

	// First, allocate new memory for this object.
	grades = new float[num_grades];
	// Copy the other object's grades into this object.
	for(int i=0; i<num_grades; i++){
		grades[i] = rhs.grades[i];
	}		
}

// Move Constructor
Student::Student( Student && rhs){
	std::cout << "***** MOVE CONSTRUCTOR CALLED *****" << std::endl;
	name = std::move(rhs.name);	// Simply copy primitives...
	student_number = rhs.student_number;
	num_grades = std::move(rhs.num_grades);
	
	// Now, we are going to steal rhs's pointer!
	// She isn't going to need it anymore anyway,
	// since she is a temporary object.  We set
	// the rhs's pointer to nullptr to make sure
	// time isn't wasted in trying to delete memory
	// multiple times.
	grades = rhs.grades;
	rhs.grades = nullptr;
}

// Copy assignment.  Basically the same code as for
// the copy constructor.  But doesn't have to be...
Student & Student::operator= ( const Student & rhs){
	std::cout << "***** COPY OPERATOR= CALLED *****" << std::endl;
	name = rhs.name;
	student_number = rhs.student_number;
	num_grades = rhs.num_grades;
	// First, allocate new memory for this object.
	grades = new float[num_grades];
	// Copy the other object's grades into this object.
	for(int i=0; i<num_grades; i++){
		grades[i] = rhs.grades[i];
	}		
	return *this;
}

// Move assignment.  Same as move constructor (but
// once again doesn't have to be).
Student & Student::operator= ( Student && rhs){
	std::cout << "***** MOVE OPERATOR= CALLED *****" << std::endl;
	name = rhs.name;	// Simply copy primitives...
	student_number = rhs.student_number;
	num_grades = rhs.num_grades;
	
	// Now, we are going to steal rhs's pointer!
	// She isn't going to need it anymore anyway,
	// since she is a temporary object.  We set
	// the rhs's pointer to nullptr to make sure
	// time isn't wasted in trying to delete memory
	// multiple times.
	grades = rhs.grades;	// Copy the other pointer
	rhs.grades = nullptr;	// Set the other to nullptr
	return *this;
}

// Destructor.  Since we dynamically allocated memory we
// must release manually it when our object is destroyed.
Student::~Student(){
	delete[] grades;
}

/*
 * Accessors and Mutators
 */

// Set this object's internal state to the parameter passed in.
void Student::setName( const std::string & name ){
	this->name = name;
}

// Return this object's name.
std::string Student::getName() const{ 
	return name;
}

// Set this objects student_number to the value of "number".
void Student::setNumber( const int number ){
	student_number = number;
}

// Return this object's student number.
int Student::getNumber() const{
	return student_number;
}

// Add a new grade entry for this student.
// If there is not enough space in our array
// we will allocate more space, and copy the
// old values in.  Not written for efficiency. 
void Student::addGrade ( const double grade ){
	// Since we initialized our values to -1
	// we can check if the array is currently
	// full by checking for -1 in the last
	// array spot.
	if(grades[num_grades - 1] != -1){
		// Simply add ten more.
		num_grades += 10;
		// Allocate new space.  Use a temporary
		// array so we don't lose our current
		// values.
		float * tmp = new float[num_grades];
		// Set the elements to -1.
		for(int i=0; i<num_grades; i++){
			tmp[i] = -1;
		}
		// Copy the old values in.
		for(int i=0; i<num_grades - 10; i++){
			tmp[i] = grades[i];
		}
		grades = tmp;
	}
	// Now add the new value in the first
	// available spot.
	for(int i=0; i<num_grades; i++){
		if(grades[i] == -1){
			grades[i] = grade;
			return;
		}
	}
	
}

// Return a pointer the array of grades.
float * Student::getGrades () const{
	return grades;
}

// Return the number of grades we are currently housing.
int Student::getNumGrades() const {
	return num_grades;
}

// Return an rvalue Student.
// Used to illustrate concepts.
Student Student::getStudent() {
	Student s("RValue Student", 81818);
	return s;
}

