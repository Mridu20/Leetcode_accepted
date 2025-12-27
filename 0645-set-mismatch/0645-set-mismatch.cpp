class Solution {
public:
    vector<int> findErrorNums(vector<int>& n) {
        vector<int> j(n.size());
        for(int i=0; i<n.size(); i++){
            j[n[i]-1]++;
        }

        vector<int> ans(2);
        ans[0] = max_element(j.begin(), j.end()) - j.begin() + 1;
        ans[1]= min_element(j.begin(), j.end()) - j.begin() + 1;

        return ans;
    }
};