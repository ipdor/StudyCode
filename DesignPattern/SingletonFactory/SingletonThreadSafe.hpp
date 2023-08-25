/**
 * 
 * Thread-safe Singleton
 * https://refactoring.guru/design-patterns/singleton/cpp/example#example-1
 */
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>

namespace singleSafe
{
    class Singleton
    {
    private:
        static Singleton* singleton_;
        static std::mutex mutex_;

    protected:
        Singleton(const std::string value):value_(value){};
        ~Singleton(){};
        std::string value_;
        
    public:
        Singleton (Singleton &other) = delete;

        void operator=(const Singleton &) = delete;

        static Singleton* GetInstance(const std::string& value);

        void SomeBusinessLogic(){};
        
        std::string value() const{return value_;}
    };

    Singleton* Singleton::singleton_ = nullptr;
    std::mutex Singleton::mutex_;
    
    /**
     * The first time we call GetInstance we will lock the storage location
     *      and then we make sure again that the variable is null and then we
     *      set the value. RU:
     */
    Singleton* Singleton::GetInstance(const std::string &value)
    {
        /**
         * ! lock when lock_guard is created, unlock when destructed
         * When a lock_guard object is created, it attempts to take ownership 
         * of the mutex it is given. When control leaves the scope in which 
         * the lock_guard object was created, the lock_guard is destructed 
         * and the mutex is released. 
         */ 
        std::lock_guard<std::mutex> lock(mutex_);
        if(singleton_ == nullptr)
        {
            singleton_ = new Singleton(value);
        }
        return singleton_;
    }

    void ThreadFoo()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        Singleton* singleton = Singleton::GetInstance("FOO");
        std::cout << singleton->value() <<"\n"; 
    }

    void ThreadBar()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        Singleton* singleton = Singleton::GetInstance("BAR");
        std::cout << singleton->value() <<"\n"; 
    }

    void test()
    {
        std::cout <<"If you see the same value, then singleton was reused (yay!\n" <<
                    "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
                    "RESULT:\n";   
        std::thread t1(ThreadFoo);
        std::thread t2(ThreadBar);
        t1.join();
        t2.join();
    }
}    