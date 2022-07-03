//----------------------------------------------------------------------------//
//                  << Scheduler Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Compare functor
//                  Compare values inside a shared pointer
//	AUTHOR 			Liad Raz
//	DATE			03 Jul 2022
// 
//----------------------------------------------------------------------------//

#ifndef COMPARE_HPP
#define COMPARE_HPP

#include <memory>                   // std::shared_ptr

#include "../tasks/itask.hpp"       // ITask


//----------------------------------------------------------------------------//
//	Compare Deceleration
//----------------------------------------------------------------------------//

class Compare
{
public:
	//
	// Special Members Constructors
    Compare() = default;
    ~Compare() = default;
    Compare(const Compare& other_) = default;
    Compare& operator=(const Compare& other_) = default;


    bool operator()(std::shared_ptr<ITask> task1_, std::shared_ptr<ITask> task2_)
    {
        return task1_.get()->GetInterval() < task2_.get()->GetInterval();
    }
};



#endif // COMPARE_HPP