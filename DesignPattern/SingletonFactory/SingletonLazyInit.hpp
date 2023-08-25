/**
 * ע�����¼��㣺
 * 1. GetInstance()�������û���ָ�룿
 *      1.1 ���ã�ע�������ý������� Singleton& single = Singleton::GetInstance();
 *      1.2 ָ�룺ע��ʹ��ʱ����ɾ����ȡ���Ķ��󣬲���ʹ������ָ�����;
 * 2. ����ģʽ�̰߳�ȫ�����⣬��μ�����
 * 3. ���Ҫ�����ͷ���Դ����β�����
 * 4. ���Ҫʵ�ֶ����Դ����β������������̳߳أ�
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
        // ! ��������������ͣ���ô���������ý������ã�������ֵ����; 
        // ! ���ʹ��ָ�룬����ָ���client����ע�ⲻҪ�ͷţ�����������ָ������׳����⣩
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

