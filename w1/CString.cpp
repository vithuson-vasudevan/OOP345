//includes
#include "CString.h"
#include <cstring>
//namespaces
using namespace std;

namespace w1
{

	CString::CString(char* cs)
	{
		strncpy(_cs, cs, MAX);
		_cs[MAX] = '\0';
	
	}

	void CString::display(ostream& os)
	{
		os << _cs;
	}

	ostream& operator<<(ostream& os, CString cst)
	{
		cst.display(os);
		return os;
	}

}