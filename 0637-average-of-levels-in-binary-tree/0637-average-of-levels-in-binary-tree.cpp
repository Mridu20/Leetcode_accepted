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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        double sum =0;
        vector<double> avg;

        while(!q.empty()){
            int n = q.size();
            int c = n;
            while(n--){
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);

                sum += temp->val;
            }

            double d = sum / c;
            sum =0;
            avg.push_back(d);
        }

        return avg;
    }
};