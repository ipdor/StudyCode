/**
 * 
 * ����ģʽʵ�ִ��룬�ο�:
 * Factory Method in C++
 * https://refactoring.guru/design-patterns/factory-method/cpp/example
 *
 * Factory Method
 * https://refactoring.guru/design-patterns/factory-method
 */ 
#include "Factory.h"
#include <iostream>
using namespace std;


/**
 * ֻ��Ҫ����ʵ���Ĳ�������ʹ�ù������ɶ�Ӧ��Product��ʹ�ã�����֪����ʲô��Ʒ/����
 */ 
void Client(const Creator& creator)
{
    cout<< "Client: I'm not aware of the creator's class, but it still works.\n" << creator.SomeOperation();
}

int main()
{
    cout << "APP: Launched with the ConcreteCreator1.\n";
    ConcreteCreator1* creator1 = new ConcreteCreator1();
    Client(*creator1);
    cout << "APP: Launched with the ConcreteCreator2.\n";
    ConcreteCreator2* creator2 = new ConcreteCreator2();
    Client(*creator2);

    delete creator1;
    delete creator2;
    return 0;
}