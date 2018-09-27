#pragma once
//includes
#include <fstream>
#include <string>
#include <iostream>
//namespace
using namespace std;

namespace w3
{
	class Text
	{
		size_t count;
		string* lineTable;
		public:
		Text();//:count(0),lineTable(nullptr);
		Text(const char*);//:count(0),lineTable(nullptr);
		Text& operator=(const Text&);
		Text&& operator=(Text&);
		Text(const Text&);
		Text(Text&&);
		~Text();
		size_t size();
		
	};
	
}