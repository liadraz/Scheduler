
//----------------------------------------------------------------------------//
//					Design Patterns
//----------------------------------------------------------------------------//
//
//	DESCRIPTION		Tests - Factory Method DP
//	AUTHOR 		    Liad Raz
//	DATE			19 Apr 2022
//
//----------------------------------------------------------------------------//

#include <iostream>			// std::cout
#include <memory>           // std::shared_ptr
#include <string>			// std::string

#include "tasks_creator.hpp"


//----------------------------------------------------------------------------//
// << Interface >>
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

//
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

    // Creation Function
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
class Cat : public IAnimal
{
public:
    Cat() : m_arg(1)
    {
        std::cout << "Cat ctor" << std::endl;
    }
    ~Cat();

    void PrintSound() override;

    // Creation Function
    static std::shared_ptr<Cat> Create(int param_)
    {
        (void)(param_);
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

    Creator<IAnimal, IAnimal::Key, int>* fact = new Creator<IAnimal, IAnimal::Key, int>();
    std::cout << "Address of creator class " << fact << std::endl;

    Creator<IAnimal, IAnimal::Key, int>::Status status = Creator<IAnimal, IAnimal::Key, int>::ADDED;

    status = fact->InsertTask(IAnimal::DOG, Dog::Create);
    std::cout << status << std::endl;

    status = fact->InsertTask(IAnimal::CAT, Cat::Create);
    std::cout << status << std::endl;

    std::shared_ptr<IAnimal> animal = fact->CreateTask(IAnimal::CAT, 2);
    std::shared_ptr<IAnimal> animal2 = fact->CreateTask(IAnimal::DOG, 2);

    animal->PrintSound();
    animal2->PrintSound();

    return 0;
}