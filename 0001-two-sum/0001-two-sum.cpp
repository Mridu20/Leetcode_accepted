class Solution {
public:
    vector<int> twoSum(vector<int> &n, int t) {
        unordered_map<int, int> mp;
        for (int i = 0; i < n.size(); i++) {
            mp[n[i]] = i;
        }
        for (int i = 0; i < n.size(); i++) {
            int d = t - n[i];
            if (mp.find(d) != mp.end() && mp[d] != i) {
                return {i, mp[d]};
            }
        }
        return {};
    }
};