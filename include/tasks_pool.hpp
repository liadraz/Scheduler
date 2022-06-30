//----------------------------------------------------------------------------//
//						<< Scheduler Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Tasks Pool API
//					Pool of Threads executes Tasks
//	AUTHOR 			Liad Raz
//	DATE			02 Jun 2022
// 
//----------------------------------------------------------------------------//

#ifndef TASKS_POOL_HPP
#define TASKS_POOL_HPP

#include <queue>  		// std::priority_queue
#include <vector>       // std::vector
#include <memory>       // std::shared_ptr
#include <thread>       // std::thread::hardware_concurrency

#include "itask.hpp"
#include "wait_queue.hpp"

class TasksPool
{
public:
    explicit TasksPool() = default;
    ~TasksPool() = default;
    TasksPool(const TasksPool& other_) = default;
    TasksPool& operator=(const TasksPool& other_) = default;

    // void AddTask(std::shared_ptr<ITask> task_);
    // void Stop();
// size_t size_ = std::thread::hardware_concurrency()

private:
    // std::vector<std::thread> m_threads;
    WaitQueue<
        std::shared_ptr<ITask>, 
        std::vector<std::shared_ptr<ITask>>, 
        ITask::Priority
        > m_tasks;

    // void MainThreadFunc();
};


#endif // TASKS_POOL_HPP