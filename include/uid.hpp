//----------------------------------------------------------------------------//
//						<< Scheduler Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		UID API
//                  Unique identifier Generator
//	AUTHOR 			Liad Raz
//	DATE			02 Jun 2022
// 
//----------------------------------------------------------------------------//

#ifndef UID_HPP
#define UID_HPP

#include <iostream>     // ostream, size_t, time_t, pid_t
#include <atomic>       // std::atomic



class Uid;

//
// Non-member Functions
std::ostream& operator<<(std::ostream& os_, const Uid& uid_);

//----------------------------------------------------------------------------//
//	Uid Declaration
//  NOTE    Class is Thread safe.
//----------------------------------------------------------------------------//

class Uid
{
public:
    //
	// Special Members Constructors
    explicit Uid();
    ~Uid() = default;
    Uid(const Uid& other_) = default;
    Uid& operator=(const Uid& other_) = default;

    //
    // Main Functionality
    bool IsSame(const Uid& first_, const Uid& second_) const;
    bool IsBad(const Uid& uid_) const;

private:
    size_t m_uid;
    time_t m_time;
    pid_t m_pid;

    static std::atomic<size_t> s_m_counter;

    // I/O overload
    // format (time, pid, counter)
    friend std::ostream& operator<<(std::ostream& os_, const Uid& uid_);
};



#endif // UID_HPP