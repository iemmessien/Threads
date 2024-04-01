/* Thread.hpp */

#ifndef THREAD_HPP
#define THREAD_HPP

// Files
#include "../../include/Drone_.hpp"


static struct Thread {

    std::thread myThread;
    std::mutex threadData;

    void begin() {

    }

    int getNumberOfCores() {

        const int numCpuCores = std::thread::hardware_concurrency();

        std::cout << numCpuCores << " concurrent threads supported." << std::endl;
    }

    std::string getThreadID() {

        std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;

        return "std::this_thread::get_id()";
    }

    void pause() {
        
        // Lock the data being accessed
        std::unique_lock<std::mutex> dataLock(threadData);


        dataLock.unlock();

    }

    void lock_() {
        
        // Lock and unlock the data being accessed
        std::lock_guard<std::mutex> dataLock(threadData);

    }

    void lock() {

        // Lock the data being accessed
        threadData.lock();

        threadData.unlock();
    }

    void unpause() {

    }

    void end() {

    }

} vehicleControllerThread, myThread;  // struct Thread

#endif

void add(int &value, const int &length) {

    int val = value;


    val = 1;

    value += 2;
}

int main() {

    std::cout << "Thread!" << std::endl;

    int value = 0;

    std::thread myThread_(add, std::ref(value), std::cref(value));

    //myThread_.detach();
    myThread_.join();

    std::cout << "New value: " << value << std::endl;

    //Thread myThread;
    //myThread.getNumberOfCores();
}