#include <iostream>
#include <cassert>

int getDuplicate(int numbers[], int length) {
    assert(numbers != nullptr && length > 0);

    for (int i = 0; i < length; ++i) {
        while (numbers[i] != i) {
            if (numbers[i] == numbers[numbers[i]]) {
                return numbers[i];
            }

            int t = numbers[i];
            numbers[i] = numbers[t];
            // must be numbers[t] = t; instead of numbers[numbers[i]] = t
            // because numbers[i] has been changed now
            // this step: numbers[i] != t
            numbers[t] = t;
        }
    }

    return -1;
}

int main() {
    int numbers[] = {2, 3, 1, 0, 2, 5, 3};
    std::cout << getDuplicate(numbers, 7) << std::endl;
    return 0;
}
