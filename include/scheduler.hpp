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

#include <memory>                   // std::shared_ptr
#include <queue>  		            // std::priority_queue
#include <ctime>  		            // time_t
#include <vector>  		            // vector

#include "tasks_creator.hpp"  	    // Creator
#include "uid.hpp"  	            // Uid
#include "compare.hpp"  		    // Compare

// ITask is generic abstract class
#include "../tasks/itask.hpp"       // ITask
// Built-in scheduler tasks
#include "../tasks/print_msg.hpp"   // PrintMsg


//----------------------------------------------------------------------------//
//	Scheduler Deceleration
//----------------------------------------------------------------------------//

template <
	typename Key,
	typename Args
	>
class Scheduler
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
    //      Args are the parameters the user can pass to ITask function
    //      interval parameter determines its priority value
    Uid ScheduleTask(Key taskName_, Args args_, time_t interval_ = 1);
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
    size_t Size();

    // DESCRIPTION Checks if any tasks exists in scheduler 
    bool IsEmpty();

    // DESCRIPTION Delete all tasks in the scheduler
    void Clear();
    

private:
    std::priority_queue<
        std::shared_ptr<ITask>, 
        std::vector<std::shared_ptr<ITask>>,
        Compare>    // compare between the interval values of => ITask1 < ITask2
        m_tasks;
    time_t m_initialTime;
    
    Creator<ITask, Key, Args>* m_creator;
};



//----------------------------------------------------------------------------//
//	Scheduler Definitions
//----------------------------------------------------------------------------//
template <typename Key, typename Args>
Scheduler<Key, Args>::Scheduler(): 
    m_initialTime(0)
{
    // Create and Initiate the creator. Adding basic tasks to the scheduler
    m_creator = new Creator<ITask, ITask::TaskName, Param>();

    // Add Basic Tasks functionalities
    m_creator->ProvideTaskType(ITask::PRINT_MSG, PrintMsg::CreateInst);
}


template <typename Key, typename Args>
Scheduler<Key, Args>::~Scheduler()
{
    // Clear all tasks from m_tasks pqueue
    // Clear();

    delete m_creator;
}


template <typename Key, typename Args>
Uid Scheduler<Key, Args>::ScheduleTask(Key taskName_, Args args_, time_t interval_)
{
    // Create instant of a task
    std::shared_ptr<ITask> task = m_creator->CreateTaskInst(taskName_, args_);

    task->SetInterval(interval_);

    // Add task to the container
    m_tasks.push(task);

    return task->GetID();
}



// Extra Functionality
//----------------------------------------------------------------------------//
template <typename Key, typename Args>
size_t Scheduler<Key, Args>::Size()
{
    return m_tasks.size();
}


template <typename Key, typename Args>
bool Scheduler<Key, Args>::IsEmpty()
{
    return m_tasks.empty();
}

template <typename Key, typename Args>
void Scheduler<Key, Args>::Clear()
{
    while (!m_tasks.empty())
    {
        m_tasks.pop();
    }
}



#endif // SCHEDULER_HPP