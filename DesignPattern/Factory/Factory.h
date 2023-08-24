/**
 * These Classes are wrote for learning Factory method.
 * 
 * * Three Product classes, one abstruct class Product 
 * * two subclasses implementing the Product and have its own methods.
 * 
 * * Three Creator classes, one abstruct class Creator 
 * * two subclasses implementing the Creator and creating a specific product.
 * 
 */ 

#include <string>
#include <iostream>

/**
 * ! Products
 */ 

class Product
{
public:    
    virtual ~Product() {};
    virtual std::string Operation() const = 0;
};

class ConcreteProduct1: public Product
{
public:    
    std::string Operation() const override;
};

class ConcreteProduct2: public Product
{
public:    
    std::string Operation() const override;
};



/**
 * ! Creators
 */ 

class Creator
{
public:
    Creator() {};
    virtual ~Creator() {};
    virtual Product* FactoryMethod() const =0;

    /**
     * ! Product creation is not the primary responsibility of the creator.
     * Usually, it contains come core business logic that 
     * relies on Product objects, returned by the factory method.
     * Subclasses can indirectly change the business logic by 
     * overriding the factory method and returning a different 
     * type of product from it.
     * 
     * FactoryMethod只是为了帮助从子类解耦合，却不是类的主要功能。
     * 就像公司可以培训员工但公司不是培训班。
     */
    std::string SomeOperation()const; 
};

/**
 * Override the factory method in order to
 * change the resulting product's type
 */ 
class ConcreteCreator1: public Creator
{
public:

    /**
     * Return the abstract product type
     */ 
    Product* FactoryMethod() const override;
};

class ConcreteCreator2: public Creator
{
public:

    Product* FactoryMethod() const override;
};
