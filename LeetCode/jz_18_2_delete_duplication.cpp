#include <iostream>
#include <string>

#include "leetcode.h"

class Solution {
public:
    ListNode *deleteDuplication(ListNode *pHead) {
        if (pHead == nullptr) return nullptr;
        ListNode *pNode = pHead;
        while (pNode->m_pNext != nullptr) {
            while (pNode->m_nValue == pNode->m_pNext->m_nValue) {
                ListNode *pToBeDelete = pNode->m_pNext;
                pNode->m_pNext = pToBeDelete->m_pNext;
                delete pToBeDelete;
            }
            pNode = pNode->m_pNext;
        }
        return pHead;
    }

    void printListNode(ListNode *pHead) {
        ListNode *pNode = pHead;
        while (pNode != nullptr) {
            std::cout << pNode->m_nValue << " ";
            pNode = pNode->m_pNext;
        }
        std::cout << std::endl;
    }
};

int main() {
    std::string strListNode;
    std::cin >> strListNode;
    ListNode *pHead = stringToListNode(strListNode);
    Solution().deleteDuplication(pHead);
    Solution().printListNode(pHead);
    return 0;
}