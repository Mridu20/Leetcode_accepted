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
    TreeNode* build(vector<int>& a, int st, int end) {
        if (st > end) return NULL;

        TreeNode* root = new TreeNode(a[st]);

        int r = end + 1;
        for (int i = st + 1; i <= end; i++) {
            if (a[i] > a[st]) {
                r = i;
                break;
            }
        }

        root->left = build(a, st + 1, r - 1);
        root->right = build(a, r, end);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, 0, preorder.size() - 1);
    }
};