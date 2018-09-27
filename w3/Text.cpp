//includes
#include <fstream>
#include <string>
#include <iostream>
#include "Text.h"
//namespaces
using namespace std;

namespace w3
{
	Text::Text():count(0),lineTable(nullptr)
	{
		
	}
	
	Text::Text(const char* filename):count(0),lineTable(nullptr)
	{
		ifstream is(filename);
		if(is.is_open())
		{
			string line;
			while(getline(is,line))
			{
				count++;
			}
			cout << "Read" << count << "lines\n";
			
			lineTable= new string[count];
			is.clear();
			is.seekg(0);
			
			for(int line=0;line < count;line++)
			{
				getline(is,lineTable[line]);
				auto cr = lineTable[line].find('\r');
				if(cr != std::string::npos)
				{
					lineTable[line].erase(cr);
				}
			}
			
			int lines = count;
			if(lines > 20)
			{
				lines=20;
			}
			for(int line=0;line < lines;line++)
			{
				cout << line+1 << ":" << lineTable[line] << "\n";
			}
			
			is.close();
		}
		else
		{
			cerr << "Cannot open file " << filename << "\n";
			exit(1);
		}
	}
	
	Text& Text::operator=(const Text& rhs)
	{
		if(this != &rhs)
		{
			if(lineTable)
			{
				delete [] lineTable;
				lineTable = nullptr;
				count = 0;
			}
			count = rhs.count;
			if(count)
			{
				lineTable = new std::string[count];
				for(int line=0;line < count;line++)
				{
					lineTable[line]=rhs.lineTable[line];
				}
			}
		}
		
		return *this;
	}
	
	Text&& Text::operator=(Text& rhs)
	{
		if(this != &rhs)
		{
			if(lineTable)
			{
				delete [] lineTable;
				lineTable = nullptr;
				count = 0;
			}

			count = rhs.count;
			lineTable=rhs.lineTable;
			rhs.count=0;
			rhs.lineTable=nullptr;
		}
		
		return move(*this);
	}
	
	Text::Text(const Text& rhs):count(0),lineTable(nullptr)
	{
		*this = rhs;
	}
	
	Text::Text(Text&& rhs):count(0),lineTable(nullptr)
	{
		*this = move(rhs);
	}
	
	Text::~Text()
	{
		delete [] lineTable;
	}
	
	size_t Text::size()
	{
		return count;
	}
	
}