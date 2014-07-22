#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "School.h"
#include "Student.h"


int main(int argc, char* argv[])
{
	// This object will contain all of the information that is imported and exported in this application.
	// This program can be easily expanded to work with more than one school.
	School school1;

	string students_choice = argv[1];
	string grades_choice = argv[2];
	string query_choice = argv[3];
	string report_choice = argv[4];

	// Loads and Sorts Student Vector
	bool students_loaded = school1.loadStudents(students_choice);
	if (students_loaded == true)
	{
		cout << endl;
		cout << school1.printStudents();
	}
	
	// Loads and Sorts Grades Vector
	bool grades_loaded = school1.loadGrades(grades_choice, students_loaded);
	if (grades_loaded == true)
	{
		// Prints Student and Grade Vectors
		cout << endl;
		cout << school1.printGrades();
	}
	
	// Calculates and Prints Students' GPA
	bool query_loaded = school1.loadQuery(query_choice);
	if (query_loaded == true && students_loaded == true)
	{
		bool is_save = false;
		cout << endl;
		cout << school1.printGPA(is_save) << endl;
	}
	
	// Saves the Report
	school1.saveReport(report_choice, students_loaded, grades_loaded, query_loaded);
	
	//cin.get();
	return 0;
}
