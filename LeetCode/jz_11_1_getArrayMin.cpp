#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    int getMin(const std::vector<int> &vecNumbers) {
        if (vecNumbers.empty()) return -1;
        int index1 = 0, index2 = vecNumbers.size() - 1;
        int mid = index1 + ((index2 - index1) >> 1);
        while (vecNumbers[index1] >= vecNumbers[index2]) {
            if (index2 - index1 == 1) {
                return vecNumbers[index2];
            }
            mid = index1 + ((index2 - index1) >> 1);
            if (vecNumbers[index1] == vecNumbers[index2]
                && vecNumbers[index1] == vecNumbers[mid]) {
                return searchAllArray(vecNumbers, index1, index2);
            }
            if (vecNumbers[mid] >= vecNumbers[index1]) {
                index1 = mid;
            } else if (vecNumbers[mid] <= vecNumbers[index2]) {
                index2 = mid;
            }
        }
        return vecNumbers[mid];
    }

    int searchAllArray(const std::vector<int> &vecNumbers, int index1, int index2) {
        int min = INT_MAX;
        for (int i = index1; i <= index2; ++i) {
            if (min > vecNumbers[i]) {
                min = vecNumbers[i];
            }
        }
        return min;
    }
};

int main() {
    int n;
    char c;
    std::vector<int> vecNumbers;
    while ((std::cin >> n).get(c)) {
        vecNumbers.push_back(n);
        if (c == '\n') {
            std::cin.clear();
            break;
        }
    }

    int t = Solution().getMin(vecNumbers);
    std::cout << t;
    return 0;
}