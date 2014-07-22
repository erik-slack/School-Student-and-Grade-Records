#pragma once
#include "Student.h"
#include "Grade.h"
using namespace std;


class School
{
private:
	// DATA
	vector<Student> all_students;
	vector<Grade> all_grades;
	vector<string> query_list;

public:
	// CONSTRUCTORS
	School();
	~School();

	// MUTATORS
	/* Sorts the all_grades vector by ID # then by Course Name then by Grade. */
	void gradeSorter();
	/* Sorts the all_students vector by ID. */
	void studentSorter();
	
	// EXPORTERS
	/* Saves all that is printed by printStudents, printGrades, and printGPA to a text file determined by command line argument #4. */
	void saveReport(string report_choice, bool students_loaded, bool grades_loaded, bool query_loaded);

	// IMPORTERS
	/* Tells how many lines a text file has before it is read in. */
	int getFileLines(string file_choice);
	/* Imports command line argument #1 and makes each 4 lines into a student in the all_students vector. */
	bool loadStudents(string students_choice);
	/* Imports command line argument #2 and makes each 3 lines into a grade in the all_grades vector. */
	bool loadGrades(string grades_choice, bool students_loaded);
	/* Imports command line argument #3 and makes each line into a query in the query_list vector.  */
	bool loadQuery(string query_choice);

	// ANALYZERS
	/* Finds the vector index of a person based on their ID. */
	int getPerson_byID(string ID_in);
	/* Tells the size of either the all_students or the all_grades vector based on the argument passed with it. */
	int getSize(string vector_chooser);
	/* Calculates the GPA of a student based on the grades that have been imported and returns a double containing that average. */
	double calculateGPA(int index);

	// PRINTERS
	/* Returns a string that contains all of the students in the all_students vector. */
	string printStudents();
	/* Returns a string that contains all of the grades in the all_grades vector. */
	string printGrades();
	/* Returns a string that contains the students--and their ID's and calculated GPA's--whose ID's are listed in the query_list vector. */
	string printGPA(bool is_save);
	/* Prints Duplicates; OPTIONAL */
	

	// VALIDATORS
	/* Makes sure a .txt file is readable. */
	bool hasLines(int line_count);
	/* Determines whether a student in command line argument #1 is a duplicate student. */
	bool checkDuplicate(string ID_in);
};
