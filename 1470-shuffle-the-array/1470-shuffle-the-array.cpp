class Solution {
public:
    vector<int> shuffle(vector<int>& a, int n) {
        vector<int> ans;
        for(int i=0; i<a.size()/2; i++){
            ans.push_back(a[i]);
            ans.push_back(a[n + i]);
        }

        return ans;
    }
};