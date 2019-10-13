//
// Created by linxi on 2019/10/13.
//

#include "leetcode.h"

void trimLeftTrailingSpaces(std::string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(std::string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}


int stringToInteger(const std::string &input) {
    return stoi(input);
}

std::vector<int> stringToIntegerVector(std::string input) {
    std::vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    std::stringstream ss;
    ss.str(input);
    std::string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

std::string integerVectorToString(std::vector<int> list, int length) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    std::string result;
    for (int index = 0; index < length; index++) {
        int number = list[index];
        result += std::to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

ListNode *stringToListNode(std::string input) {
    // Generate list from the input
    std::vector<int> list = stringToIntegerVector(input);

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

std::string listNodeToString(ListNode *node) {
    if (node == nullptr) {
        return "[]";
    }

    std::string result;
    while (node) {
        result += std::to_string(node->m_nValue) + ", ";
        node = node->m_pNext;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

TreeNode *stringToTreeNode(std::string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    std::string item;
    std::stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    std::queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->m_pLeft = new TreeNode(leftNumber);
            nodeQueue.push(node->m_pLeft);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->m_pRight = new TreeNode(rightNumber);
            nodeQueue.push(node->m_pRight);
        }
    }
    return root;
}

std::string treeNodeToString(TreeNode *root) {
    if (root == nullptr) {
        return "[]";
    }

    std::string output = "";
    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();

        if (node == nullptr) {
            output += "null,";
            continue;
        }

        output += std::to_string(node->m_nValue) + ",";
        q.push(node->m_pLeft);
        q.push(node->m_pRight);
    }
    return "[" + output.substr(0, output.length() - 1) + "]";
}

std::string boolToString(bool input) {
    return input ? "True" : "False";
}

