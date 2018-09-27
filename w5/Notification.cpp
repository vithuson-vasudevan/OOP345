//includes
#include "Notifications.h"
//namespace
using namespace w5;

Notifications::Notifications()
{
	msg = new Message[MAX];
	cur_count = 0;
}

Notifications::Notifications(const Notifications& src):cur_count(0)
{
	if(src.cur_count!=0)
	{
		*this = src;
	}
}

Notifications& Notifications::operator=(const Notifications& src)
{
	if(this != &src)
	{
		if(src.cur_count !=0)
		{
			msg = new Message[MAX];
			cur_count = src.cur_count;
			for(int i = 0 ; i < src.cur_count;i++)
			{
				msg[i] = src.msg[i];	
			}
		}
		else
		{
			msg= nullptr;
			*this = Notifications();
		}
	}
	
	return *this;
}

Notifications::Notifications(Notifications&& src)
{
		*this = src;
		src.msg=nullptr;
		src.cur_count=0;
}

Notifications& Notifications::operator=(Notifications&& src)
{	
	msg = src.msg;
	cur_count = src.cur_count;

	src.msg = nullptr;
	src.cur_count = 0;
	return *this; 

}

Notifications::~Notifications()
{
	if(msg != nullptr)
	{
		delete[] msg;
	}
} 

void Notifications::operator+=(const Message& Sysmsg)
{
	if(cur_count <MAX || !Sysmsg.empty())
	{
		msg[cur_count] = Sysmsg;
		cur_count++;
	}
}

void Notifications::display(std::ostream& os) const
{
	for(int i = 0 ; i< cur_count; i++)
	{
		msg[i].display(os);
	}
}

Notifications& Notifications::operator+=(const Message&& msg)
{
	if(!msg.empty() && cur_count < MAX)
	{
		this->msg[cur_count]=msg;
		cur_count++;
	}
	
	msg.empty();
	return *this;
	
}
	
