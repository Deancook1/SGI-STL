#include <iostream>
#include <thread>
#include <chrono>

bool flag = false;  // 非 volatile，非 atomic

void thread1() {
    while (!flag) { }  // 高优化下可能被缓存，导致死循环
    std::cout << "Flag is set! (thread1 结束)" << std::endl;
}

void thread2() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    flag = true;
    std::cout << "Flag 已修改为 true (thread2 结束)" << std::endl;
}

int main() {
    std::thread t1(thread1);
    std::thread t2(thread2);
    t1.join();
    t2.join();
    return 0;
}