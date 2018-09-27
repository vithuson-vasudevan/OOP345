//includes
#include "Grades.h"
//namespaces
using namespace w6;
using namespace std;

int main(int argc, char* argv[]) {
	try{
		 if (argc != 2) {
		    cerr << argv[0] <<": incorrect number of arguments\n";
			cerr << "Usage: " << argv[0] << " file_name\n"; 
			return 1;
		}

	Grades grades(argv[1]);

	string (*letter)(double)=[](double grade)->string{
		if(grade>89)
			return "A+";
		else if(grade >79)
			return "A";
		else if(grade >74)
			return "B+";
		else if(grade >69)
			return "B";
		else if(grade >64)
			return "C+";
		else if(grade >59)
			return "C";
		else if(grade >54)
			return "D+";
		else if(grade >49)
			return "D";
		else
			return "F";
	};	  

	grades.displayGrades(cout,letter);

	cout << "Press any key to continue ... ";
    cin.get();

	 }
	catch(const char * error){
		cerr << error << endl;	
	 }
	
}
