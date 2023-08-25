#include <iostream>
#include <string>
#include <memory>
#include <thread>
#include "SingletonLazyInit.hpp"
#include "SingletonEarlyInit.hpp"
#include "Singleton.hpp"
#include "SingletonThreadSafe.hpp"
using namespace singleSafe;

int main(int, char**)
{
    test();

    return 0;
}
