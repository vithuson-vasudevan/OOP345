//includes
#include "Station.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
//namespaces
using namespace std;

namespace w2
{
	
	Station::Station()
	{
		
	}

	Station::Station(ifstream &is)
	{
		string line;
		getline(is, line);
		auto cr = line.find('\r');
		if(cr != string::npos)
		{
			line.erase(cr);
		}

		stringstream ss(line);
		getline(ss, stationName, ';');
		
		ss >> passes[STUDENT_PASS];
		ss >> passes[ADULT_PASS];	
	}
	
	void Station::update()
	{
		int num;
		cout << stationName << "\n";
		cout << "Student Passes sold:";
		cin >> num;
		passes[STUDENT_PASS] -= num;
		cout <<"Adult Passes sold:";
		cin >> num;
		passes[ADULT_PASS] -= num;
	}
	
	void Station::restock()
	{
		int num;
		cout << stationName << "\n";
		cout << "Student Passes added:";
		cin >> num;
		passes[STUDENT_PASS] += num;
		cout <<"Adult Passes added:";
		cin >> num;
		passes[ADULT_PASS] += num;
	}
	
	void Station::report()
	{
		cout << setw(19) << left << stationName;
		cout << setw(6) << right << passes[STUDENT_PASS];
		cout << setw(6) << right << passes[ADULT_PASS];
		cout << "\n";
	}
}