
//----------------------------------------------------------------------------//
//					Design Patterns
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Tests - Scheduler Class
//	AUTHOR 		    Liad Raz
//	DATE			22 Jun 2022
//
//  CpyCompile
//  gdp11 -I ./include/ -I ./tasks/ ./src/uid.cpp tests/scheduler_test.cpp
//----------------------------------------------------------------------------//

#include <string>

#include "scheduler.hpp"


int main()
{
    std::cout << "Tests Scheduler" << std::endl;

    Scheduler<ITask, ITask::TaskName, Param> sched;

    return 0;
}