//----------------------------------------------------------------------------//
//						<< Scheduler Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Thread-Pool Tests
//	AUTHOR 			Liad Raz
//	DATE			03 Jun 2022
// 
//----------------------------------------------------------------------------//

#include <iostream>			// std::cout

#include "tasks_pool.hpp"
#include "wait_queue.hpp"


class Person {
public:
	explicit Person(int id, const std::string &name) : 
        m_id{id}, m_name{name} 
    {}
	
    int id() const 
    {
        return m_id;
    }

	const std::string& name() const 
    {
        return m_name;
    }

private:
	const int m_id;
	const std::string m_name;		
};


bool operator<(const Person &lhs, const Person &rhs) 
{ // compare by id
	return lhs.id() < rhs.id();
}	


std::ostream& operator<<(std::ostream &os, const Person &rhs) 
{ // for formatted output
	os << "Id: " << rhs.id() << ", Name: " << rhs.name();
	return os;
}



int main() 
{
    // Person p1(2, "C");
    // Person p2(3, "A"); 
    // Person p3(1, "B");
	
	// // By Id
	// TasksPool<Person> peopleById;
	// std::cout << "By Id: " << peopleById << "\n\n";

    // // peopleById.PushTask(p1);

    WaitQueue<int> wq;



	return 0;		
}