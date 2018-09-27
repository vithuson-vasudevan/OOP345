//includes
#include <iostream>
 #include <fstream>
 #include "Message.h"
 #include "Notifications.h"
//namespaces
using namespace w5;
using namespace std;
//global
const char REC_DELIMITER = '\n';

w5::Notifications collect(std::ifstream& in, char recDelim) {
     w5::Notifications notifications;

     do {
         w5::Message message(in, recDelim);
	
         if (!message.empty())
             notifications += move(message);
			
     } while(in);

     return notifications;
 }

 int main(int argc, char* argv[]) {
     if (argc == 1) {
         cerr << argv[0] << ": missing file operand\n";
         return 1;
     }
     else if (argc != 2) {
         cerr << argv[0] << ": too many arguments\n";
         return 2;
     }
     ifstream file("w5_test.dat");
     if (!file) {
         cerr << argv[0] << "\n: Failed to open " << argv[1] << "\n"; 
         return 3;
     }

     cout << "\nNotifications\n=============\n\n";
     w5::Notifications notifications = collect(file, REC_DELIMITER);

     notifications.display(cout);

     cout << "Press any key to continue ... ";
     cin.get();
 }
