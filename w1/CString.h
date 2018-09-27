#ifndef _CSTRING_
#define _CSTRING_
//defines
#define MAX 3
//includes
#include <iostream>
namespace w1
{
class CString
	{
		char _cs[MAX + 1];
		public:
	
		CString(char*);
		void display(std::ostream&);
	
	
	};
	std::ostream& operator<<(std::ostream&, CString);
}

#endif