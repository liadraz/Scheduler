
//----------------------------------------------------------------------------//
//					Design Patterns
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Tests - ITask Class
//	AUTHOR 		    Liad Raz
//	DATE			22 Jun 2022
//
//  CpyCompile      
//----------------------------------------------------------------------------//

#include <memory>       // std::shared_ptr

#include "itask.hpp"
#include "print_msg.hpp"


int main()
{
    std::shared_ptr<ITask<int>> t1 = PrintMsg::CreateTaskInst();

    return 0;
}