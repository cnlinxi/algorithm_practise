//
// Created by linxi on 2019/10/13.
//

#ifndef JZ_8_1_TREE_GET_NEXT_NODE_LEETCODE_H
#define JZ_8_1_TREE_GET_NEXT_NODE_LEETCODE_H

#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>

struct ListNode {
    int m_nValue;
    ListNode *m_pNext;

    explicit ListNode(int x) : m_nValue(x), m_pNext(nullptr) {}
};

struct TreeNode {
    int m_nValue;
    TreeNode *m_pLeft;
    TreeNode *m_pRight;

    explicit TreeNode(int x) : m_nValue(x), m_pLeft(nullptr), m_pRight(nullptr) {}
};

struct BiTreeNode {
    int m_nValue;
    BiTreeNode *m_pLeft;
    BiTreeNode *m_pRight;
    BiTreeNode *m_pParent;

    explicit BiTreeNode(int x) : m_nValue(x), m_pLeft(nullptr), m_pRight(nullptr), m_pParent(nullptr) {};
};

void trimLeftTrailingSpaces(std::string &input);

void trimRightTrailingSpaces(std::string &input);

int stringToInteger(const std::string &input);

std::vector<int> stringToIntegerVector(std::string input);

std::string integerVectorToString(std::vector<int> list, int length = -1);

ListNode *stringToListNode(std::string input);

std::string listNodeToString(ListNode *node);

TreeNode *stringToTreeNode(std::string input);

std::string treeNodeToString(TreeNode *root);

std::string boolToString(bool input);

#endif //JZ_8_1_TREE_GET_NEXT_NODE_LEETCODE_H
