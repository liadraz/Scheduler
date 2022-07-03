//----------------------------------------------------------------------------//
//						<< Scheduler Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		ITask Interface
//					
//	AUTHOR 			Liad Raz
//	DATE			21 Jun 2022
// 
//----------------------------------------------------------------------------//

#ifndef ITASK_HPP
#define ITASK_HPP

#include <memory>       // std::shared_ptr
#include <ctime>        // time_t
#include <string>       // std::string

#include "uid.hpp"      // Uid


class ITask;
//
// Non-member Functions
bool operator<(const ITask& lhs_, const ITask& rhs_);


struct Param
{
    std::string m_taskName;
};

//----------------------------------------------------------------------------//
//	<< Interface >> 
//  ITask Deceleration 
//      Generic task which handled by the Scheduler.
//----------------------------------------------------------------------------//
class ITask
{
public:
    //
    // Definitions 
    // Basic tasks the scheduler accepts.
    enum TaskName { PRINT_MSG = 0, TELL_TIME = 1 };
    
    //
	// Special Members Constructors
    explicit ITask(const Param& param_);
    virtual ~ITask() = 0;

    // NOTE cctor and copy= are shallowed copied
    //      Task can be copied and be assigned by value, 
    //      while being pushed and popped each time as a new instance.
    ITask(const ITask &other_) = default;
	ITask &operator=(const ITask &other_) = default; 

    Uid GetID() const;
    
    time_t GetInterval() const;
    void SetInterval(time_t interval_);

private:
    Param m_param;   // TODO: should move to protected access specifier
    time_t m_interval;
    time_t m_nextRun;
    Uid m_id;

    // DESCRIPTION  The actual function which will be overriden by 
    //              the derived class. The actual execution of the Task.
    virtual bool ExecFunc() = 0;


    // TODO: Upgrade and assign tasks to waitable queue
	// DESCRIPTION  operator< defined as a friend for symmetric purposes.
    friend bool operator<(const ITask& lhs_, const ITask& rhs_);
    
    // TODO: Upgrade to multi-threaded environment using a TaskPool(Thread Pool)
    // friend TasksPool;
};



#endif // ITASK_HPP