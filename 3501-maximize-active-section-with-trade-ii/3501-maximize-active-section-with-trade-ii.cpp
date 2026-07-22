class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& q) {
        int n = s.size();
        int o = ranges::count(s, '1');

        vector<int> st, en;
        for (int i = 0; i < n;) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0') j++;
                st.push_back(i);
                en.push_back(j - 1);
                i = j;
            } else {
                i++;
            }
        }

        int m = st.size();
        vector<int> v;
        for (int i = 0; i + 1 < m; i++) {
            v.push_back((en[i] - st[i] + 1) + (en[i + 1] - st[i + 1] + 1));
        }

        int sz = v.size();
        vector<vector<int>> sp{v};

        for (int k = 1; k * 2 <= sz; k *= 2) {
            auto &p = sp.back();
            vector<int> c;
            c.reserve(p.size() - k);
            for (int i = 0; i + k < (int)p.size(); i++) {
                c.push_back(max(p[i], p[i + k]));
            }
            sp.push_back(move(c));
        }

        auto rmq = [&](int l, int r) {
            int t = bit_width((unsigned)(r - l + 1)) - 1;
            return max(sp[t][l], sp[t][r - (1 << t) + 1]);
        };

        auto val = [&](int i, int l, int r) {
            return v[i] - max(0, l - st[i]) - max(0, en[i + 1] - r);
        };

        auto f = [&](int l, int r) {
            if (m < 2) return 0;

            int a = ranges::lower_bound(en, l) - en.begin();
            int b = ranges::upper_bound(st, r) - st.begin() - 2;

            if (a > b) return 0;

            return max({
                val(a, l, r),
                val(b, l, r),
                b - a >= 2 ? rmq(a + 1, b - 1) : 0
            });
        };

        vector<int> ans;
        ans.reserve(q.size());

        for (auto &x : q) {
            ans.push_back(o + f(x[0], x[1]));
        }

        return ans;
    }
};