#include "Student.h"
#include <cctype>
#include <map>


// CONSTRUCTORS
	Student::Student(string name_in, string ID_in, string phone_in, string address_in)
	{
		name = name_in;
		ID = ID_in;
		telephone = phone_in;
		address = address_in;
		grade_sum = 0;
		grade_number = 0;
	}
	Student::~Student(){}

// MUTATORS
	bool Student::operator < (Student s) const 
	{
		return ID < s.ID;
	}

// IMPORTERS
	bool Student::gradeConverter(string letter_in)
	{
		map<string, double> grade_conversion;
		grade_conversion["A"] = 4;
		grade_conversion["A-"] = 3.7;
		grade_conversion["B+"] = 3.4;
		grade_conversion["B"] = 3;
		grade_conversion["B-"] = 2.7;
		grade_conversion["C+"] = 2.4;
		grade_conversion["C"] = 2;
		grade_conversion["C-"] = 1.7;
		grade_conversion["D+"] = 1.4;
		grade_conversion["D"] = 1;
		grade_conversion["D-"] = .7;
		grade_conversion["E"] = 0;

		bool is_valid = false;

		// if (letter_in == "A" || letter_in == "A-" || letter_in == "B+" || letter_in == "B" || letter_in == "B-" || letter_in == "C+" || 
		//letter_in == "C" || letter_in == "C-" || letter_in == "D+" || letter_in == "D" || letter_in == "D-" || letter_in == "E")
		//{
			is_valid = true;
			//cout << grade_number;
			grade_number++;
			//cout << grade_sum;
			grade_sum += grade_conversion[letter_in];
	     //}

		return is_valid;
	}

// ANALYZERS
	double Student::getGrade_Sum()
	{
		return grade_sum;
	}

	int Student::getGrade_Number()
	{
		return grade_number;
	}

	string Student::getName()
	{
		return name;
	}

	string Student::getID()
	{
		return ID;
	}

	string Student::getPhone()
	{
		return telephone;
	}

	string Student::getAddress()
	{
		return address;
	}
