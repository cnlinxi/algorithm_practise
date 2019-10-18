#include <iostream>

class Solution {
public:
    int getNumberOf1(int n) {
        int counter = 0;
        while (n) {
            n = (n - 1) & n;
            ++counter;
        }
        return counter;
    }
};

int main() {
    int n;
    std::cin >> n;
    std::cout << Solution().getNumberOf1(n);
    return 0;
}