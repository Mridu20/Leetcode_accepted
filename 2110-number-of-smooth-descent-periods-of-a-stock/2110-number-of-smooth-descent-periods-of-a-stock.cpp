class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        long long ans = 1;

        long long cnt = 1;
        for(int i=1; i<p.size(); i++){
            if(p[i] == p[i-1]-1){
                cnt++;
                ans += cnt;
            }
            else{
                cnt = 1;
                ans++;
            }
        }

        return ans;
    }
};