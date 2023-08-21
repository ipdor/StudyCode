#include "SimpleFactory.h"

void Basketball::printName()
{
    std::cout<< "Jungle get Basketball" << std::endl ; 
}

void Basketball::play()
{
    std::cout<< "Jungle play Basketball" << std::endl ; 
}

void Football::printName()
{
    std::cout<< "Jungle get Football" << std::endl ; 
}

void Football::play()
{
    std::cout<< "Jungle play Football" << std::endl ; 
}

void Volleyball::printName()
{
    std::cout<< "Jungle get Volleyball" << std::endl ; 
}

void Volleyball::play()
{
    std::cout<< "Jungle play Volleyball" << std::endl ; 
}

/**
 * It is simple to use, just pass the name of product.
 * ! However, we should modify the getSportProduct method if other products need to be added.
 * ! Once problems occur in the factory, all products will be affected.
 * ! To solve this, we need Factory method.
 */ 
std::shared_ptr<Product> Factory::getSportProduct(std::string productName)
{
    std::shared_ptr<Product> pro;
    if (productName == "Basketball")
    {
        pro = std::shared_ptr<Product>(new Basketball());
    }
    else if (productName == "Football")
    {
        pro = std::shared_ptr<Product>(new Football());
    }
    else if (productName == "Volleyball")
    {
        pro = std::shared_ptr<Product>(new Volleyball());
    }
    return pro;
}
