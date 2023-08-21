#include "Factory.h"
#include <string>

std::string ConcreteProduct1::Operation() const  // ! Don't forget the 'const' keyword
{
    return "{This is ConcreteProduct1.}\n";
}

std::string ConcreteProduct2::Operation() const
{
    return "{This is ConcreteProduct2.}\n";
}


/**
 * 抽象工厂类中，除了生产Product的纯虚函数，还要使用生成的Product完成某些业务逻辑。
 * 所有子类都继承这个函数，使用对应的Product
 */ 
std::string Creator::SomeOperation() const
{
    // Call the factory method to create a Product object
    Product* product = this->FactoryMethod();
    // Now, use the product
    std::string str = "Creator: The same creator's code has just worked with: " + product->Operation();
    delete product;
    return str;
}

/**
 * 每个产品示例对应1个产品工厂，负责生成对应的Product
 */ 
Product* ConcreteCreator1::FactoryMethod() const
{
    return new ConcreteProduct1();
}

Product* ConcreteCreator2::FactoryMethod() const
{
    return new ConcreteProduct2();
}
