//----------------------------------------------------------------------------//
//						<< Scheduler Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		WaitQueue Tests
//	AUTHOR 			Liad Raz
//	DATE			06 Jun 2022
// 
//----------------------------------------------------------------------------//

#include <iostream>			// std::cout

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

struct PersonCompareByName 
{
	bool operator()(const Person &lhs, const Person &rhs) const 
    {
		return lhs.name() < rhs.name();
	}
};

int main() 
{
    WaitQueue<int> wq;

    // wq.Push(10);
    // wq.Push(12);
    // wq.Push(14);

    // int x = 0;

    // while (!wq.m_pqueue.empty())
    // {
    //     std::cout << "num: "<< wq.m_pqueue.top() << std::endl;
    //     std::cout << "& "<< &wq.m_pqueue.top() << std::endl;
    //     wq.Pop(x);
    //     std::cout << "num: " << x << std::endl;
    //     std::cout << "& "<< &x << std::endl;
    // }

    WaitQueue<Person> persons;

    // Person p1(2, "C");
    // Person p2(3, "A"); 
    // Person p3(1, "B");

    // persons.Push(p1);

	// By Id
	// std::cout << "By Id: " << peopleById << "\n\n";

    // // // peopleById.PushTask(p1);


	return 0;		
}