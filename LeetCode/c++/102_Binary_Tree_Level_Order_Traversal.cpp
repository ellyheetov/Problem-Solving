//
// Created by 박혜원 on 2020/06/10.
//

#include <iostream>
#include <string>
#include <sstream>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if(root == NULL) return result;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){

            vector<int> answer;
            int size = que.size();

            for(int i =0;i< size;i++){
                TreeNode *cur_ptr = que.front();
                if(cur_ptr->left) que.push(cur_ptr->left);
                if(cur_ptr->right) que.push(cur_ptr->right);
                answer.push_back(cur_ptr->val);
                que.pop();
            }
            result.push_back(answer);
        }
        return result;
    }
};