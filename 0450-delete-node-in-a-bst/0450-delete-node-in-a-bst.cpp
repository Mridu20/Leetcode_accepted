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
    TreeNode* findMin(TreeNode* root) {
        while(root->left)
            root = root->left;
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int k) {
        if(!root) return nullptr;

        if(k < root->val) {
            root->left = deleteNode(root->left, k);
        }
        else if(k > root->val) {
            root->right = deleteNode(root->right, k);
        }
        else {
            if(!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            if(!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            TreeNode* succ = findMin(root->right);
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }

        return root;
    }
};