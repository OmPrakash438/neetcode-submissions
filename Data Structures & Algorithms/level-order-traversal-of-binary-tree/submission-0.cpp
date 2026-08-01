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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> order;

        queue<TreeNode*> q;
        if(root != NULL) q.push(root);
        else return order;

        while(q.size() > 0){
            int size = q.size();
            vector<int> level;

            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
            }

            order.push_back(level);
        }

        return order;
    }
};
