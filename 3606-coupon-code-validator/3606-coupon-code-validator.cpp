class Solution {
public:
    vector<string> validateCoupons(vector<string>& c, vector<string>& bl,
                                   vector<bool>& t) {
        vector<string> ans;
        int n = c.size();

        for (int i = 0; i < n; i++) {
            bool h = true;
            for (char c : c[i]) {
                if (!(isalnum(c) || c == '_')) {
                    h = false;
                }
            }

            if(!h){
                c[i] ="";
            }
        }
        for (int i = 0; i < n; i++) {
            if (bl[i] == "electronics" && t[i] && c[i].size() > 0) {
                ans.push_back(c[i]);
            }
        }
        sort(ans.begin(), ans.end());
        int a = ans.size();
        for (int i = 0; i < n; i++) {
            if (bl[i] == "grocery" && t[i] && c[i].size() > 0) {
                ans.push_back(c[i]);
            }
        }
        sort(ans.begin()+a, ans.end());
        a = ans.size();
        for (int i = 0; i < n; i++) {
            if (bl[i] == "pharmacy" && t[i] && c[i].size() > 0) {
                ans.push_back(c[i]);
            }
        }
        sort(ans.begin()+a, ans.end());
        a = ans.size();
        for (int i = 0; i < n; i++) {
            if (bl[i] == "restaurant" && t[i] && c[i].size() > 0) {
                ans.push_back(c[i]);
            }
        }
        sort(ans.begin()+a, ans.end());
        // a = ans.size();

        return ans;
    }
};