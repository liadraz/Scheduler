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
	typename Key,
	typename Args
	>
class Scheduler:
{
public:
	//
	// Special Members Constructors
    Scheduler();
    ~Scheduler();
    // Uncopiable
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
    Uid ScheduleTask(Key taskName_, Args param_, time_t interval_);
    // void RemoveTask(Uid toRemove_);

    //
    // DESCRIPTION  Add a user custom task type. 
    // Creating a tasks creator, option to add tasks while the scheduler is running 
    // Uid InsertTaskClass();
    // DESCRIPTION Remove a task from the scheduler.
    // void DeleteTaskClass();

    //
    // Extra functionality

    // DESCRIPTION Obtain how many tasks currently exists in the scheduler.
    // size_t Size();

    // DESCRIPTION Checks if any tasks exists in scheduler 
    // bool IsEmpty();

    // DESCRIPTION Delete all tasks in the scheduler
    // void Clear();
    

private:
    std::priority_queue<Task> m_tasks;
    time_t m_initialTime;
    Creator* m_creator;
};



//----------------------------------------------------------------------------//
//	Scheduler Definitions
//----------------------------------------------------------------------------//
template <typename Task, typename Key, typename Args>
Scheduler<Task, Key, Args>::Scheduler(): m_initialTime(0)
{
    // Create and Initiate the creator. Adding basic tasks to the scheduler
    m_creator = new Creator<ITask, ITask::TaskName, Args>();

    // Add Basic Tasks functionalities
    m_creator->ProvideTaskType(ITask::PRINT_MSG, PrintMsg::CreateInst);
}

template <typename Task, typename Key, typename Args>
Scheduler<Task, Key, Args>::~Scheduler()
{
    // Clear all tasks from m_tasks pqueue
    Clear();

    delete m_creator;
}


template <typename Task, typename Key, typename Args>
Uid Scheduler<Task, Key, Args>::ScheduleTask(Key taskName_, Args param_, time_t interval_)
{
    // m_creator->CreateTaskInst
}




#endif // SCHEDULER_HPP