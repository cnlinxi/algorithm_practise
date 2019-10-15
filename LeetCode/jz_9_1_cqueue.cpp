#include <iostream>
#include <stack>
#include <exception>

template<typename T>
class CQueue {
public:
    CQueue(void) {}

    ~CQueue(void) {}

    void appendTail(const T &node) {
        stack1.push(node);
    }

    T deleteHead() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.empty()) {
            throw std::exception();
        }
        T t = stack2.top();
        stack2.pop();
        return t;
    }

private:
    std::stack<T> stack1;
    std::stack<T> stack2;
};

int main() {
    CQueue<int> cQueue;
    for (int i = 0; i < 6; ++i) {
        cQueue.appendTail(i);
    }
    for (int i = 0; i < 6; ++i) {
        std::cout << cQueue.deleteHead() << ",";
    }
    return 0;
}