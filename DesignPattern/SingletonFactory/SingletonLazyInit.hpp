/**
 * 注意以下几点：
 * 1. GetInstance()返回引用还是指针？
 *      1.1 引用：注意用引用接收引用 Singleton& single = Singleton::GetInstance();
 *      1.2 指针：注意使用时不能删除获取到的对象，不能使用智能指针接收;
 * 2. 懒汉模式线程安全的问题，如何加锁？
 * 3. 如果要考虑释放资源，如何操作？
 * 4. 如果要实现多个资源，如何操作？（例如线程池）
 *      https://blog.csdn.net/qq_38200194/article/details/125956243
 * 
 * 
 */
#include <iostream>
#include <string>
#include <thread>

namespace lazy{
        
    class Singleton
    {
    private:
        Singleton(){single = nullptr; cnt = 0;};

    private:
        static Singleton *single; // declare as static
        int cnt;

    public:
        // ! 如果返回引用类型，那么必须用引用接收引用，否则还是值传递; 
        // ! 如果使用指针，接收指针的client代码注意不要释放（比如用智能指针就容易出问题）
        static Singleton* GetInstance(); 
        std::string Getcnt();
    };

    Singleton* Singleton::GetInstance() // ! Do NOT write keyword 'static' in definition
    {
        if(single == nullptr)
        {
            single = new Singleton();
        }
        return single;
    }

    std::string Singleton::Getcnt()
    {
        ++cnt;
        //return "Lazy Singleton: cnt = " + std::to_string(cnt) + "\n";
        return std::to_string(cnt);
    }

    Singleton* Singleton::single; // ! Must initialize the static member

    void fun1()
    {
        Singleton* single = Singleton::GetInstance();
        std::cout<< single << std::endl;
        for (int i =0 ;i<50; i++)
        {
            std::cout << "Thread 1 executing, cnt = " << single->Getcnt() << " \n";
            //std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    void fun2()
    {
        Singleton* single = Singleton::GetInstance();
        std::cout<< single << std::endl;
        for (int i =0 ;i<50; i++)
        {
            std::cout << "Thread 2 executing, cnt = " << single->Getcnt() << " \n";
            //std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    void test()
    {
        // ! simple test
        // Singleton* single1 = Singleton::GetInstance();
        // std::cout << single1->Getcnt();
        // std::cout << single1->Getcnt();
        // std::cout << single1 << std::endl;

        // Singleton* single2 = Singleton::GetInstance();
        // std::cout << single2->Getcnt();
        // std::cout << single2 << std::endl;

        std::thread t2(fun1);
        std::thread t3(fun2);

        t2.join();
        t3.join();
        
        Singleton* single = Singleton::GetInstance();
        std::cout<< single << std::endl;
        std::cout<< "app: cnt ="<< single->Getcnt() << std::endl;
    }

}

