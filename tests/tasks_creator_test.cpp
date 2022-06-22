
//----------------------------------------------------------------------------//
//					Design Patterns
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Tests - Factory Method DP
//	AUTHOR 		    Liad Raz
//	DATE			19 Apr 2022
//
//  CpyCompile      gdp11 -I ./include/ tests/tasks_creator_test.cpp
//----------------------------------------------------------------------------//

#include <iostream>			// std::cout
#include <memory>           // std::shared_ptr
#include <string>			// std::string
#include <vector>			// std::vector

#include "tasks_creator.hpp"


//----------------------------------------------------------------------------//
// << Base Task >>
class IAnimal
{
public:
    enum Key {DOG, CAT};

    //
    // Special Ctors
    IAnimal() = default;
    virtual ~IAnimal() = 0;
    IAnimal(const IAnimal& other_) = default;
    IAnimal& operator=(const IAnimal& other_) = default;

    virtual void PrintSound() = 0;
};

IAnimal::~IAnimal() = default;


// << Concrete Task 1 >>
class Dog : public IAnimal
{
public:
    //
    // Special Ctors
    Dog() : m_arg(1)
    {
        std::cout << "Dog ctor" << std::endl;
    }

    ~Dog() noexcept override;
    Dog(const Dog& other_) = default;
    Dog& operator=(const Dog& other_) = default;

    void PrintSound() override;

    // The Creation Function, which will be passes to the Creator Class
    static std::shared_ptr<Dog> Create(int param_)
    {
        (void)(param_);
        return std::shared_ptr<Dog>(new Dog());
    }

private:
    int m_arg;
};


Dog::~Dog() {}

// Definitions
void Dog::PrintSound()
{
    std::cout << "Hwo Hwo" << std::endl;
}

//----------------------------------------------------------------------------//
// << Concrete Task 2 >>
class Cat : public IAnimal
{
public:
    Cat() : m_arg(1)
    {
        std::cout << "Cat ctor" << std::endl;
    }

    ~Cat() noexcept override;

    void PrintSound() override;

    // The Creation Function, which will be passes to the Creator Class
    static std::shared_ptr<Cat> Create(int param_)
    {
        std::cout << param_ << std::endl;
        return std::shared_ptr<Cat>(new Cat());
    }

private:
    int m_arg;
};

// Definitions
void Cat::PrintSound()
{
    std::cout << "MEOW" << std::endl;
}

Cat::~Cat() {}



int main()
{
    std::cout << "Tests Factory Method Design Pattern" << std::endl;

    Creator<IAnimal, IAnimal::Key, int>* creator = new Creator<IAnimal, IAnimal::Key, int>();
    std::cout << "Address of creator class " << creator << std::endl;

    Creator<IAnimal, IAnimal::Key, int>::Status status = Creator<IAnimal, IAnimal::Key, int>::ADDED;

    // Add concrete tasks
    status = creator->ProvideTaskType(IAnimal::DOG, Dog::Create);
    std::cout << status << std::endl;

    status = creator->ProvideTaskType(IAnimal::CAT, Cat::Create);
    std::cout << status << std::endl;

    
    // Call to Create a task object
    std::shared_ptr<IAnimal> animal = creator->CreateTaskInst(IAnimal::CAT, 2);
    animal->PrintSound();

    std::shared_ptr<IAnimal> animal2 = creator->CreateTaskInst(IAnimal::DOG, 2);
    animal2->PrintSound();


    std::vector<IAnimal::Key> list = creator->GetListOfTasks();

    return 0;
}