class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){ return nums[a] < nums[b]; });

        vector<int> val(n), pos(n); 
        for (int i = 0; i < n; i++) {
            val[i] = nums[idx[i]];
            pos[idx[i]] = i;
        }

        vector<int> far(n);
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (j < i) j = i;
            while (j + 1 < n && val[j + 1] - val[i] <= maxDiff) j++;
            far[i] = j;
        }

        vector<int> comp(n);
        comp[0] = 0;
        for (int i = 1; i < n; i++)
            comp[i] = (val[i] - val[i - 1] <= maxDiff) ? comp[i - 1] : comp[i - 1] + 1;

        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        LOG++;
        vector<vector<int>> up(LOG, vector<int>(n));
        up[0] = far;
        for (int k = 1; k < LOG; k++)
            for (int i = 0; i < n; i++)
                up[k][i] = up[k - 1][up[k - 1][i]];

        auto minSteps = [&](int lo, int hi) -> int {
            if (lo >= hi) return 0;
            int cur = lo, steps = 0;
            for (int k = LOG - 1; k >= 0; k--) {
                if (cur < hi && up[k][cur] < hi) {
                    cur = up[k][cur];
                    steps += (1 << k);
                }
            }
            if (cur < hi) steps++; 
            return steps;
        };

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            int pu = pos[u], pv = pos[v];
            if (comp[pu] != comp[pv]) {
                ans.push_back(-1);
                continue;
            }
            int lo = min(pu, pv), hi = max(pu, pv);
            ans.push_back(minSteps(lo, hi));
        }
        return ans;
    }
};