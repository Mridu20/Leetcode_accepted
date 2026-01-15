class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        vector<pair<int, int>> ze;

        for(int i=0; i<m.size(); i++){
            for(int j=0; j<m[0].size(); j++){
                if(m[i][j] == 0)ze.push_back({i, j});
            }
        }

        for(auto it: ze){
            for(int j=0; j<m[it.first].size(); j++){
                m[it.first][j] = 0;
            }
            for(int i=0; i<m.size(); i++){
                m[i][it.second] = 0;
            }
        }
    }
};