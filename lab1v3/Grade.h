#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;


class Grade
{
private:
	// DATA
	string class_name;
	string student_ID;
	string letter;
	
public:
	// CONSTRUCTORS
	Grade(string class_name_in, string attached_ID_in, string letter_in);
	~Grade();

	// MUTATORS
	bool operator < (Grade g) const;
	
	/* Sends a letter to be processed by the student object in the all_students vector associated with that letter grade. */
	void sendLetter();

	// ANALYZERS
	string getClass();
	string getAttachedID();
	string getLetter();
};
