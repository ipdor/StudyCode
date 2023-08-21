/**
 * 
 * �򵥹���ģʽʵ�ִ��룬�ο�:
 * �ٲ�ѧ�򵥹���ģʽ�������Ҫȥ������ש��~
 * https://blog.csdn.net/sinat_21107433/article/details/102598181
 * 
 */ 
#include <iostream>
#include <memory>
#include "SimpleFactory.h"

int main()
{
    std::cout<< "APP: Simple Factory Method." << std::endl;

    std::shared_ptr<Factory> fac = std::make_shared<Factory>();
    std::shared_ptr<Product> pro = fac->getSportProduct("Basketball");
    pro = fac->getSportProduct("Football");
    pro = fac->getSportProduct("Volleyball");
    
    std::cout<< "APP: Hello World from simple factory." << std::endl;
    return 0;
}
