#include <iostream>
#include <exception>
#include <queue>

template<typename T>
class QStack {
public:
    QStack() {}

    ~QStack() {}

    void pushBack(const T &node) {
        if (queue1.empty() && queue2.empty()) {
            queue1.push(node);
        } else if (queue1.empty()) {
            queue2.push(node);
        } else {
            queue1.push(node);
        }
    }

    T popBack() {
        if (queue1.empty() && queue2.empty()) {
            throw std::exception();
        }
        if (queue1.empty()) {
            while (queue2.size() > 1) {
                queue1.push(queue2.front());
                queue2.pop();
            }
            int t = queue2.front();
            queue2.pop();
            return t;
        } else {
            while (queue1.size() > 1) {
                queue2.push(queue1.front());
                queue1.pop();
            }
            int t = queue1.front();
            queue1.pop();
            return t;
        }
    }

private:
    std::queue<T> queue1;
    std::queue<T> queue2;
};

int main() {
    QStack<int> qStack;
    for (int i = 0; i < 6; ++i) {
        qStack.pushBack(i);
    }
    for (int i = 0; i < 6; ++i) {
        std::cout << qStack.popBack() << ",";
    }
    return 0;
}