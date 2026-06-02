class Solution {
public:
    bool ancestors(TreeNode* root, vector<TreeNode*>& path, TreeNode* target) {
        if (!root) return false;

        if (root == target) {
            path.push_back(root);
            return true;
        }

        if (ancestors(root->left, path, target) ||
            ancestors(root->right, path, target)) {
            path.push_back(root);
            return true;
        }

        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root,
                                   TreeNode* p,
                                   TreeNode* q) {

        vector<TreeNode*> pathP, pathQ;

        ancestors(root, pathP, p);
        ancestors(root, pathQ, q);

        reverse(pathP.begin(), pathP.end());
        reverse(pathQ.begin(), pathQ.end());

        TreeNode* ans = nullptr;

        int n = min(pathP.size(), pathQ.size());

        for (int i = 0; i < n; i++) {
            if (pathP[i] == pathQ[i])
                ans = pathP[i];
            else
                break;
        }

        return ans;
    }
};