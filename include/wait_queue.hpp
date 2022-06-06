//----------------------------------------------------------------------------//
//					Waitable Queue
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		<< Interface >> Waitable Queue
//					A container which holds Tasks, which are ordered by priority.
//	AUTHOR 			Liad Raz
//	DATE			26 Apr 2022
//
//----------------------------------------------------------------------------//

#ifndef WAIT_QUEUE_HPP
#define WAIT_QUEUE_HPP

#include <queue>  		// std::priority_queue


//----------------------------------------------------------------------------//
//	WaitQueue Deceleration
// 	DESCRIPTION
// 		T must be copyable and assignable. 
// 		Container cannot be copyable and assignable.
//		TODO Feature thread-safe.
//----------------------------------------------------------------------------//
template <
	typename T, 
	typename Container = std::vector<T>, 
	typename Compare = std::less<T>
	>
class WaitQueue
{
public:
	//
	// Special Constructors
	explicit WaitQueue(const Compare& compare_ = Compare());
	~WaitQueue() = default;
	// Uncopiable
	WaitQueue(const WaitQueue& other_) = delete;
	WaitQueue &operator=(const WaitQueue& other_) = delete;

	//
	// Main Functionality
	void Push(const T& data_);
	void Pop(T& out_);

	bool IsEmpty() const;

	std::priority_queue<T, Container, Compare> m_pqueue;
private:
};


//----------------------------------------------------------------------------//
//	WaitQueue Class Definitions
//----------------------------------------------------------------------------//
template <typename T, typename Container, typename Compare>
WaitQueue<T, Container, Compare>::WaitQueue(const Compare &compare_) :
	m_pqueue(compare_)
{}


template <typename T, typename Container, typename Compare>
void WaitQueue<T, Container, Compare>::Push(const T& data_)
{
	m_pqueue.push(data_);
}


template <typename T, typename Container, typename Compare>
void WaitQueue<T, Container, Compare>::Pop(T& out_)
{
	out_ = m_pqueue.top();
	m_pqueue.pop();
}

//
template <typename T, typename Container, typename Compare>
bool WaitQueue<T, Container, Compare>::IsEmpty() const
{
	return m_pqueue.empty();
}


#endif // WAIT_QUEUE_HPP
