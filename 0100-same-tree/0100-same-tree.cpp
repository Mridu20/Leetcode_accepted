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
    bool traversal(TreeNode* p, TreeNode* q){
        if((p && !q)||(q && !p))return false;
        if((p && q) && (p->val != q->val))return false;
        
        if(!p && !q)return true;
        bool l = traversal(p->left, q->left);
        bool r = traversal(p->right, q->right);

        if(l && r) return true;

        return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return traversal(p,q);
    }
};