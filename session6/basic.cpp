#include <thread>
#include <mutex>
#include <vector>
#include <iostream>

int main(){
    std::vector<int> v;
    std::mutex m;

    std::thread t1([&](){
        for(int i = 0; i < 50000; ++i){
            std::lock_guard<std::mutex> l(m);
            v.push_back(i);
        }
    });
    std::thread t2([&](){
        for(int i = 0; i < 50000; ++i){
            std::lock_guard<std::mutex> l(m);
            v.push_back(i);
        }
    });
    t1.join();
    t2.join();

    for(int i : v){
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}

