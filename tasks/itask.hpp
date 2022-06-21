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

#include "uid.hpp"      // Uid


class ITask;

//
// Non-member Functions

bool operator<(const ITask& lhs_, const ITask& rhs_);


//----------------------------------------------------------------------------//
//	<< Interface >> 
//  ITask Deceleration 
//      Is created by a call from the TasksCreator class.
//----------------------------------------------------------------------------//
template <typename Args>
class ITask
{
public:
    //
    // Definitions
    enum Priority { ADMIN = -100, HIGH = 0, MED = 1, LOW = 2};
    
    //
	// Special Members Constructors
    explicit ITask(std::shared_ptr<Args> args_, time_t interval, Priority pri = MED);
    virtual ~ITask() = 0;

    // NOTE cctor and copy= are shallowed copied
    //      Task can be copied and be assigned by value, 
    //      while being pushed and popped each time as a new instance.
    ITask(const ITask &other_) = default;
	ITask &operator=(const ITask &other_) = default; 


private:
    std::shared_ptr<Args> m_args;   // TODO: should move to protected access specifier
    time_t m_interval;
    time_t m_nextRun;
    Priority m_priority;
    Uid id;

    // DESCRIPTION  The actual function which will execute the Task
    virtual bool ExecFunc() = 0;

	// DESCRIPTION  operator< defined as a friend for symmetric purposes.
    friend bool operator<(const ITask& lhs_, const ITask& rhs_);
    

    // TODO: Upgrade to multi-threaded environment using a TaskPool(Thread Pool)
    // friend TasksPool;
};


template <typename Args>
ITask<Args>::~ITask() = default;


#endif // ITASK_HPP