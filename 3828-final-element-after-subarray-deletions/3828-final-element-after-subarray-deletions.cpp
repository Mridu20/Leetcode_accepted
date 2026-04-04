class Solution {
public:
    int finalElement(vector<int>& a) {

        int mx = max(a[0], a[a.size()-1]);
        return mx;
    }
};