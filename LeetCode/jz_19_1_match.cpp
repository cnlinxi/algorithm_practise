#include <iostream>
#include <string>

class Solution {
public:
    bool matchCore(int indexStr, int indexPattern) {
        if (indexStr == str.length() && indexPattern == pattern.length()) return true;
        if (indexStr != str.length() && indexPattern == pattern.length()) return false;
        if (pattern[indexPattern + 1] == '*') {
            if (str[indexStr] == pattern[indexPattern]
                || (pattern[indexPattern] == '.' && str[indexStr] != '\0')) {
                return matchCore(indexStr + 1, indexPattern + 2)
                       || matchCore(indexStr, indexPattern + 2)
                       || matchCore(indexStr + 1, indexPattern);
            } else {
                return matchCore(indexStr, indexPattern + 2);
            }
        } else if (str[indexStr] == pattern[indexPattern]
                   || (pattern[indexPattern] == '.' && str[indexStr] != '\0')) {
            return matchCore(indexStr + 1, indexPattern + 1);
        }

        return false;
    }

    bool match(std::string str, std::string pattern) {
        this->str = str;
        this->pattern = pattern;
        return matchCore(0, 0);
    }

private:
    std::string str;
    std::string pattern;
};

int main() {
    std::string strRaw;
    std::string strPattern;
    while (std::cin >> strRaw >> strPattern) {
        std::cout << Solution().match(strRaw, strPattern) << std::endl;
    }
    return 0;
}