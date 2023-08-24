/**
 * 
 * Abstract Factory
 * https://refactoring.guru/design-patterns/abstract-factory
 * 
 * Abstract Factory in C++
 * https://refactoring.guru/design-patterns/abstract-factory/cpp/example
 * 
 */ 
#include <iostream>
#include <memory>
#include "Products.hpp"
#include "AbstractFactory.hpp"

/// @brief original ClientCode function 
/// @param AbstractFactory & 
void ClientCode(const AbstractFactory &factory)
{
    const AbstractProductA *productA = factory.CreateProductA();
    const AbstractProductB *productB = factory.CreateProductB();
    std::cout<< productB->UsefulFunctionB() <<std::endl;
    std::cout<< productB->AnotherUsefulFunctionB(*productA) <<std::endl;
    delete productA;
    delete productB;
}

/// @brief re-write ClientCode function by using shared_ptr
/// @param shared_ptr<AbstractFactory> 
void ClientCode2(const std::shared_ptr<AbstractFactory> factory) 
{
    std::shared_ptr<AbstractProductA> productA(factory->CreateProductA());
    std::shared_ptr<AbstractProductB> productB(factory->CreateProductB());

    std::cout<< productB->UsefulFunctionB() <<std::endl;
    std::cout<< productB->AnotherUsefulFunctionB(*productA) <<std::endl;
}

int main(int, char**)
{
    // * original code from the Internet
    // std::cout << "Client: Testing client code with the first factory type:\n";
    // ConcreteFactory1 *f1 = new ConcreteFactory1();
    // ClientCode(*f1);
    // delete f1;

    // std::cout<< std::endl;
    // std::cout << "Client: Testing the same client code with the second factory type:\n";
    // ConcreteFactory2 *f2 = new ConcreteFactory2();
    // ClientCode(*f2);
    // delete f2;

    // * improved version
    std::cout << "Client: Testing client code with the first factory type:\n";
    std::shared_ptr<ConcreteFactory1> f1 = std::make_shared<ConcreteFactory1>();
    std::shared_ptr<ConcreteFactory2> f2 = std::make_shared<ConcreteFactory2>();

    ClientCode2(f1);

    std::cout<< std::endl;
    std::cout << "Client: Testing the same client code with the second factory type:\n";

    ClientCode2(f2);

    std::cout<< std::endl;
    std::cout << "Client: Bye!" << std::endl;

    return 0;
}
