/**
 * 
 * 
 * 
 */
#include <iostream>
#include <string>

namespace early{
        
    class Singleton
    {
    private:
        Singleton(){cnt = 0;};

    private:
        int cnt;

    public:
        static Singleton& GetInstance();
        std::string Getcnt();
    };


    Singleton& Singleton::GetInstance() // ! do not write keyword 'static' in definition
    {
        static Singleton single;
        return single;
    }

    std::string Singleton::Getcnt()
    {
        ++cnt;
        return "Early Singleton: cnt = " + std::to_string(cnt) + "\n";
    }

}

