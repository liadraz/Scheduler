//----------------------------------------------------------------------------//
//						<< Scheduler Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		API
//                  Based on Factory Method Design Pattern.
//					
//	AUTHOR 			Liad Raz
//	DATE			02 Jun 2022
// 
//----------------------------------------------------------------------------//

#ifndef TASKS_CREATOR_HPP
#define TASKS_CREATOR_HPP


#include <memory>               // std::shared_ptr
#include <functional>           // std::function
#include <unordered_map>        // std::unordered_map


//----------------------------------------------------------------------------//
//	Creator Deceleration
//      The Creator class has two methods :
//      1. The user can implement and add any task he wants.
//      2. The create Task method which returns a new Task object with specific.
//----------------------------------------------------------------------------//
template <typename ITask, typename Key, typename Args>
class Creator
{
public:
    //
	// Special Members Constructors
    Creator() = default;
    ~Creator() = default;
    // Uncopiable class
    Creator(const Creator& other_) = delete;
    Creator& operator=(const Creator& other_) = delete;

    //
    // Definitions
    enum Status { ADDED = 0, UPDATED = 1 };

    // Alias for a general-purpose function.    
    // i.e syntax std::function<return(params)>;
    using CreateTaskInst_ty = std::function<std::shared_ptr<ITask>(Args args_)>;

    //
    // Main Functionality

    // DESCRIPTION  Insert a custom Task class to a table that Creator class holds.
    //              The user responsible of the task implementation.
    // RETURN       UPDATED when key exists; ADDED when key was added. 
    Status InsertTask(const Key& key_, CreateTaskInst_ty createFunc_);

    // DESCRIPTION  Creates instant of a desired Task, calling it by its Key.
    // IMPORTANT    Undefined behaviour when passing a key which does not exist.
    std::shared_ptr<ITask> CreateTask(const Key& key_, Args args_);


private:
    // DESCRIPTION An associative container (key-value pairs) impl like Hash Table.
    std::unordered_map<Key, CreateTaskInst_ty> m_tasks;

};



//----------------------------------------------------------------------------//
//	Creator Definitions
//----------------------------------------------------------------------------//
template <typename ITask, typename Key, typename Args>
typename Creator<ITask, Key, Args>::Status Creator<ITask, Key, Args>::InsertTask(const Key& key_, CreateTaskInst_ty createFunc_)
{
    Status status = Status::ADDED;

    if (m_tasks.end() != m_tasks.find(key_))
    {
        status = Status::UPDATED;
    }

    m_tasks[key_] = createFunc_;

    return status;
}


template <typename ITask, typename Key, typename Args>
std::shared_ptr<ITask> Creator<ITask, Key, Args>::CreateTask(const Key& key_, Args args_)
{
    try
    {
        return m_tasks[key_](args_);
    }
    catch(const std::exception& e)
    {
        throw;
    }
}


#endif // TASKS_CREATOR_HPP