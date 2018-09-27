//includes
#include "Grades.h"
#include <sstream>
//namespaces
using namespace w6;
using namespace std;

Grades::Grades()
{
	
}

Grades::Grades(const char* file)
{
	ifstream fin(file);
	string str;
	int    tmp_id;
	double tmp_grades;
	int count = 0, max = 0;

	if(fin)
	{
		while(getline(fin,str))
		{
			max++;
		}
		
		fin.clear();
		fin.seekg(0);
		
		do
		{
			fin >> tmp_id;
			fin >> tmp_grades;
			student_id.push_back(tmp_id);
			grade.push_back(tmp_grades);
			
			count++;
		} while(count < max);
		
		fin.close();
	}
	else
	{
		throw "File can not be found";
	
	}
}

void Grades::displayGrades(ostream& os, string (*letter)(double)) const
{
	auto stu_it    = student_id.begin();
	auto grade_it  = grade.begin(); 
	for(stu_it < student_id.end(); stu_it++ , grade_it++)
	{
		os << *stu_it << ' '<< *grade_it << ' '<< letter(*grade_it) << endl;
	}
}
