/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int count = 0;

public:
    void helper(TreeNode* root, int currMax){
        if(root == NULL) return;

        if(root->val == currMax) count++;

        if(root->left) helper(root->left, max(currMax, root->left->val));
        if(root->right) helper(root->right, max(currMax, root->right->val));
    }

    int goodNodes(TreeNode* root) {
        if(root == NULL) return 0;

        helper(root, root->val);

        return count;
    }
};
