class Solution {
public:
    int longestMonotonicSubarray(vector<int>& a) {
        int mx=0;
        int l =0, r=0;
        int n = a.size();

        for(int i =1; i<n; i++){
            if(a[i] > a[i-1])r++;
            else{
                mx = max(r-l+1, mx);
                l= i;
                r=l;
            }
        }
        mx = max(r-l+1, mx);

        l=0;
        r=0;
        for(int i =1; i<n; i++){
            if(a[i] < a[i-1])r++;
            else{
                mx = max(r-l+1, mx);
                l= i;
                r=l;
            }
        }
        mx = max(r-l+1, mx);

        return mx;
    }
};