#include "TimedSharedPtr.h"
#include <iostream>
#include <thread>

struct Node {
    int data;
    Node(int v): data(v) { std::cout << "Node constructed: " << data << std::endl; }
    ~Node() { std::cout << "Node destructed: " << data << std::endl; }
};

int main() {
    using Clock = TimedSharedPtr<Node>::Clock;
    std::cout << "Test 1: Node expiration example" << std::endl;
    TimedSharedPtr<Node> myNode(new Node(7), 100);  // expires in 100ms
    TimedSharedPtr<Node> myOtherNode = myNode;

    std::this_thread::sleep_until(Clock::now() + std::chrono::milliseconds(50));
    std::cout << "myNode.get(): " << myNode.get() << std::endl;
    std::cout << "myNode.use_count(): " << myNode.use_count() << std::endl;
    std::cout << "myOtherNode.use_count(): " << myOtherNode.use_count() << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(75));
    auto ptr_after = myNode.get();
    std::cout << "After expiration, myNode.get(): " << (ptr_after ? ptr_after : nullptr) << std::endl;

    std::cout << "\nTest 2: int example" << std::endl;
    TimedSharedPtr<int> p(new int(42));
    std::cout << "Pointer p: " << p.get() << std::endl;
    std::cout << "p.use_count(): " << p.use_count() << std::endl;

    TimedSharedPtr<int> q = p;
    std::cout << "After copy, p.use_count(): " << p.use_count() << std::endl;
    std::cout << "q.use_count(): " << q.use_count() << std::endl;

    return 0;
}
