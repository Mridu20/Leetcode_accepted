class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size(); 

            for (int i = 0; i < levelSize; i++) {
                TreeNode* temp = q.front();
                q.pop();

                if (i == levelSize - 1)
                    ans.push_back(temp->val);

                if (temp->left)  q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }

        return ans;
    }
};