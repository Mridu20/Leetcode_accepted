class Solution {
public:
    vector<vector<int>> subsets(vector<int>& a) {
        int n= a.size();
        int s = 1<<n;
        vector<vector<int>> ans;

        for (int j = 0; j < s; j++) {
            vector<int> m;

            for (int i = 0; i < n; i++) {
                if (j & (1 << i)) {
                    m.push_back(a[i]);
                }
            }

            ans.push_back(m);
        }

        return ans;
    }
};