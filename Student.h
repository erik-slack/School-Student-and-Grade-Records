#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>
using namespace std;


class Student
{
private:
	// DATA
	string name;
	string ID;
	string telephone;
	string address;

	double grade_sum;
	int grade_number;

public:
	// CONSTRUCTORS
	Student(string name, string ID, string phone_in, string address_in);
	~Student();

	// MUTATORS
	bool operator < (Student s) const;

	// IMPORTERS
	/* Converts letter grades into grade scores up to 4.0 and adds 1 to the total # of classes that person has taken. */
	bool gradeConverter(string letter_in);

	// ANALYZERS
	double getGrade_Sum();
	int getGrade_Number();

	string getName();
	string getID();
	string getPhone();
	string getAddress();
};
