class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        int currl = v[0][0];
        int currr = v[0][1];

        int n = v.size();
        int ans = n;

        for(int i =1; i<n; i++){
            if(v[i][0] >= currl && v[i][1] <= currr)ans--;
            else if(v[i][0] == currl && v[i][1] > currr){
                ans--;
                currr = v[i][1];
            }
            else {
                currl = v[i][0];
                currr = v[i][1];
            }
        }

        return ans;
    }
};