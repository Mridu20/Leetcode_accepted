class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        vector<int> pfmx(n), sfmx(n);
        int mx = 0;

        for(int i=0; i<n; i++){
            pfmx[i] = mx;
            mx = max(mx, a[i]);
        }

        mx = a[n-1];
        for(int i=n-1; i>=0; i--){
            sfmx[i] = mx;
            mx = max(mx, a[i]);
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            int x = min(pfmx[i], sfmx[i]);
            ans += max(x-a[i], 0);
        }

        return ans;
    }
};