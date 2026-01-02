class Solution {
public:
    int maxCoins(vector<int>& p) {

        sort(p.begin(), p.end(), greater<int>());
        int l=0, r=p.size()-1;
        int ans=0;

        while(l < r){
            ans += p[l+1];
            l += 2;
            r--;
        }

        return ans;
    }
};