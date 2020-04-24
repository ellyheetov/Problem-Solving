//
// Created by 박혜원 on 2020/04/22.
//


#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int longest_length = 0;

    void length(TreeNode *root, int cur_num, int len) {
        if(root->val != cur_num) return;
        len++;
        length(root->left,cur_num,len);
        length(root->right,cur_num,len);
    }

    void traverse(TreeNode *root) {
        if (root == NULL) return;
        int len =0;
        length(root, root->val, len);
        max(longest_length, len);

        traverse(root->left);
        traverse(root->right);
    }

    int longestUnivaluePath(TreeNode *root) {
        traverse(root);
        return longest_length;
    }
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
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode *root = stringToTreeNode(line);

        int ret = Solution().longestUnivaluePath(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}