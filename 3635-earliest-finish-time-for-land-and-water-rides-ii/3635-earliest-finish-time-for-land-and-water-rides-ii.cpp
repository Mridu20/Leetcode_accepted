class Solution {
public:
    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst,vector<int>& wd) {

        int mnl = INT_MAX;
        for (int i = 0; i < lst.size(); i++) {
            mnl =
                min(mnl, lst[i] + ld[i]);
        }

        int mnw = INT_MAX;
        for (int i = 0; i < wst.size(); i++) {
            mnw =
                min(mnw, wst[i] + wd[i]);
        }

        int ans = INT_MAX;

        for (int j = 0; j < wst.size(); j++) {
            ans = min(ans,
                      max(mnl, wst[j]) + wd[j]);
        }

        for (int i = 0; i < lst.size(); i++) {
            ans = min(ans,
                      max(mnw, lst[i]) + ld[i]);
        }

        return ans;
    }
};