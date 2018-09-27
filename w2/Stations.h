//includes
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Station.h"
//namespaces
using namespace std;

namespace w2
{
	class Stations
	{
		int stationCount;
		Station* stationTable;
		public:
		Stations(const char*);
		~Stations();
		void update();
		void restock();
		void report();
		
	};
}