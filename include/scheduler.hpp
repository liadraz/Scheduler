//----------------------------------------------------------------------------//
//                  << Scheduler Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Scheduler Interface
//                  Executes user costumed tasks in a provided intervals
//	AUTHOR 			Liad Raz
//	DATE			02 Jun 2022
// 
//----------------------------------------------------------------------------//

#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <queue>  		// std::priority_queue
#include <ctime>  		// time_t

#include "tasks_creator.hpp"  	// Creator
#include "itask.hpp"  	        // ITask
#include "uid.hpp"  	        // Uid


//----------------------------------------------------------------------------//
//	Scheduler Deceleration
//----------------------------------------------------------------------------//

template <
	typename Task, 
	typename Args, 
	typename Container = std::vector<Task>, 
	typename Compare = std::less<Task>
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

    // DESCRIPTION  Add a task to the scheduler. 
    // T is a pointer to a function
    // Args are the parameters the user can pass to T function
    // interval parameter determines its priority value
    Uid ScheduleTask(Task task_, Args param_, time_t interval_);
    void RemoveTask(Uid toRemove_);

    //
    // DESCRIPTION  Add a user custom task type. 
    // Creating a tasks creator, option to add tasks while the scheduler is running 
    Uid InsertTaskClass();
    // DESCRIPTION Remove a task from the scheduler.
    void DeleteTaskClass();

    //
    // Extra functionality

    // DESCRIPTION Obtain how many tasks currently exists in the scheduler.
    size_t Size();

    // DESCRIPTION Checks if any tasks exists in scheduler 
    bool IsEmpty();

    // DESCRIPTION Delete all tasks in the scheduler
    void Clear();
    

private:
    std::priority_queue<Task, Container, Compare> m_tasks;
    time_t m_initialTime;
    Creator* m_creator;
};



//----------------------------------------------------------------------------//
//	Scheduler Definitions
//----------------------------------------------------------------------------//
template <typename Task, typename Args, typename Container, typename Compare>
Scheduler<Task, Args, Container, Compare>::Scheduler() : m_initialTime(0)
{
    // Create and Initiate the creator. Adding basic tasks to the scheduler
    typename Creator<ITask, ITask::TASK_NAME, Args>* creator = new Creator<ITask, ITask::TASK_NAME, Args>();

    creator->ProvideTaskType(ITask::PRINT_MSG, PrintMsg::CreateTaskInst);

}

template <typename Task, typename Args, typename Container, typename Compare>
Scheduler::~Scheduler()
{}


#endif // SCHEDULER_HPP