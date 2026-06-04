class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) {
        vector<vector<int>> z;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            int m = a[i].size();
            vector<int> l(m, 0);
            z.push_back(l);
        }

        z[0][0] = a[0][0];
        for (int i = 1; i < n; i++) {
            int m = z[i].size();
            for (int j = 0; j < m; j++) {
                int p1 = j; 
                int p2 = j - 1; 

                z[i][j] = a[i][j];

                if (j == 0)
                    z[i][j] += z[i - 1][p1]; 
                else if (j == m - 1)
                    z[i][j] += z[i - 1][p2]; 
                else
                    z[i][j] += min(z[i - 1][p1], z[i - 1][p2]); 
            }
        }

        int ans = *min_element(z[n - 1].begin(), z[n - 1].end());
        return ans;
    }
};