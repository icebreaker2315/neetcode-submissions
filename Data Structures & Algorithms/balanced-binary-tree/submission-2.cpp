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
    int bf = 0;

    int helper(TreeNode* root) {
        if(root == NULL) return 0;
        
        int left = helper(root -> left);
        int right = helper(root ->right);

        bf = max(bf, abs(left - right));

        return max(left, right) + 1;
    } 

    bool isBalanced(TreeNode* root) {
        helper(root);

        if(bf >= 2){
            return false;
        }

        return true;
    }
};
