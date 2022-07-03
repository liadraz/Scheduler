
//----------------------------------------------------------------------------//
//					Design Patterns
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Tests - Scheduler Class
//	AUTHOR 		    Liad Raz
//	DATE			22 Jun 2022
//
//  CpyCompile
//  gdp11 -I ./include/ -I ./tasks/ ./src/uid.cpp src/itask.cpp src/print_msg.cpp tests/scheduler_test.cpp
//----------------------------------------------------------------------------//

#include <string>

#include "scheduler.hpp"


int main()
{
    std::cout << "Tests Scheduler" << std::endl;

    // Create scheduler
    Scheduler<ITask::TaskName, Param> sched;

    // Schedule print massage task
    Param p;
    Uid taskID = sched.ScheduleTask(ITask::PRINT_MSG, p, 3);
    Uid taskID1 = sched.ScheduleTask(ITask::PRINT_MSG, p, 1);
    Uid taskID2 = sched.ScheduleTask(ITask::PRINT_MSG, p, 4);


    std::cout << taskID << std::endl;
    std::cout << taskID1 << std::endl;
    std::cout << taskID2 << std::endl;


    return 0;
}