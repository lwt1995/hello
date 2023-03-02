#include <iostream>
#include <thread>
#include<mutex>
//#include <boost/asio.hpp>
#include "threadpool.hpp"
/* 互斥锁 */
std::mutex mutex_iostream;

void my_task(void) {
    std::lock_guard<std::mutex> lg(mutex_iostream);
//    std::unique_lock<std::mutex> lu(mutex_iostream);
    std::cout.flush();
    std::cout << "This is my task." << std::endl;
    std::cout.flush();
//    lu.unlock();
}

int main(int argc, const char **argv) {
    printf("%d\n", argc);
    printf("%s\n", argv[0]);
    /* 定义一个4线程的线程池 */
//    boost::asio::thread_pool tp(4);
    ThreadPool tp(4);
    tp.init();
    /* 将函数投放到线程池 */
    for (int i = 0; i < 5; ++i) {
//        boost::asio::post(tp, my_task);
        tp.submit(my_task).get();
    }

    /* 将语句块投放到线程池 */
    for (int i = 0; i < 5; ++i) {
//        boost::asio::post(
//                tp,
//                []() {
//                    std::lock_guard<std::mutex> lg(mutex_iostream);
//                    std::cout.flush();
//                    std::cout << "This is lambda task." << std::endl;
//                    std::cout.flush();
//                });
        tp.submit(
                []() {
                    std::lock_guard<std::mutex> lg(mutex_iostream);
                    std::cout.flush();
                    std::cout << "This is lambda task." << std::endl;
                    std::cout.flush();
                }).get();

    }

    /* 退出所有线程 */
//    tp.join();
      tp.shutdown();

    //system("PAUSE");

    return 0;
}
