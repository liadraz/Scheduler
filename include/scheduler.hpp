//----------------------------------------------------------------------------//
//						<< Scheduler Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Scheduler Interface
//					Executes user costumed tasks in a provided intervals
//	AUTHOR 			Liad Raz
//	DATE			02 Jun 2022
// 
//----------------------------------------------------------------------------//

#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <queue>  		// std::priority_queue
#include <ctime>  		// time_t

#include "uid.hpp"  	// Uid


//----------------------------------------------------------------------------//
//	Scheduler Deceleration
//----------------------------------------------------------------------------//

template <
	typename T, 
	typename Args, 
	typename Container = std::vector<T>, 
	typename Compare = std::less<T>
	>
class Scheduler:
{
public:
	//
	// Special Members Constructors
    Scheduler();
    ~Scheduler();
    Scheduler(const Scheduler& other_) = delete;
    Scheduler& operator=(const Scheduler& other_) = delete;

    //
    // Main Functionality
    void Run();
    void Stop();

    // DESCRIPTION Add a task to the scheduler. 
    // T is a pointer to a function
    // Args are the parameters the user can pass to T function
    // interval parameter determines its priority value
    Uid InsertTaskClass(ITask task_, Args param_, time_t interval_);

    // DESCRIPTION Remove a task from the scheduler.
    void RemoveTaskClass();


    //
    // Extra functionality

    // DESCRIPTION Obtain how many tasks currently exists in the scheduler.
    size_t Size();
    // DESCRIPTION Checks if any tasks exists in scheduler 
    bool IsEmpty();
    // DESCRIPTION Delete all tasks in the scheduler
    void Clear();
    
    // TODO: creating a tasks creator, option to add tasks while the scheduler is running 
    // void AddTaskInst();
    // void RemoveTaskInst();

private:
    std::priority_queue<T, Container, Compare> m_tasks;
};


#endif // SCHEDULER_HPP