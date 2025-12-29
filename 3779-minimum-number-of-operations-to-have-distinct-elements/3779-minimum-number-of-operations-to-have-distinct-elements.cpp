class Solution {
public:
    int minOperations(vector<int>& n) {
        unordered_map<int, int> f;
        for (int x : n) f[x]++;

        int dcnt = 0;
        for (auto &it : f) {
            if (it.second >= 2) dcnt++;
        }

        int ans = 0;
        int i = 0;

        while (i < n.size() && dcnt > 0) {
            ans++;

            for (int k = 0; k < 3 && i < n.size(); k++, i++) {
                int val = n[i];
                if (f[val] == 2) dcnt--; 
                f[val]--;
            }
        }
        return ans;
    }
};