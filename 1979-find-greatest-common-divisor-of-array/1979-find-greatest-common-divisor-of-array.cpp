class Solution {
public:
    int findGCD(vector<int>& a) {
        int mn = *min_element(a.begin(), a.end());
        int mx = *max_element(a.begin(), a.end());

        return gcd(mn, mx);
    }
};