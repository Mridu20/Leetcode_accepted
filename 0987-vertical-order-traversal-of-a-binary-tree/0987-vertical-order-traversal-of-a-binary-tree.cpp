class Solution {
    map<int, vector<pair<int,int>>> mp;
    
    void inorder(TreeNode* node, int col, int row) {
        if (!node) return;
        
        mp[col].push_back({row, node->val});
        
        inorder(node->left,  col - 1, row + 1);
        inorder(node->right, col + 1, row + 1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        inorder(root, 0, 0);
        
        vector<vector<int>> ans;
        
        for (auto& [col, nodes] : mp) {
            sort(nodes.begin(), nodes.end());
            
            vector<int> colVals;
            for (auto& [row, val] : nodes)
                colVals.push_back(val);
            
            ans.push_back(colVals);
        }
        
        return ans;
    }
};