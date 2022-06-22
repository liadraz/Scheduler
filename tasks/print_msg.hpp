//----------------------------------------------------------------------------//
//						<< Scheduler Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Print Message - Concrete Class
//					
//	AUTHOR 			Liad Raz
//	DATE			21 Jun 2022
// 
//----------------------------------------------------------------------------//

#ifndef PRINTMSG_HPP
#define PRINTMSG_HPP


#include <iostream>       // std::cout, std::endl
#include <memory>       // std::shared_ptr
#include <ctime>        // time_t

#include "itask.hpp"    // ITask


//----------------------------------------------------------------------------//
//  PrintMsg Deceleration 
//      Is created by a call from the TasksCreator class.
//----------------------------------------------------------------------------//
template <typename Args>
class PrintMsg : public ITask<Args>
{
public:
    //
	// Special Members Constructors
    // NOTE     The default Ctor is blocked, in order to create 
    //          an instance of this class only by invoking CreateTask method.
    ~PrintMsg() = default;

    PrintMsg(const PrintMsg &other_) = default;
	PrintMsg &operator=(const PrintMsg &other_) = default;

    //
    // Main Functionality
    // Create an Instance of this class
    static std::shared_ptr<PrintMsg> CreateInst(Args args_);

private: 
    // NOTE     Default Ctor is blocked to use by the user.
    explicit PrintMsg(Args args_);

    // DESCRIPTION  
    bool ExecFunc() override;
};



//----------------------------------------------------------------------------//
//	PrintMsg Definitions
//----------------------------------------------------------------------------//


template <typename Args>
PrintMsg<Args>::PrintMsg(Args args_): 
    ITask<Args>::ITask<Args>(args_)
{}


template <typename Args>
std::shared_ptr<PrintMsg<Args>> PrintMsg<Args>::CreateInst(Args args_)
{
    return std::shared_ptr<PrintMsg>(new PrintMsg(args_));
}


template <typename Args>
bool PrintMsg<Args>::ExecFunc()
{
    std::cout << "Hello" << std::endl;
    return true;
}

#endif // PRINTMSG_HPP