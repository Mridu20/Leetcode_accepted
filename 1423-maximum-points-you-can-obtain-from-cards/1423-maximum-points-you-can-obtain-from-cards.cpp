class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n = a.size();
        vector<long long> pfs(n+1);
        long long sum=0;
        pfs[0]=0;
        for(int i=0; i<n; i++){
            sum += a[i];
            pfs[i+1] = sum;
        }

        long long mx = 0;
        for(int i=0; i<=k; i++){
            long long l = pfs[i];
            l += pfs[n]-pfs[n-k+i];

            mx = max(mx, l);
        }

        return mx;
    }
};