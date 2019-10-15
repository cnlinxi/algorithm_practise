#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct ListNode {
    int m_nValue;
    ListNode *m_pNext;

    explicit ListNode(int x) : m_nValue(x), m_pNext(nullptr) {}
};

int stringToInteger(string input) {
    return stoi(input);
}

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode *stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode *dummyRoot = new ListNode(0);
    ListNode *ptr = dummyRoot;
    for (int item : list) {
        ptr->m_pNext = new ListNode(item);
        ptr = ptr->m_pNext;
    }
    ptr = dummyRoot->m_pNext;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode *node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->m_nValue) + ", ";
        node = node->m_pNext;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

class Solution {
public:
    void printListReversingly(ListNode *pHead) {
        if (pHead == nullptr) return;
        printListReversingly(pHead->m_pNext);
        if (!isFirstElement) {
            cout << ",";
        } else {
            isFirstElement = false;
        }
        cout << pHead->m_nValue;
    }

private:
    bool isFirstElement = true;
};

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode *listHead = stringToListNode(line);

        Solution().printListReversingly(listHead);
    }
    return 0;
}