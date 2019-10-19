#include <iostream>
#include <vector>

class Solution {
public:
    void reorder(std::vector<int> &vecNumbers) {
        int left = 0, right = vecNumbers.size() - 1;
        while (left < right) {
            while (left < right && (vecNumbers[left] % 2 != 0)) ++left;
            while (left < right && (vecNumbers[right] % 2 == 0)) --right;
            if (left < right) {
                int t = vecNumbers[left];
                vecNumbers[left] = vecNumbers[right];
                vecNumbers[right] = t;
            }
        }
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
    Solution().reorder(vecNumbers);
    Solution().printNumbers(vecNumbers);
    return 0;
}