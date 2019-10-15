#include <iostream>

class Solution {
public:
    long long getFibonacci(int n) {
        if (n <= 2) return 1;
        int fibMinusTwo = 1;
        int fibMinusOne = 1;
        int fibN = fibMinusOne;
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