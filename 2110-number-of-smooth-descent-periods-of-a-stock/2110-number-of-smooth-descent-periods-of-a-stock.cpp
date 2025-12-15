class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        long long ans = p.size();

        long long cnt = 1;
        for(int i=1; i<p.size(); i++){
            if(p[i] == p[i-1]-1){
                cnt++;
            }
            else{
                ans -= cnt;
                long long incr = ((cnt*(cnt+1))/2);
                ans += incr;
                cnt = 1;
            }
        }

        if(cnt != 1){
            ans -= cnt;
            long long incr = ((cnt*(cnt+1))/2);
            ans += incr;
        }

        return ans;
    }
};