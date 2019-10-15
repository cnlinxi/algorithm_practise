#include <cmath>
#include <iostream>
#include <vector>

class Solution {
public:
    bool isPrime(int x) {
        if (x <= 1) return false;
        if (x == 2) return true;
        int sqrtX = std::sqrt(x);
        for (int i = 2; i < sqrtX + 1; ++i) {
            if (x % i == 0) return false;
        }
        return true;
    }

    void printResult(const std::vector<int> &paths) {
        bool isFirstElement = true;
        for (int i = 1; i < paths.size(); ++i) {
            if (isFirstElement) {
                isFirstElement = false;
            } else {
                std::cout << " ";
            }
            std::cout << paths[i];
        }
        std::cout << std::endl;
    }

    void dfs(int index, int num) {
        // 'index' is to be place instead already place, here is index == num + 1 !
        if (index == num + 1) {
            if (isPrime(paths[1] + paths[num])) {
                printResult(paths);
            }
            return;
        }
        for (int i = 2; i <= num; ++i) {
            if (mark[i]) continue;
            if (!isPrime(paths[index - 1] + i)) continue;
            paths[index] = i;
            mark[i] = true;
            dfs(index + 1, num);
            mark[i] = false;
        }
    }

    void getPrimeRing(int num) {
        if (num <= 1) return;
        while (!mark.empty()) mark.pop_back();
        while (!paths.empty()) paths.pop_back();
        mark.resize(num + 1);
        for (int i = 1; i <= num; ++i) {
            mark[i] = false;
        }
        paths.resize(num + 1);
        paths[1] = 1;
        mark[1] = true;
        dfs(2, num);
    }

private:
    std::vector<int> paths;
    std::vector<bool> mark;
};

int main() {
    int n;
    int counter = 0;
    while (std::cin >> n) {
        std::cout << "Case " << ++counter << ":" << std::endl;
        Solution().getPrimeRing(n);
    }
    return 0;
}
