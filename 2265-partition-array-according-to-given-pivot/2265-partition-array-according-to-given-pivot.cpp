class Solution {
public:
    vector<int> pivotArray(vector<int>& a, int p) {

        vector<int> m,n,o;
        for(int i=0; i<a.size(); i++){
            if(a[i]<p)m.push_back(a[i]);
            else if(a[i]==p)n.push_back(a[i]);
            else o.push_back(a[i]);
        }

        vector<int> ans;
        for(int i=0; i<m.size(); i++){
            ans.push_back(m[i]);
        }
        for(int i=0; i<n.size(); i++){
            ans.push_back(n[i]);
        }
        for(int i=0; i<o.size(); i++){
            ans.push_back(o[i]);
        }

        return ans;
    }
};