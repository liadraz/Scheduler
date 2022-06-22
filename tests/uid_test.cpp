//----------------------------------------------------------------------------//
//						<< Scheduler Project >>
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		UID Tests
//	AUTHOR 			Liad Raz
//	DATE			03 Jun 2022
//
//  CpyCompile      gdp11 -I ./include/ ./src/uid.cpp tests/uid_test.cpp
//----------------------------------------------------------------------------//

#include <iostream>			// std::cout

#include "uid.hpp"

int main()
{
    Uid id1;
    Uid id2;

    std::cout << id1 << std::endl;
    std::cout << id2 << std::endl;


    return 0;
}