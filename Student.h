#ifndef H_STUDENT
#define H_STUDENT

#include <string>
#include <vector>

class Student {

	public:

		// "Normal" Constructor
		Student( std::string name, int number);

		/*
		 * The "Big Five"
		 * Needed because we are going to be using
		 * dynamically allocated memory.
		 */

		// Copy Constructor
		Student( const Student & rhs );
		// Move Constructor
		Student( Student && rhs);
		// Copy assignment
		Student & operator= ( const Student & rhs);
		// Move assignment
		Student & operator= ( Student && rhs);
		// Destructor
		~Student();

		/*
		 * Accessors and Mutators
		 */

		void setName( const std::string & name );
		std::string getName() const;
		void setNumber( const int number );
		int getNumber() const;
		void addGrade ( const double grade );
		float * getGrades () const;
		int getNumGrades () const;
		Student getStudent();

	private:
		// The student's name
		std::string name;
		// The unique student number
		int student_number;
		// An array of grades.  We don't know
		// at compile time how many there will be
		// so we have to allocate it dynamically.
		// This will cause us to have to write the
		// Big Five.
		float * grades;		
		// The number of grades we are keeping
		int num_grades;	
};

#endif
