
/*
 * Design Pattern : Singleton
 * Creational Design Pattern
 * Author : Ayush Agarwal [https://github.com/ayush9096]
 * 
 */


#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std;

class Singleton {

    public:

        // It should not be cloneable and assignable.
        Singleton(Singleton &other) = delete;
        void operator=(const Singleton&) = delete;
        
        static Singleton* getInstance(){
            if(!instance)
                instance = new Singleton();
            return instance;
        }

        static void freeMemory(){
            if(!instance)
                delete instance;
            instance = nullptr;
        }

    private:
        static Singleton *instance;

        Singleton(){}
        ~Singleton(){} 
};


class SingletonMultiThreaded{

    public:

        // It should not be cloneable and assignable
        SingletonMultiThreaded(SingletonMultiThreaded &other) = delete;
        void operator=(const SingletonMultiThreaded&) = delete;

        static SingletonMultiThreaded* getInstance(){
            
            std::lock_guard<std::mutex> lock(mLock);
            if(!instance)
                instance = new SingletonMultiThreaded();
            return instance;
        }

        static void freeMemory(){

            std::lock_guard<std::mutex> lock(mLock);
            if(!instance)
                delete instance;
            instance = nullptr;
        }

    
    private:
        static SingletonMultiThreaded *instance;
        static mutex mLock;
        SingletonMultiThreaded(){}
        ~SingletonMultiThreaded(){}
};

// Static methods should be defined outside the class
Singleton* Singleton::instance = nullptr;
SingletonMultiThreaded* SingletonMultiThreaded::instance = nullptr;
mutex SingletonMultiThreaded::mLock;



void ThreadOne(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    SingletonMultiThreaded *instance = SingletonMultiThreaded::getInstance();
}

void ThreadTwo(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    SingletonMultiThreaded *instance = SingletonMultiThreaded::getInstance();
}

int main(){


    // Singleton - Single-Threaded 
    Singleton *instance = Singleton::getInstance();
    Singleton::freeMemory();


    // Singleton - Multi-Threaded
    // SingletonMultiThreaded *mulThreadInstance = SingletonMultiThreaded::getInstance();
    // SingletonMultiThreaded::freeMemory();

    thread testOne(ThreadOne);
    thread testTwo(ThreadTwo);

    testOne.join();
    testTwo.join();

    return 0;
}