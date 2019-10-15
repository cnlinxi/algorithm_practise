#include <iostream>

#include "leetcode.h"

class Solution {
public:
    BiTreeNode *findNextNode(BiTreeNode *pTarget) {
        if (pTarget == nullptr) return nullptr;
        if (pTarget->m_pRight != nullptr) {
            BiTreeNode *pNext = pTarget->m_pRight;
            while (pNext->m_pLeft != nullptr) {
                pNext = pNext->m_pLeft;
            }
            return pNext;
        } else {
            BiTreeNode *pNext = pTarget;
            while (pNext->m_pParent != nullptr
                   && pNext->m_pParent->m_pLeft != pNext) {
                pNext = pNext->m_pParent;
            }
            return pNext->m_pParent;
        }
    }

    BiTreeNode *findTargetNode(BiTreeNode *pHead, int target) {
        if (pHead == nullptr) return nullptr;
        if (pHead->m_nValue == target) {
            return pHead;
        }
        BiTreeNode *pTarget = findTargetNode(pHead->m_pLeft, target);
        if (pTarget != nullptr) {
            return pTarget;
        } else {
            return findTargetNode(pHead->m_pRight, target);
        }
    }
};

int main() {
    std::string line;
    return 0;
}