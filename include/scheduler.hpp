//----------------------------------------------------------------------------//
//						<< Scheduler Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Scheduler Interface
//					
//	AUTHOR 			Liad Raz
//	DATE			02 Jun 2022
// 
//----------------------------------------------------------------------------//

#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP


//----------------------------------------------------------------------------//
//	Scheduler Deceleration
//----------------------------------------------------------------------------//
class Scheduler:
{
public:
	//
	// Special Members Constructors
    Scheduler() = default;
    ~Scheduler() = default;
    Scheduler(const Scheduler& other_) = delete;
    Scheduler& operator=(const Scheduler& other_) = delete;

    //
    // Main Functionality
    void Run();
    void Stop();

    // DESCRIPTION Adds a task to Tasks list
    void InsertTaskClass();
    // DESCRIPTION Remove a task from Tasks list
    void DeleteTaskClass();

    void AddTaskInst();
    void RemoveTaskInst();

private:

};


#endif // SCHEDULER_HPP