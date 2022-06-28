//----------------------------------------------------------------------------//
//						<< Scheduler Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		ITask Implementation
//					
//	AUTHOR 			Liad Raz
//	DATE			2 Jun 2022
// 
//----------------------------------------------------------------------------//


#include "itask.hpp"    // ITask


//
// Special Members Constructors
//----------------------------------------------------------------------------//
ITask::~ITask() = default;



// Main Functionality
//----------------------------------------------------------------------------//
ITask::ITask(const Param& param_):
    m_param(param_),
    m_interval(1),
    m_nextRun(0)
{
    m_id = Uid();
}


Uid ITask::GetID()
{
    return m_id;
}

void ITask::SetInterval(time_t interval_)
{
    m_interval = interval_;
}


//
// Friendly Non-Member Functions
//----------------------------------------------------------------------------//
bool operator<(const ITask& lhs_, const ITask& rhs_)
{
    return lhs_.m_interval < rhs_.m_interval;
}

