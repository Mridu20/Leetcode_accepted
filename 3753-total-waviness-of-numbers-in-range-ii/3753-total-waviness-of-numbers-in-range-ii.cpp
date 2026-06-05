class Solution {
public:
    struct Node {
        long long cnt;
        long long sum;
    };

    string s;
    Node dp[20][3][11][11];
    bool vis[20][3][11][11];

    Node dfs(int pos, bool tight, int state, int prev2, int prev1) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][state][prev2][prev1]) {
            return dp[pos][state][prev2][prev1];
        }

        int lim = tight ? s[pos] - '0' : 9;

        long long totalCnt = 0;
        long long totalSum = 0;

        for (int d = 0; d <= lim; d++) {
            bool nt = tight && (d == lim);

            if (state == 0) {
                if (d == 0) {
                    auto child = dfs(pos + 1, nt, 0, 10, 10);
                    totalCnt += child.cnt;
                    totalSum += child.sum;
                } else {
                    auto child = dfs(pos + 1, nt, 1, 10, d);
                    totalCnt += child.cnt;
                    totalSum += child.sum;
                }
            }
            else if (state == 1) {
                auto child = dfs(pos + 1, nt, 2, prev1, d);

                totalCnt += child.cnt;
                totalSum += child.sum;
            }
            else {
                int add = 0;

                if ((prev1 > prev2 && prev1 > d) ||
                    (prev1 < prev2 && prev1 < d))
                    add = 1;

                auto child = dfs(pos + 1, nt, 2, prev1, d);

                totalCnt += child.cnt;
                totalSum += child.sum + child.cnt * add;
            }
        }

        Node res = {totalCnt, totalSum};

        if (!tight) {
            vis[pos][state][prev2][prev1] = true;
            dp[pos][state][prev2][prev1] = res;
        }

        return res;
    }

    long long solve(long long n) {
        if (n < 0) return 0;

        s = to_string(n);
        memset(vis, 0, sizeof(vis));

        return dfs(0, true, 0, 10, 10).sum;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};