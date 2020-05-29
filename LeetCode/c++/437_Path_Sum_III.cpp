//
// Created by 박혜원 on 2020/04/22.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int answer = 0;

    void traverse(TreeNode *root, int sum) {
        if (root == NULL) return;
        part_sum(root, sum);
        traverse(root->left, sum);
        traverse(root->right, sum);
    }

    void part_sum(TreeNode *root, int remaining_sum) {
        if (root == NULL) return;
        if (root->val == remaining_sum) {
            answer++;
        }
        part_sum(root->left, remaining_sum - root->val);
        part_sum(root->right, remaining_sum - root->val);
    }

    int pathSum(TreeNode *root, int sum) {
        traverse(root, sum);
        return answer;
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode *root = stringToTreeNode(line);
        getline(cin, line);
        int sum = stringToInteger(line);

        int ret = Solution().pathSum(root, sum);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}