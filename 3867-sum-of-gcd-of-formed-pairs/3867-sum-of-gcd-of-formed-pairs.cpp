class Solution {
public:
    long long gcdSum(vector<int>& a) {
        int n = a.size();
        vector<int> pfxgcd(n);

        int mx = 0;
        for(int i=0; i<n; i++){
            mx = max(mx, a[i]);
            pfxgcd[i] = gcd(mx, a[i]);
        }

        sort(pfxgcd.begin(), pfxgcd.end());
        long long sum = 0;
        for(int i =0; i<n/2; i++){
            sum += gcd(pfxgcd[i], pfxgcd[n-i-1]);
        }

        return sum;
    }
};