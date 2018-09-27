// Workshop 2 - unsigned int, Enumerations, String Class and File I/O 
//includes
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include "Stations.h"
//namespaces
using namespace w2;
using namespace std;

int main(int argc, char* argv[]) {
     cout << "\nCommand Line : ";
     for (int i = 0; i < argc; i++) {
         cout << argv[i] << ' ';
     }
     cout << endl;
     if (argc != 2) {
         cerr << "\nIncorrect number of arguments\n";
         return 1;
     }

     w2::Stations stations(argv[1]);
     stations.update();
     stations.restock();
     stations.report();
     return 0;
}