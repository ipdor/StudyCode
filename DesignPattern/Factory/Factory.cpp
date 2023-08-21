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
 * ���󹤳����У���������Product�Ĵ��麯������Ҫʹ�����ɵ�Product���ĳЩҵ���߼���
 * �������඼�̳����������ʹ�ö�Ӧ��Product
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
 * ÿ����Ʒʾ����Ӧ1����Ʒ�������������ɶ�Ӧ��Product
 */ 
Product* ConcreteCreator1::FactoryMethod() const
{
    return new ConcreteProduct1();
}

Product* ConcreteCreator2::FactoryMethod() const
{
    return new ConcreteProduct2();
}
