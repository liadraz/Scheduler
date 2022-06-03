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

#ifndef TASKS_FACTORY_HPP
#define TASKS_FACTORY_HPP


#include <memory>               // std::shared_ptr
#include <functional>           // std::function
#include <unordered_map>        // std::unordered_map


//  The Creator class declares the factory method that returns new Task objects.
// 

template <typename ITask, typename Key, typename Args>
class Creator:
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
    enum Status { ADDED = 0, FAILED = 1, UPDATED = 2 }

    // Alias for a general-purpose function.    
    // i.e syntax std::function<return(params)>;
    using CreateTaskClass_ty = std::function<std::shared_ptr<ITask>(Args args_)>;

    //
	// Main Functionality

    // DESCRIPTION  Add a custom Task class to a table that Creator class holds.
    //              The user responsible of the task implementation.
    // RETURN       UPDATED when key exists; ADDED when key was added. 
    Status InsertTaskClass(const Key& key_, CreateTaskClass_ty create_);

    // DESCRIPTION  Creates instant of a desired Task, calling it by its Key.
    // IMPORTANT    Undefined behaviour when passing a key which does not exist.
    std::shared_ptr<ITask> FactoryMethod(const Key& key_, Args args_);


private:
    // DESCRIPTION An associative container (key-value pairs) impl like Hash Table.
    std::unordered_map<Key, CreateTaskClass_ty> m_tasks;

};


#endif // TASKS_FACTORY_HPP