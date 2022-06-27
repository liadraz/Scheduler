//----------------------------------------------------------------------------//
//						<< Scheduler Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		API - Tasks Creator
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
#include <vector>               // std::vector
#include <iterator>             // std::iterator

//----------------------------------------------------------------------------//
//	Creator Deceleration
//      The Creator class has two main methods :
//      1. Provide, The user can add any task/class he desires.
//      2. Create Class, returns a Task object instance.
//
//      *** Get more information how to implement tasks in README.md file 
//          under Creator Class.
//----------------------------------------------------------------------------//
template <typename T, typename Key, typename Args>
class Creator
{
public:
    //
	// Special Members Constructors
    Creator() = default;
    ~Creator() = default;
    // Class cannot be Copied
    Creator(const Creator& other_) = delete;
    Creator& operator=(const Creator& other_) = delete;

    //
    // Definitions
    enum Status { ADDED = 0, UPDATED = 1 };

    // Alias for a general-purpose function.    
    // i.e syntax std::function<return(params)>;
    using CreateTaskInst_ty = std::function<std::shared_ptr<T>(Args args_)>;

    //
    // Main Functionality

    // DESCRIPTION  Fill the Creator class with custom Task Classes.
    //              Is the user responsibilty for writing the task interface 
    //              and the concrete class.
    // RETURN       UPDATED when key exists; ADDED when key was added. 
    Status ProvideTaskType(const Key& key_, CreateTaskInst_ty createFunc_);

    // DESCRIPTION  Creates an instant of a desired Task, calling it by its Key.
    //              (The Factory method)
    // IMPORTANT    Undefined behaviour when passing a key which does not exist.
    std::shared_ptr<T> CreateTaskInst(const Key& key_, Args args_);

    //
    // Extra Features

    // DESCRIPTION  Get a list of the current existing tasks.
    std::vector<Key> GetListOfTasks();


private:
    // DESCRIPTION An associative container (key-value pairs) impl like Hash Table.
    std::unordered_map<Key, CreateTaskInst_ty> m_tasks;

};



//----------------------------------------------------------------------------//
//	Creator Definitions
//----------------------------------------------------------------------------//
template <typename T, typename Key, typename Args>
typename Creator<T, Key, Args>::Status Creator<T, Key, Args>::ProvideTaskType(const Key& key_, CreateTaskInst_ty createFunc_)
{
    Status status = Status::ADDED;

    if (m_tasks.end() != m_tasks.find(key_))
    {
        status = Status::UPDATED;
    }

    m_tasks[key_] = createFunc_;

    return status;
}


template <typename T, typename Key, typename Args>
std::shared_ptr<T> Creator<T, Key, Args>::CreateTaskInst(const Key& key_, Args args_)
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


template <typename T, typename Key, typename Args>
std::vector<Key> Creator<T, Key, Args>::GetListOfTasks()
{
    std::vector<Key> retKeys;
    retKeys.reserve(m_tasks.size());

    auto it = m_tasks.begin();

    while (it != m_tasks.end())
    {
        retKeys.push_back(it->first);
        ++it;
    }

    return retKeys;
}


#endif // TASKS_CREATOR_HPP