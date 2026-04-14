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
    int mx = INT_MIN;
public:
    int mps(TreeNode* node) {
        if (node == NULL) return 0;

        int ls = max(0, mps(node->left));
        int rs = max(0, mps(node->right));

        mx = max(mx, ls + rs + node->val);

        return node->val + max(ls, rs);
    }
    
    int maxPathSum(TreeNode* root) {
        mps(root);
        return mx;
    }
};