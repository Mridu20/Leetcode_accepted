class Solution {
public:
    int maxProduct(vector<int>& a) {
        long long maxp = a[0];
        long long minp = a[0];
        long long ans  = a[0];

        for (int i = 1; i < a.size(); i++) {
            if (a[i] < 0) swap(maxp, minp);

            maxp = max((long long)a[i], maxp * a[i]);
            minp = min((long long)a[i], minp * a[i]);

            ans = max(ans, maxp);
        }

        return ans;
    }
};
