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
}

// Copy assignment.  Basically the same code as for
// the copy constructor.  But doesn't have to be...
Student & Student::operator= ( const Student & rhs){
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

// Destructor
Student::~Student(){
	delete[] grades;
}

/*
 * Accessors and Mutators
 */

void Student::setName( const std::string & name ){
	this->name = name;
}

std::string Student::getName() const{ 
	return name;
}
void Student::setNumber( const int number ){
	student_number = number;
}
int Student::getNumber() const{
	return student_number;
}

void Student::addGrade ( const double grade ){
	if(grades[num_grades - 1] != -1){
		num_grades += 10;
		float * tmp = new float[num_grades];
		for(int i=0; i<num_grades; i++){
			tmp[i] = -1;
		}
		for(int i=0; i<num_grades - 10; i++){
			tmp[i] = grades[i];
		}
		grades = tmp;
	}
	for(int i=0; i<num_grades; i++){
		if(grades[i] == -1){
			grades[i] = grade;
			return;
		}
	}
	
}

float * Student::getGrades () const{
	return grades;
}

int Student::getNumGrades() const {
	return num_grades;
}

