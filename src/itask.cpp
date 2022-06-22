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
