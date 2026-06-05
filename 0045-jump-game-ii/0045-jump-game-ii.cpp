class Solution {
public:
    int jump(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == INT_MAX) continue;

            for (int j = 1; j <= a[i] && i + j < n; j++) {
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }

        return dp[n - 1];
    }
};