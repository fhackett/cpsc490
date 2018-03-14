#define BOOST_THREAD_PROVIDES_FUTURE
#define BOOST_THREAD_PROVIDES_FUTURE_CONTINUATION
#include <boost/thread.hpp>
#include <boost/thread/future.hpp>
#include <iostream>

boost::future<int> later_int(int v){
    return boost::async([=](){
        return v;
    });
}

int main(){
    int x = later_int(42)
        .then([](boost::future<int> f) -> float{
            return f.get()*2;
        })
        .then([](boost::future<float> f) -> int{
            return static_cast<int>(f.get()/2);
        })
        .get();
    std::cout << x << "\n";
    return 0;
}

