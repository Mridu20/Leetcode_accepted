class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        vector <int> z;
        z.push_back(-1);
        int n = a.size();
        for(int i=0; i<n; i++){
            if(a[i]==0)z.push_back(i);
        }
        z.push_back(n);
        if(z.size()-2 <= k)return n;
        int mx = 0;
        for(int i=1; i+k<z.size(); i++){
            int l = (z[i]-z[i-1])+(z[i+k-1]-z[i])+(z[i+k]-z[i+k-1]-1);
            mx = max(mx, l);
        }

        return mx;
    }
};