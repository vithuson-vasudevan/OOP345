#ifndef NOTIFICATION_H_INCLUDED
#define NOTIFICATION_H_INCLUDED
//define
#define MAX 10
//includes
#include "Message.h"

namespace w5{

class Notifications
	{
	private:
		Message *msg;
		int cur_count;
	public:
		Notifications();
		Notifications(const Notifications&) ;
		Notifications& operator=(const Notifications&);
		Notifications(Notifications&&);
		Notifications& operator=(Notifications&&);
		~Notifications();
		void operator+=(const Message& msg);
		Notifications& operator+=(const Message&& msg);
		void display(std::ostream& os) const;
	};
}

#endif