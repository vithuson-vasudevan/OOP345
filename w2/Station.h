//#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
namespace w2
{
	enum PASS_TYPE {STUDENT_PASS, ADULT_PASS, PASS_COUNT};
	class Station
	{
		string stationName;
		int passes[PASS_COUNT];
		public:
		Station();
		Station(ifstream&);
		void update();
		void restock();
		void report();
	
		
	};

}
