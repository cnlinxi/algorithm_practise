#include <iostream>
#include <string>

#include "leetcode.h"

class Solution {
public:
    void deleteNode(ListNode *pHead, int deleteNodeValue) {
        if (pHead == nullptr) return;
        if (pHead->m_nValue == deleteNodeValue) {
            delete pHead;
            pHead = nullptr;
            return;
        }
        ListNode *pPrevNode = pHead;
        ListNode *pNode = pHead;
        ListNode *pNextNode = pHead;
        while (pNode != nullptr) {
            if (pNode->m_nValue == deleteNodeValue) break;
            pPrevNode = pNode;
            pNode = pNode->m_pNext;
            if (pNode != nullptr) {
                pNextNode = pNode->m_pNext;
            }
        }
        if (pNode != nullptr) {
            pPrevNode->m_pNext = pNextNode;
            delete pNode;
        }
    }

    void printList(ListNode *pHead) {
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
    int n;
    std::cin >> n >> strListNode;
    ListNode *pHead = stringToListNode(strListNode);
    Solution().deleteNode(pHead, n);
    Solution().printList(pHead);
    return 0;
}