#include <iostream>

void replaceBlank(char *str, int maxSize) {
    char *pStr = str;
    int length = 0, counterBlank = 0;
    while (*pStr != '\0') {
        if (*pStr == ' ') {
            ++counterBlank;
        }
        ++length;
        ++pStr;
    }
    int newLength = length + 2 * counterBlank;
    if (newLength >= maxSize) return;
    char *pNewStr = str + newLength;
    *pNewStr = '\0';
    --pStr;
    --pNewStr;
    for (int i = 0; i < length; ++i) {
        if (*pStr == ' ') {
            *pNewStr = '0';
            --pNewStr;
            *pNewStr = '2';
            --pNewStr;
            *pNewStr = '%';
        } else {
            *pNewStr = *pStr;
        }
        --pStr;
        --pNewStr;
    }
}

int main() {
    const int kMaxSize = 101;
    char *str = new char[kMaxSize];
    std::cin.getline(str, kMaxSize);
    replaceBlank(str, kMaxSize);
    std::cout << str;
    return 0;
}
