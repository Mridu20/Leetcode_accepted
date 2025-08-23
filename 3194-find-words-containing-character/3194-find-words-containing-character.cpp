class Solution {
public:
    vector<int> findWordsContaining(vector<string>& w, char x) {
        vector<int> ans;
        for (int i = 0; i < w.size(); i++) {
            for (int j = 0; j < w[i].size(); j++) {
                if (w[i][j] == x) {
                    ans.push_back(i);
                    j = w[i].size();
                }
            }
        }
        return ans;
    }
};