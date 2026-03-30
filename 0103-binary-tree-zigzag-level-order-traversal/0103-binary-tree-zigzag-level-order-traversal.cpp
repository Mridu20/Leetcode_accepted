class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        int lvl = 0;

        while (!q.empty()) {
            int sz = q.size();   
            vector<int> b;

            for (int i = 0; i < sz; i++) {
                TreeNode* temp = q.front(); 
                q.pop();

                b.push_back(temp->val);

                if (temp->left)  q.push(temp->left);
                if (temp->right) q.push(temp->right); 
            }

            if (lvl % 2 == 1)
                reverse(b.begin(), b.end());

            ans.push_back(b);
            lvl++;
        }

        return ans;
    }
};