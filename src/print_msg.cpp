//----------------------------------------------------------------------------//
//						<< Scheduler Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		PrintMsg Implementation
//					
//	AUTHOR 			Liad Raz
//	DATE			22 Jun 2022
// 
//----------------------------------------------------------------------------//


#include "print_msg.hpp"    // ITask

//
// Special Members Constructors
//----------------------------------------------------------------------------//
PrintMsg::PrintMsg(const Param& param_): 
    ITask::ITask(param_)
{}

// Main Functionality
//----------------------------------------------------------------------------//
std::shared_ptr<PrintMsg> PrintMsg::CreateInst(const Param& param_)
{
    return std::shared_ptr<PrintMsg>(new PrintMsg(param_));
}

bool PrintMsg::ExecFunc()
{
    std::cout << "Hello" << std::endl;
    return true;
}