//----------------------------------------------------------------------------//
//						<< Scheduler Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		UID Implementation
//                  Unique identifier Generator
//	AUTHOR 			Liad Raz
//	DATE			02 Jun 2022
// 
//----------------------------------------------------------------------------//

#include <iostream>     // ostream
#include <ctime>        // time
#include <unistd.h>     // getpid

#include "uid.hpp"


// Initiation of static variables
std::atomic<size_t> Uid::s_m_counter(0);

//
// Special Members Constructors
//----------------------------------------------------------------------------//
Uid::Uid() :
    m_uid(s_m_counter.fetch_add(1)),
    m_time(time(NULL)),
    m_pid(getpid())
{}


// Main Functionality
//----------------------------------------------------------------------------//
bool Uid::IsSame(const Uid& first_, const Uid& second_) const
{
    return (
        (first_.m_time == second_.m_time) &&
        (first_.m_pid == second_.m_pid) &&
        (first_.s_m_counter == second_.s_m_counter)
        );
}

bool Uid::IsBad(const Uid& uid_) const
{
    return (
        (0 == uid_.m_time) &&
        (0 == uid_.m_pid) &&
        (0 == uid_.s_m_counter)
        );
}


// I/O
//----------------------------------------------------------------------------//
std::ostream& operator<<(std::ostream& os_, const Uid& uid_)
{
    return os_ << "(UID " << uid_.m_uid << ", Time " << uid_.m_time << ", PID " << uid_.m_pid << ")";
}

// 