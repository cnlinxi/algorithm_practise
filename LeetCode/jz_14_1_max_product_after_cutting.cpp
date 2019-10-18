#include <iostream>
#include <vector>

class Solution {
public:
    int getMaxProductAfterCutting(int length) {
        if (length < 2) return 0;
        if (length == 2) return 1;
        if (length == 3) return 2;
        std::vector<int> vecProducts(length + 1);
        // For the convenience of subsequent calculations, initialize vecProducts as follows.
        // When length==2, vecProducts[1]=2.
        // If length>2, in order to maximize the product, 2 is no longer divided.
        // Other initial values ​​are similar considerations.
        vecProducts[0] = 0;
        vecProducts[1] = 1;
        vecProducts[2] = 2;
        vecProducts[3] = 3;
        for (int i = 4; i <= length; ++i) {
            int tmax = 0;
            for (int j = 1; j <= i / 2; ++j) {
                int product = vecProducts[j] * vecProducts[i - j];
                if (tmax < product) {
                    tmax = product;
                }
            }
            vecProducts[i] = tmax;
        }
        return vecProducts[length];
    }
};

int main() {
    int t;
    std::cin >> t;
    std::cout << Solution().getMaxProductAfterCutting(t);
    return 0;
}