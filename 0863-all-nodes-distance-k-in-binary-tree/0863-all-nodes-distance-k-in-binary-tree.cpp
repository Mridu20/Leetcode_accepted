/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        queue<TreeNode*> bfs;
        bfs.push(root);

        while(!bfs.empty()){
            int s = bfs.size();
            for(int i=0;i<s;i++){
                TreeNode* temp = bfs.front();
                bfs.pop();

                if(temp->left){
                    parent[temp->left] = temp;
                    bfs.push(temp->left);
                }
                if(temp->right){
                    parent[temp->right] = temp;
                    bfs.push(temp->right);
                }
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;

        markparent(root, parent);
        unordered_map<TreeNode*, bool> visited;

        visited[target] = true;
        queue<TreeNode*> q;
        q.push(target);

        int dis = 0;
        while(!q.empty()){
            int n = q.size();
            if(dis++ == k)break;

            for(int i=0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                visited[temp] = true;

                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                }
                if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                }
                if(parent.count(temp) && !visited[parent[temp]]){
                    q.push(parent[temp]);
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(temp->val);
        }

        return ans;
    }
};