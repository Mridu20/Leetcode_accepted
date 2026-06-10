class Solution {
public:
    struct Node {
        long long val;
        int l, r;

        bool operator<(const Node& other) const {
            return val < other.val; // max heap
        }
    };

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> lg(n + 1);
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        int K = lg[n] + 1;

        vector<vector<int>> mx(K, vector<int>(n));
        vector<vector<int>> mn(K, vector<int>(n));

        for (int i = 0; i < n; i++) {
            mx[0][i] = mn[0][i] = nums[i];
        }

        for (int j = 1; j < K; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                mx[j][i] = max(mx[j - 1][i],
                               mx[j - 1][i + (1 << (j - 1))]);

                mn[j][i] = min(mn[j - 1][i],
                               mn[j - 1][i + (1 << (j - 1))]);
            }
        }

        auto value = [&](int l, int r) -> long long {
            int len = r - l + 1;
            int p = lg[len];

            int mxv = max(mx[p][l],
                          mx[p][r - (1 << p) + 1]);

            int mnv = min(mn[p][l],
                          mn[p][r - (1 << p) + 1]);

            return 1LL * mxv - mnv;
        };

        priority_queue<Node> pq;

        for (int l = 0; l < n; l++) {
            pq.push({value(l, n - 1), l, n - 1});
        }

        long long ans = 0;

        while (k--) {
            auto [cur, l, r] = pq.top();
            pq.pop();

            ans += cur;

            if (r > l) {
                pq.push({value(l, r - 1), l, r - 1});
            }
        }

        return ans;
    }
};