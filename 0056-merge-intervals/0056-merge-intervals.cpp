class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> m;
        if (a.empty()) return m;
        
        sort(a.begin(), a.end());

        int start = a[0][0];
        int end = a[0][1];

        for (int i = 1; i < a.size(); i++) {
            if (a[i][0] <= end) {
                end = max(end, a[i][1]);
            } else {
                m.push_back({start, end});
                start = a[i][0];
                end = a[i][1];
            }
        }
        m.push_back({start, end});
        return m;
    }
};
