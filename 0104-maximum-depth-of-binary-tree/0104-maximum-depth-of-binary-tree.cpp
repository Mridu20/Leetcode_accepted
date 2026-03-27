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
    int maxDepth(TreeNode* root) {
        vector<vector<int>> ans;
        int cnt=0;
        if(root == NULL)return cnt;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            // vector<int> a;
            int s = q.size();
            for(int i=0; i<s; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                // a.push_back(node->val);
            }
            cnt++;
        }
        return cnt;
    }
};