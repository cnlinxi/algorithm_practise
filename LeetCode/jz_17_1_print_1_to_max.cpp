#include <iostream>
#include <vector>

class Solution {
public:
    void printVecNumbers(const std::vector<char> &vecNumber) {
        bool isFirstNum = false;
        for (int i = 0; i < vecNumber.size(); ++i) {
            if (vecNumber[i] != '0') {
                isFirstNum = true;
            }
            if (isFirstNum) {
                std::cout << vecNumber[i];
            }
        }
        if (isFirstNum) {
            std::cout << std::endl;
        }
    }

    void dfs(std::vector<char> vecCharNumber, int index) {
        if (n <= index) {
            printVecNumbers(vecCharNumber);
            return;
        }
        for (int i = 0; i < 10; ++i) {
            vecCharNumber[index] = '0' + i;
            dfs(vecCharNumber, index + 1);
        }
    }

    void print1ToMaxOfNDigits(int n) {
        if (n <= 0) return;
        this->n = n;
        std::vector<char> vecCharNumber(n);
        dfs(vecCharNumber, 0);
    }

private:
    int n;
};

int main() {
    int n = 0;
    std::cin >> n;
    Solution().print1ToMaxOfNDigits(n);
    return 0;
}