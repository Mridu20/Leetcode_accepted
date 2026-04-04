class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int t) {
        if (t == 0) {
            int ans = 0, cnt = 0;
            for (int x : a) {
                if (x == 0)
                    cnt++;
                else {
                    ans += cnt * (cnt + 1) / 2;
                    cnt = 0;
                }
            }
            ans += cnt * (cnt + 1) / 2;
            return ans;
        }

        vector<int> one;
        one.push_back(-1);
        for (int i = 0; i < a.size(); i++)
            if (a[i] == 1)
                one.push_back(i);
        one.push_back(a.size());

        int ans = 0;

        if (one.size() - 2 < t)
            return 0;

        for (int i = 1; i + t - 1 < one.size() - 1; i++) {
            int l = one[i] - one[i - 1];
            int r = one[i + t] - one[i + t - 1];

            ans += l * r;
        }

        return ans;
    }
};