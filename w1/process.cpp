//includes
#include "process.h"
#include <iostream>
#include <cstring>
//namespace
namespace w1 
{
	void process(char* str)
	{
		CString cstr(str);
		std::cout << cstr;
	}
}
