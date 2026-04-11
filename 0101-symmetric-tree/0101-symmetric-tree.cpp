class Solution {
    bool isMirror(TreeNode* l, TreeNode* r) {
        if (!l && !r) return true;          
        if (!l || !r) return false;          
        if (l->val != r->val) return false;  

        return isMirror(l->left, r->right) &&
               isMirror(l->right, r->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
};