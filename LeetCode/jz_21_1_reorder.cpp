#include <iostream>
#include <vector>

class Solution {
public:
    void reorder(std::vector<int> &vecNumbers, bool(*func)(int)) {
        int left = 0, right = vecNumbers.size() - 1;
        while (left < right) {
            while (left < right && !func(vecNumbers[left])) ++left;
            while (left < right && func(vecNumbers[right])) --right;
            if (left < right) {
                int t = vecNumbers[left];
                vecNumbers[left] = vecNumbers[right];
                vecNumbers[right] = t;
            }
        }
    }

    static bool func(int x) {
        return (x & 1) == 0;
    }

    void printNumbers(const std::vector<int> &vecNumbers) {
        for (auto num:vecNumbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int t, n;
    std::vector<int> vecNumbers;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> t;
        vecNumbers.push_back(t);
    }
    Solution().reorder(vecNumbers, Solution().func);
    Solution().printNumbers(vecNumbers);
    return 0;
}