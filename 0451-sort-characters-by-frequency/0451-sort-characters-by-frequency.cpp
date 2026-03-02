class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;

        for(char c : s)
            freq[c]++;

        vector<pair<char,int>> mp(freq.begin(), freq.end());

        sort(mp.begin(), mp.end(),
            [](auto &a, auto &b){
                return a.second > b.second;
            });

        string ans;
        for(auto &p : mp)
            ans.append(p.second, p.first);

        return ans;
    }
};