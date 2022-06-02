//----------------------------------------------------------------------------//
//						<< Scheduler Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		API - Factory Design Pattern
//					
//	AUTHOR 			Liad Raz
//	DATE			02 Jun 2022
// 
//----------------------------------------------------------------------------//

#ifndef TASKS_FACTORY_HPP
#define TASKS_FACTORY_HPP

template <typename Base, typename Key, typename Args>
class Factory:
{
public:
    //
	// Special Members Constructors
    Factory() = default;
    ~Factory() = default;
    // Uncopiable
    Factory(const Factory& other_) = delete;
    Factory& operator=(const Factory& other_) = delete;

private:

};


#endif // TASKS_FACTORY_HPP