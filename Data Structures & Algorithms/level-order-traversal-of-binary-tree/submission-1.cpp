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
        if(root == NULL) return {};

        vector<vector<int>> ans;
        vector<int> temp;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            for(int i=0; i<n; i++) {
                TreeNode* a = q.front();
                q.pop();

                temp.push_back(a->val);

                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
            }
            //here one lvl completed
            ans.push_back({temp});
            temp.clear();
        }
        return ans;
    }
};
