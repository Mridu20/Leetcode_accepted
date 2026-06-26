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
    TreeNode* build(vector<int>& postorder, int poststart, int postend, vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMap) {
        
        if (poststart > postend || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[postend]);

        int inRoot = inMap[root->val];

        int numsLeft = inRoot - inStart;

        root->left = build(postorder, poststart, poststart + numsLeft-1,
                           inorder, inStart, inRoot - 1, inMap);
        root->right = build(postorder, poststart + numsLeft, postend-1,
                            inorder, inRoot + 1, inEnd, inMap);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        map<int,int> inMap;
        for(int i = 0; i < inorder.size(); i++)inMap[inorder[i]] = i;

        return build(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
    }

};