#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int m_nValue;
    TreeNode *m_pLeft;
    TreeNode *m_pRight;

    explicit TreeNode(int x) : m_nValue(x), m_pLeft(nullptr), m_pRight(nullptr) {}
};

class Solution {
public:
    TreeNode *reconstructTree(const vector<int> &vecPreorder, const vector<int> &vecInorder) {
        this->vecPreorder = vecPreorder;
        this->vecInorder = vecInorder;
        if (vecPreorder.empty() || vecInorder.empty()) {
            return nullptr;
        } else {
            return reconstructTreeCore(0, vecPreorder.size() - 1,
                                       0, vecInorder.size() - 1);
        }
    }

    TreeNode *reconstructTreeCore(int preStart, int preEnd, int inStart, int inEnd) {
        int root = vecPreorder[preStart];
        TreeNode *pNode = new TreeNode(root);
        if (preStart == preEnd) {
            assert(inStart == inEnd && vecPreorder[preStart] == vecInorder[inStart]);
            return pNode;
        }
        int rootIndex = inStart;
        while (vecInorder[rootIndex] != root) ++rootIndex;
        if (rootIndex != inStart) {
            pNode->m_pLeft = reconstructTreeCore(preStart + 1, preStart + rootIndex - inStart,
                                                 inStart, rootIndex - 1);
        }
        if (rootIndex != inEnd) {
            pNode->m_pRight = reconstructTreeCore(preStart + rootIndex - inStart + 1, preEnd,
                                                  rootIndex + 1, inEnd);
        }
        return pNode;
    }

private:
    vector<int> vecPreorder;
    vector<int> vecInorder;
};

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

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for (int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

TreeNode *stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true) {
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

string treeNodeToString(TreeNode *root) {
    if (root == nullptr) {
        return "[]";
    }

    string output = "";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();

        if (node == nullptr) {
            output += "null,";
            continue;
        }

        output += to_string(node->m_nValue) + ",";
        q.push(node->m_pLeft);
        q.push(node->m_pRight);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

void preOrder(TreeNode *pHead, vector<int> &paths) {
    if (pHead == nullptr) return;
    paths.push_back(pHead->m_nValue);
    preOrder(pHead->m_pLeft, paths);
    preOrder(pHead->m_pRight, paths);
}

void inOrder(TreeNode *pHead, vector<int> &paths) {
    if (pHead == nullptr) return;
    inOrder(pHead->m_pLeft, paths);
    paths.push_back(pHead->m_nValue);
    inOrder(pHead->m_pRight, paths);
}

int main() {
    string linePre, lineIn;
    while (getline(cin, linePre) && getline(cin, lineIn)) {
        vector<int> vecPre = stringToIntegerVector(linePre);
        vector<int> vecIn = stringToIntegerVector(lineIn);
        TreeNode *pHead = Solution().reconstructTree(vecPre, vecIn);
        string strTree = treeNodeToString(pHead);
        std::cout << strTree.c_str();
    }
    return 0;
}