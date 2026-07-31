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
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(!p && !q){
            return true;
        }

        if(p && q && p->val == q->val){
            bool right = isSameTree(p->right, q->right);
            bool left = isSameTree(p->left, q->left);

            return right && left;
        }else{
            return false;
        }
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;

        if(!subRoot) return false;

        if(isSameTree(root, subRoot)){
            return true;
        }else{
            return isSubtree(root->left, subRoot) ||
                   isSubtree(root->right, subRoot);
        }
    }
};
