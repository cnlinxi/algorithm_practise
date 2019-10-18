#include <iostream>
#include <cmath>

class Solution {
public:
    int getMaxProductAfterCutting(int length) {
        if (length < 2) return 0;
        if (length == 2) return 1;
        if (length == 3) return 2;
        int timesOf3 = length / 3;
        if (length - 3 * timesOf3 == 1) {
            timesOf3 -= 1;
        }
        int timesOf2 = (length - 3 * timesOf3) / 2;
        return std::pow(3, timesOf3) * std::pow(2, timesOf2);
    }
};

int main() {
    int n;
    std::cin >> n;
    std::cout << Solution().getMaxProductAfterCutting(n);
    return 0;
}