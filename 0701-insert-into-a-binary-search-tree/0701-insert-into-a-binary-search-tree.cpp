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
    TreeNode* insertIntoBST(TreeNode* root, int t) {
        TreeNode* temp = root;
        TreeNode* prev = temp;
        
        if(!root){
            root = new TreeNode(t);
            return root;
        }
        
        while(temp){
            if(temp->val > t){
                prev = temp;
                temp = temp->left;
            }
            else if(temp->val < t){
                prev = temp;
                temp = temp->right;
            }   
        }

        if(prev->val > t)prev->left = new TreeNode(t);
        else prev->right = new TreeNode(t);

        return root;
    }
};