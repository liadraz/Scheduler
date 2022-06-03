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

#include <cstddef>			// size_t
#include <ctime>			// time_t, pid_t


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
    ~Uid();
    // Class cannot be Copied
    Uid(const Uid& other_) = delete;
    Uid& operator=(const Uid& other_) = delete;

    //
    // Main Functionality
    bool IsSame(const Uid& first_, const Uid& second_) const;
    bool IsBad(const Uid& isBad_) const;

private:
    size_t m_counter;
    time_t m_time;
    pid_t m_pid;

};



#endif // UID_HPP