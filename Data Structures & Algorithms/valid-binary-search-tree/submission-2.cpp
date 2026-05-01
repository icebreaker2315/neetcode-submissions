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
    bool helper(TreeNode* root, int maxi, int mini) {
        if(root == NULL) return true;

        if(root->val >= maxi || mini >= root->val){
            return false;
        }

        bool left = helper(root->left, root->val, mini);
        bool right = helper(root->right, maxi, root->val);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MAX, INT_MIN);
    }
};
