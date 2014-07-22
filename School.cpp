#include "School.h"
#include <algorithm>
#include <vector>
#include <cctype>
#include <sstream>
#include <iostream>
#include <iomanip>


// CONSTRUCTORS
	School::School()
	{}
	School::~School()
	{}

// MUTATORS
	void School::gradeSorter()
	{
		sort(all_grades.begin(), all_grades.end());
	}

	void School::studentSorter()
	{
		sort(all_students.begin(), all_students.end());
	}

// EXPORTERS
	void School::saveReport(string report_choice, bool students_loaded, bool grades_loaded, bool query_loaded)
	{
		ofstream out_file;
		string file_choice = report_choice;

		out_file.open(file_choice);
		if (students_loaded == true)
		{
			out_file << printStudents();
		}
		if (grades_loaded == true)
		{
			out_file << endl;
			out_file << printGrades();
		}
		if (query_loaded == true)
		{
			bool is_save = true;
			out_file << endl;
			out_file << printGPA(is_save);
		}
	}

// IMPORTERS
	int School::getFileLines(string file_choice)
	{ // This function assists the Load Functions with knowing how many times to iterate the getline() functions by prereading the file.
		ifstream in_file;
		in_file.open(file_choice);
		int line_count = 0;

		do
		{
			line_count++;
		}
		while (!getline(in_file, file_choice).fail());
		
		line_count--;

		return line_count;
	}

	bool School::loadStudents(string students_choice)
	{	
		bool is_working = false;
		ifstream in_file;
		string file_choice = students_choice;

		cout << "File name to load (file_name.txt): \t" << file_choice << endl;
		//cin >> file_choice;
		in_file.open(file_choice);
	
		int line_count = 0;
		line_count = getFileLines(file_choice);
		
		if (hasLines(line_count) == false)
		{
			return is_working;
		}
		else
		{
			for (int i = line_count; i > 0; i = i - 4)
			{
				string name_in, address_in, ID_in, phone_in = "";

				getline(in_file, ID_in);
				getline(in_file, name_in);
				getline(in_file, address_in);
				getline(in_file, phone_in);

				//if (checkDuplicate(ID_in) == true)
				//{
					//cout << "Duplicate student ommitted." << endl;
				//}
				//else
				//{
				all_students.push_back(Student(name_in, ID_in, phone_in, address_in));
				//}
			}
			is_working = true;
		}
		
		studentSorter();
		return is_working;
	}

	bool School::loadGrades(string grades_choice, bool students_loaded)
	{
		bool is_working = false;
		ifstream in_file;
		string file_choice = grades_choice;
		cout << "File name to load (file_name.txt): \t" << file_choice << endl;
		//cin >> file_choice;
		in_file.open(file_choice);

		int line_count = 0;
		line_count = getFileLines(file_choice);

		if (hasLines(line_count) == false)
		{
			return is_working;
		}
		else
		{
			for (int i = line_count; i > 0; i = i - 3)
			{
				string class_name_in, attached_ID_in, letter_in = "";

				getline(in_file, class_name_in);
				getline(in_file, attached_ID_in);
				getline(in_file, letter_in);
				
				if (students_loaded == true && checkDuplicate(attached_ID_in) == true)
				{
					all_students[(getPerson_byID(attached_ID_in))].gradeConverter(letter_in);
				}

				Grade loaded_grade (class_name_in, attached_ID_in, letter_in);
				all_grades.push_back(loaded_grade);
			}
			is_working = true;
		}
		gradeSorter();
		return is_working;
	}

	bool School::loadQuery(string query_choice)
	{
		ifstream in_file;
		string file_choice = query_choice;
		cout << "File name to load (file_name.txt): \t" << file_choice << endl;
		//cin >> file_choice;
		in_file.open(file_choice);
	

		int line_count = 0;
		line_count = getFileLines(file_choice);
		if (hasLines(line_count) == false)
		{
			return false;
		}
		else
		{
			for (int i = line_count; i > 0; i--)
			{
				string ID_in = "";

				getline(in_file, ID_in);
			
				query_list.push_back(ID_in);
				//cout << ID_in << endl;
			}
		}
		return true;
	}

// ANALYZERS
	int School::getPerson_byID(string ID_in)
	{
		int temp = -1;
		for (int i = 0; i < all_students.size(); i++)
		{
			if (ID_in == all_students[i].getID()) 
			{
				temp = i; // Return a the index number for the Person with the ID that matches;
				break;
			}
		}
		return temp; // Returns -1 otherwise.
	}

	int  School::getSize(string vector_chooser)
	{
		int size_out = 0;
		if (vector_chooser == "student")
		{
			size_out = all_students.size();
			return size_out;
		}
		else if (vector_chooser == "grade")
		{
			size_out = all_grades.size();
			return size_out;
		}
		else
		{
			cout << "Vector_chooser didn't choose a valid vector." << endl;
		}
		return 0;		
	}

	double School::calculateGPA(int index)
	{
		double average = 0;

		if (all_students[index].getGrade_Number() == 0)
		{
			average = 0.00;
		}
		else
		{
			average = all_students[index].getGrade_Sum() / all_students[index].getGrade_Number();
		}
		
		return average;
	}

// PRINTERS
	string School::printStudents()
	{
		string vector_chooser = "student";
		stringstream ss;

		for (int i = 0; i < getSize(vector_chooser); i++)
		{
			ss << all_students[i].getName() << endl;
			ss << all_students[i].getID() << endl;
			ss << all_students[i].getPhone() << endl;
			ss << all_students[i].getAddress() << endl;
		}
		
		return ss.str();
	}

	string School::printGrades()
	{
		string vector_chooser = "grade";
		stringstream ss;

		for (int i = 0; i < getSize(vector_chooser); i++)
		{
			ss << all_grades[i].getAttachedID() << "   " <<
				all_grades[i].getLetter() << "   " <<
				all_grades[i].getClass() << endl;
		}
		
		return ss.str();
	}
	
	string School::printGPA(bool is_save)
	{
		string vector_chooser = "student";
		stringstream ss;
		for (int j = 0; j < query_list.size(); j++)
		{
			bool missing_info = true;
			string id_queried  = query_list[j];
			for (int i = 0; i < getSize(vector_chooser); i++)
			{
				string id_temp = all_students[i].getID();
				if (id_temp == id_queried)
				{
					ss << fixed << setprecision(2) << setfill('0') << 
					all_students[i].getID() << "    " << 
					calculateGPA(i) << "    " << 
					all_students[i].getName() << endl;
					missing_info = false;
					break;
				}
				if (missing_info == true && i == getSize(vector_chooser) - 1 && is_save != true)
				{
					cout << "\nError: There was a student ID in the query file that does not belong to any student on file.  \nThis may make the report inaccurate.  Please revise query or update student file.\n" << endl;
				}
			}
		}

		return ss.str();
	}

// VALIDATORS
	bool School::hasLines(int line_count)
	{
		bool has_lines = false;
		if (line_count == 0)
		{
			cout << "This is an empty file." << endl;
		}
		else
		{
			has_lines = true;
		}
		return has_lines;
	}

	bool School::checkDuplicate(string ID_in)
	{
		bool is_duplicate = false;

		if (getPerson_byID(ID_in) != -1)
		{
			is_duplicate = true;
		}

		return is_duplicate;
	}
