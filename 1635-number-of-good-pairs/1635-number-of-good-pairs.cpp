class Solution {
public:
    int numIdenticalPairs(vector<int>& n) {
        int cnt = 0;
        map <int, int> mp;
        for(int i=0; i<n.size(); i++){
            mp[n[i]]++;
        }
        for(auto it:mp){
            int m = (it.second *(it.second -1))/2;
            cnt += m;
        }
        return cnt;
    }
};