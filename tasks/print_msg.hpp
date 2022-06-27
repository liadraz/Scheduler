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


#include <iostream>     // std::cout, std::endl
#include <memory>       // std::shared_ptr
#include <ctime>        // time_t

#include "itask.hpp"    // ITask


//----------------------------------------------------------------------------//
//  PrintMsg Deceleration 
//     Print a massage to stdout.
//----------------------------------------------------------------------------//
class PrintMsg : public ITask
{
public:
    //
	// Special Members Constructors
    // NOTE     The default Ctor is blocked. 
    //          Use CreateInst to create this class.
    ~PrintMsg() = default;

    PrintMsg(const PrintMsg &other_) = default;
	PrintMsg &operator=(const PrintMsg &other_) = default;

    //
    // Main Functionality
    // Create an Instance of this class
    static std::shared_ptr<PrintMsg> CreateInst(const Param& param_);

private: 
    // NOTE     Default Ctor is blocked to use by the user.
    explicit PrintMsg(const Param& param_);

    // DESCRIPTION  
    bool ExecFunc() override;
};


#endif // PRINTMSG_HPP