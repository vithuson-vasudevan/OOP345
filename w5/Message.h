#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED
//includes
#include <string>
#include <fstream>
#include <iostream>
//namespaces
using namespace std;

namespace w5{
	class Message
	{
		string msg;
		public:
		Message();
		Message(ifstream& in, char c);
		bool empty() const;
		void display(ostream&) const;
	};

}

#endif
