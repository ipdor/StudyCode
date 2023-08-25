/**
 * 
 * 1 abstract factory and 2 concrete factories
 * ! Each concrete factory for each product variant: a product A and a product B.
 * 
 * 
 */
#include <iostream>
#include "Products.hpp"

class AbstractFactory
{
private:
    
public:
    virtual AbstractProductA *CreateProductA() const = 0;
    virtual AbstractProductB *CreateProductB() const = 0;
};

class ConcreteFactory1: public AbstractFactory
{
private:
    
public:
    AbstractProductA *CreateProductA() const override
    {
        return new ConcreteProductA1;
    }
    AbstractProductB *CreateProductB() const override
    {
        return new ConcreteProductB1;
    }
};

class ConcreteFactory2: public AbstractFactory
{
private:
    
public:
    AbstractProductA *CreateProductA() const override
    {
        return new ConcreteProductA2;
    }
    AbstractProductB *CreateProductB() const override
    {
        return new ConcreteProductB2;
    }
};

