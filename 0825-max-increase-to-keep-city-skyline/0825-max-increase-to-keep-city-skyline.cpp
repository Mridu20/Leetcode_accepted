class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& c) {
        int sum=0;
        vector<int> r, cl;
        for(int i=0; i<c.size(); i++){
            int x = *max_element(c[i].begin(), c[i].end());
            r.push_back(x);
        }

        for(int i=0; i<c[0].size(); i++){
            int y = 0;
            for(int j=0; j<c.size(); j++){
                y = max(c[j][i], y);
                
            }
            cl.push_back(y);
        }

        for(int i=0; i<c.size(); i++){
            for(int j=0; j<c[i].size(); j++){
                int d = min(r[i], cl[j]);

                sum += (d - c[i][j]);
            }
        }

        return sum;
    }
};