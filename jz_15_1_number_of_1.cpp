#include <iostream>

class Solution {
public:
    int getNumberOf1(int n) {
        int counter = 0;
        unsigned int flag = 1;
        while (flag) {
            if (n & flag) {
                ++counter;
            }
            flag = flag << 1;
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