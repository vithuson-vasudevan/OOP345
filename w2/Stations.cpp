//includes
#include "Stations.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
//namespaces
using namespace std;

namespace w2
{
	
	Stations::Stations(const char* filename)
	{
		ifstream is(filename);
		if(is.is_open())
		{
			string line;
			getline(is, line);
			auto cr = line.find('\r');
			if(cr != string::npos)
			{
				line.erase(cr);
			}
						
			stringstream ss(line);
			ss >> stationCount;

			char c;
			ss >> c;
			if(c != ';')
			{
				cerr << "Syntax error line 1: expected ';' found" << c << "\n";
				exit(2);
			}
			
			stationTable = new Station[stationCount];
			for(int station = 0; station < stationCount ; station++)
			{
				stationTable[station] = Station(is);
			}
			
			is.close();
		}
		else
		{
			cerr << "Cannot open file " << filename << "\n";
			exit(1);
		}
		
	}
	
	Stations::~Stations()
	{
		if(stationTable)
		{
			delete[] stationTable; //delete dynamic array
		}
	}

	void Stations::update()
	{
		cout << "\npasses Sold:\n";
		cout << "------------\n";

		for(int station = 0; station < stationCount; station++)
		{
			stationTable[station].update();
		}
		
	}

	void Stations::restock()
	{
		cout << "\npasses Added:\n";
		cout << "-------------\n";
		for(int station = 0; station < stationCount; station++)
		{
			stationTable[station].restock();
		}
	}


	void Stations::report()
	{
		cout << "\nPasses in stock : Student Adult\n";
		cout << "-------------------------------\n";
		for(int station = 0; station < stationCount; station++)
		{
			stationTable[station].report();
		}
		
	}

}