//
// Created by 박혜원 on 2020/06/10.
//

#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if(root == NULL) return result;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            vector<int> answer;
            int size = que.size();
            answer.resize(size);
            TreeNode *cur = que.front();

            for(int i =0; i< size; i++) {
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
        }

        return result;
    }
};