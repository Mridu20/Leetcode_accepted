class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> a, b, c;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if      (s[i] == 'a') a.push_back(i);
            else if (s[i] == 'b') b.push_back(i);
            else                  c.push_back(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            auto ia = lower_bound(a.begin(), a.end(), i);
            auto ib = lower_bound(b.begin(), b.end(), i);
            auto ic = lower_bound(c.begin(), c.end(), i);

            if (ia == a.end() || ib == b.end() || ic == c.end()) break;

            int mx = max({*ia, *ib, *ic});
            ans += (n - mx);
        }
        return ans;
    }
};