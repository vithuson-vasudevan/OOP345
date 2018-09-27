//includes
#include <typeinfo>
#include <iostream>
#include <fstream>
#include <vector>
//namespaces
using namespace std;
namespace w6{
	class Grades
	{	
	private:
		vector<int> student_id;
		vector<double> grade;
	public:
		Grades();
		Grades(const char*);
		void displayGrades(ostream&,string (*letter)(double)) const;
	};
}
