/**
 * These Classes are wrote for learning Simple Factory method.
 * 
 * * Three Product classes, one abstruct class Product 
 * * two subclasses implementing the Product and have its own methods.
 * 
 * * One Factory class with a method that can produce products according to the param.
 * 
 */ 
#include <iostream>
#include <memory>
/**
 * ! Products
 */ 
class Product
{
public:
    Product(){};
    virtual ~Product(){};
    virtual void printName() = 0;
    virtual void play() = 0;
};

class Basketball: public Product
{
private:
    
public:
    Basketball()
    {
        printName();
        play();
    };
    ~Basketball(){};
    void printName();
    void play();
};

class Football: public Product
{
private:
    
public:
    Football()
    {
        printName();
        play();
    };
    ~Football(){};
    void printName();
    void play();
};

class Volleyball: public Product
{
private:
    
public:
    Volleyball()
    {
        printName();
        play();
    };
    ~Volleyball(){};
    void printName();
    void play();
};


/**
 * ! Factory
 */ 
class Factory
{
private:
    
public:
    Factory(){};
    ~Factory(){};

    std::shared_ptr<Product> getSportProduct(std::string productName);
};
