//----------------------------------------------------------------------------//
//						<< Scheduler Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		ITask Interface
//					
//	AUTHOR 			Liad Raz
//	DATE			02 Jun 2022
// 
//----------------------------------------------------------------------------//

#ifndef ITASK_HPP
#define ITASK_HPP

#include <ctime>        // time_t

#include "tasks_pool.hpp"

class ITask;

//
// Non-member Functions
bool operator<(const ITask& lhs_, const ITask& rhs_);


//----------------------------------------------------------------------------//
//	<< Interface >> 
//  ITask Deceleration 
//  Is created by a call from the TasksCreator class.
//----------------------------------------------------------------------------//
class ITask
{
public:

    enum Priority { ADMIN = -100, HIGH = 0, MED = 1, LOW = 2};
    
    //
	// Special Members Constructors
    explicit ITask(time_t interval, Priority pri = MED);
    ~ITask() = default;

    // NOTE cctor and copy= are shallowed copied
    //      Task can be copied and be assigned, 
    //      in order to be contained in the waitable queue.
    ITask(const ITask &other_) = default;
	ITask &operator=(const ITask &other_) = default; 

private:
    time_t m_interval;
    Priority m_priority;

    //
	// Operators defined as friends non-member funcs, for symmetric purposes.
    friend bool operator<(const ITask& lhs_, const ITask& rhs_);
    
    virtual bool ExecFunc() = 0;
    friend TasksPool;
};


#endif // ITASK_HPP