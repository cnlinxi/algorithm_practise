#include <iostream>

class Solution {
public:
    long long getFibonacci(int n) {
        if (n <= 2) return 1;
        return getFibonacci(n - 1) + getFibonacci(n - 2);
    }
};

int main() {
    int n;
    while (std::cin >> n) {
        std::cout << Solution().getFibonacci(n);
    }
    return 0;
}