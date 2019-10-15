#include <iostream>
#include <cassert>

class Solution {
public:
    long long getFibonacci(int n) {
        assert(n >= 1);
        if (n == 1) return 1;
        if (n == 2) return 2;
        int fibMinusTwo = 1;
        int fibMinusOne = 2;
        int fibN = fibMinusTwo;
        for (int i = 3; i <= n; ++i) {
            fibN = fibMinusTwo + fibMinusOne;
            fibMinusTwo = fibMinusOne;
            fibMinusOne = fibN;
        }
        return fibN;
    }
};

int main() {
    int n;
    while (std::cin >> n) {
        std::cout << Solution().getFibonacci(n);
    }
    return 0;
}