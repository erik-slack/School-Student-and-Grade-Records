#include "Grade.h"


// CONSTRUCTORS
	Grade::Grade(string class_name_in, string attached_ID_in, string letter_in)
	{
		//cout << class_name_in << "\n" << attached_ID_in << "\n" << letter_in << "\n" << endl;
		class_name = class_name_in;
		student_ID = attached_ID_in;
		letter = letter_in;
	}
	Grade::~Grade(){}

// MUTATORS
	bool Grade::operator < (Grade g) const 
	{
		return student_ID < g.student_ID ||
		(student_ID == g.student_ID && class_name < g.class_name) ||
		(student_ID == g.student_ID && class_name == g.class_name && letter < g.letter);
	}
	
// ANALYZERS
	string Grade::getClass()
	{
		return class_name;
	}

	string Grade::getAttachedID()
	{
		return student_ID;
	}

	string Grade::getLetter()
	{
		return letter;
	}

// PRINTERS
