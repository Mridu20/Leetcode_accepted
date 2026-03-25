class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;

        vector<bool> p(n, true);
        p[0] = false;
        p[1] = false;

        for (int i = 2; i < n; i++) {
            if (p[i]) {
                for (long long j = (long long)i * i; j < n; j += i) {
                    p[j] = false;
                }
            }
        }

        int ans = 0;
        for (bool x : p) {
            if (x) ans++;
        }

        return ans;
    }
};