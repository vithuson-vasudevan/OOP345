//includes
#include "Message.h"
//namespaces
using namespace std;
using namespace w5;

Message::Message(){
	msg.clear();
}

Message::Message(ifstream& in, char c){
	int index;
	string tmp;
	getline(in,tmp,c);
	index =tmp.find(' ');
	
	if((tmp.substr(0,index).find('@')<-1) == 0) 
		msg= tmp;
}

bool Message::empty() const{
	if(msg.length() == 0)
		return true;
	 
	return false;
}

void Message::display(ostream& os) const{
	if(!empty()){
		int find_at = msg.find("@");
		int len = msg.length();
		
			if(find_at<0){
				int name_index = msg.find_first_of(' ');
				std::string user = msg.substr(0,name_index);
				std::string tweet = msg.substr(name_index+1,len);

					if(len != tweet.length()){
						cout<< "Message" << endl;
						cout<< "     User : " << user.c_str() << endl;
						cout<< "     Tweet : " << tweet.c_str() << endl;
					}
			}
			else if(find_at>=0){
				cout << "Message" << endl;
				int count = 0;
				int index;
				string tmp = msg.substr(0,find_at-1);
				string tmp2;
				cout << "     User : " << tmp.c_str() << endl;
				tmp = msg.substr(find_at+1);
				index = tmp.find_first_of(' ');
				cout << "     Reply :" << tmp.substr(0,index).c_str() << endl;
				tmp = msg.substr(index+1);
				cout << "     Tweet :" << tmp.substr(index+1).c_str() << endl;
			}
	}
}