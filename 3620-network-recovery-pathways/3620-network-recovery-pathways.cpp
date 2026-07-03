class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int,int>>> g(n);

        int lo = INT_MAX, hi = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];

            if (!online[u] || !online[v]) continue;

            g[u].push_back({v, w});
            lo = min(lo, w);
            hi = max(hi, w);
        }

        if (lo == INT_MAX) return -1;

        auto check = [&](int mid) -> bool {
            vector<long long> dist(n, LLONG_MAX / 4);
            priority_queue<
                pair<long long,int>,
                vector<pair<long long,int>>,
                greater<pair<long long,int>>
            > pq;

            dist[0] = 0;
            pq.push({0, 0});

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();

                if (d != dist[u]) continue;
                if (d > k) return false;
                if (u == n - 1) return true;

                for (auto &[v, w] : g[u]) {
                    if (w < mid) continue;

                    long long nd = d + w;
                    if (nd < dist[v]) {
                        dist[v] = nd;
                        pq.push({nd, v});
                    }
                }
            }

            return false;
        };

        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;

            if (check(mid))
                lo = mid;
            else
                hi = mid - 1;
        }

        return check(lo) ? lo : -1;
    }
};