/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int a = p->val;
        int b = q->val;

        TreeNode* temp = root;
        while(temp){
            if(a<temp->val && b<temp->val)temp = temp->left;
            else if(a>temp->val && b>temp->val)temp = temp->right;
            else return temp;
        }

        return root;
    }
};