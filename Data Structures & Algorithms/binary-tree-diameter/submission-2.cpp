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
    int helper(TreeNode* root, int& dm) {
        if(root == NULL) return 0;

        int left = helper(root->left, dm);
        int right = helper(root->right, dm);

        if(left+right > dm) dm = left + right;

        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dm = 0;
        helper(root, dm);
        return dm;
    }
};
