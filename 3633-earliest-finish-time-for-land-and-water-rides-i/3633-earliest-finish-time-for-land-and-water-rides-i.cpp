class Solution {
public:
    int earliestFinishTime(vector<int>& lst, vector<int>& ld,
                           vector<int>& wst, vector<int>& wd) {

        int ans = INT_MAX;

        for (int i = 0; i < lst.size(); i++) {
            for (int j = 0; j < wst.size(); j++) {

                int landFinish = lst[i] + ld[i];
                ans = min(ans,
                          max(wst[j], landFinish) + wd[j]);

                int waterFinish = wst[j] + wd[j];
                ans = min(ans,
                          max(lst[i], waterFinish) + ld[i]);
            }
        }

        return ans;
    }
};