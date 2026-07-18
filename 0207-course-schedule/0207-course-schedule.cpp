class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& a) {
        vector<vector<int>> adj(n);
        vector<int> inorder(n, 0);
        int m = a.size();
        for(int i=0 ;i<m; i++){
            adj[a[i][1]].push_back(a[i][0]);
            inorder[a[i][0]]++;
        }

        stack<int> st;
        for(int i=0; i<n; i++){
            if(inorder[i] == 0)st.push(i);
        }

        vector<int> ans;
        while(!st.empty()){
            int x = st.top();
            st.pop();

            for(int it: adj[x]){
                inorder[it]--;
                if(inorder[it] == 0)st.push(it);
            }
            ans.push_back(x);
        }

        if(ans.size() == n)return true;

        return false;
    }
};