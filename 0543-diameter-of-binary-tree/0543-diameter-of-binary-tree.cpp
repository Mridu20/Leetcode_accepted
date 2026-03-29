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
    int ans = 0;
public:
    int ht(TreeNode* node){
        if(node == NULL)return 0;

        int lh= ht(node->left);
        int rh = ht(node->right);

        ans = max(ans, lh + rh);

        return max(lh, rh)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        ht(root);

        return ans;
    }
};