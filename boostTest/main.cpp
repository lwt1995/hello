#include <iostream>
#include <thread>
#include <boost/asio.hpp>

/* 互斥锁 */
std::mutex mutex_iostream;

void my_task( void )
{
    std::lock_guard<std::mutex> lg(mutex_iostream);
    std::cout.flush();
    std::cout << "This is my task." << std::endl;
    std::cout.flush();
}

int main( int argc, const char **argv )
{
    /* 定义一个4线程的线程池 */
    boost::asio::thread_pool tp( 4 );

    /* 将函数投放到线程池 */
    for( int i=0; i<5; ++i ) {
        boost::asio::post( tp, my_task );
    }

    /* 将语句块投放到线程池 */
    for( int i=0; i<5; ++i ) {
        boost::asio::post(
            tp,
            [](){
                std::lock_guard<std::mutex> lg( mutex_iostream );
                std::cout.flush();
                std::cout << "This is lambda task." << std::endl;
                std::cout.flush();
            });
    }

    /* 退出所有线程 */
    tp.join();

    system("PAUSE");

    return 0;
}
