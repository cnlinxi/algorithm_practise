#include <iostream>
#include <cassert>

int countRange(int numbers[], int length, int left, int right) {
    assert(numbers != nullptr && length > 0);
    int counter = 0;
    for (int i = 0; i < length; ++i) {
        if (numbers[i] >= left && numbers[i] <= right) {
            ++counter;
        }
    }
    return counter;
}

int getDuplicate(int numbers[], int length) {
    assert(numbers != nullptr && length > 0);
    int start = 0, end = length - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        int counter = countRange(numbers, length, start, mid);
        if (start == end && counter > 1) {
            return start;
        }
        if (counter > mid - start + 1) {
            // This is different from the binary search
            // because the duplicate number may be mid,
            // so 'end' should be assigned 'mid' instead of 'mid+1'
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

int main() {
    int numbers[] = {2, 3, 1, 0, 2, 5, 3};
    std::cout << getDuplicate(numbers, 7) << std::endl;
    return 0;
}
