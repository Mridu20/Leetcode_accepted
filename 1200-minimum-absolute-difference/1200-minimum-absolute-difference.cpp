class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& a) {
        int mn=1e7;
        sort(a.begin(), a.end());

        for(int i=0; i<a.size()-1; i++){
            mn = min(mn, a[i+1]-a[i]);
        }

        vector<vector<int>> ans;
        for(int i=0; i<a.size()-1; i++){
            if(a[i+1]-a[i] == mn){
                vector<int> m = {a[i], a[i+1]};
                ans.push_back(m);
            }
        }

        return ans;
    }
};