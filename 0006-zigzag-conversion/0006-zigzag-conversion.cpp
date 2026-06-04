class Solution {
public:
    string convert(string s, int r) {
        if (r == 1) return s;  

        vector<vector<char>> ans(r);
        int row = 0, dir = 1;  

        for (char c : s) {
            ans[row].push_back(c);

            if (row == 0)    dir = 1;   
            if (row == r-1)  dir = -1;  

            row += dir;
        }

        string res;
        for (auto& rowVec : ans)
            for (char c : rowVec)
                res += c;

        return res;
    }
};