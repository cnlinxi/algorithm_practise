#include <iostream>

class Solution {
public:
    int Pow(double base, unsigned int exponent) {
        if (exponent == 0) return 1;
        if (exponent == 1) return base;
        int result = Pow(base, exponent >> 1);
        result *= result;
        if (exponent & 0x1 == 1) {
            result *= base;
        }
        return result;
    }
};

int main() {
    int base = 0, exponent = 0;
    std::cin >> base >> exponent;
    std::cout << Solution().Pow(base, exponent);
    return 0;
}