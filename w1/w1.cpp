//includes
#include <iostream>
#include "process.h"
#include "CString.h"
//namespaces
using namespace w1;
using namespace std;

int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		cout << "Insufficient number of arguments - minimum 1 required" << endl;
	}
	else
	{
		cout << "Maximum number of characters stored : " << argc << endl;

		for(int i=0;i<(argc-1);i++)
		{
			cout<<i<<":";
			process(argv[i+1]);
			cout << endl;
		}
	}

	return 0;	
}
